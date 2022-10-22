#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e5+10;
int a[mn];
int o[32];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=0;i<n;i++)for(int j=0;j<32;j++)if((a[i]>>j)&1)o[j]++;
    int bes=0,besv=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<32;j++)if((a[i]>>j)&1)o[j]--;
        int num=0;
        for(int j=0;j<32;j++)if(o[j]==0&&((a[i]>>j)&1))num+=1<<j;
        if(num>besv)bes=i,besv=num;
        for(int j=0;j<32;j++)if((a[i]>>j)&1)o[j]++;
    }
    printf("%d",a[bes]);
    for(int i=0;i<n;i++)if(i!=bes)printf(" %d",a[i]);
}