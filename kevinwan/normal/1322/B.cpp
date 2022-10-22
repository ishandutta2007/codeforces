#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int inf=0x3f3f3f3f;
const int mn=1e6+10;
char c[1<<25];
int a[mn];
char ans[25];
char num[25];
int main(){
    //printf("3 %d %d %d",1<<22,1<<23,3<<22);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        for(int j=0;j<25;j++){
            c[(1<<j)+a[i]%(1<<j)]++;
            if((a[i]>>j)&1)num[j]++,ans[j+1]--;
        }
    }
    for(int i=0;i<25;i++){
        for(int j=(1<<i+1)-2;j>=1<<i;j--)c[j]+=c[j+1];
    }
    for(int i=0;i<25;i++)ans[i]+=2*num[i]*(n-num[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<25;j++){
            if(a[i]%(1<<j)==0)continue;
            ans[j]+=c[(1<<j)+(1<<j)-(a[i]%(1<<j))];
        }
    }
    int ret=0;
    for(int i=0;i<25;i++)ret|=(abs(ans[i]%4)==2)<<i;
    printf("%d",ret);
}