#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=2e5+10;
int a[22];
bool gud[1<<22];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int bes=(1<<n)-1;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        a[x]|=(1<<y);
        a[y]|=(1<<x);
    }
    gud[0]=1;
    for(int i=0;i<1<<n;i++){
        for(int j=0;j<n;j++)if((i>>j)&1){
            if(!gud[i-(1<<j)])continue;
            gud[i]|=(bool)(a[j]&(i-(1<<j)));
        }
        if(__builtin_popcount(i)==1)gud[i]=1;
        if(!gud[i])continue;
        if(__builtin_popcount(i)>=__builtin_popcount(bes))continue;
        bool gud=1;
        for(int j=0;j<n;j++){
            if(__builtin_popcount(a[j])==n-1)continue;
            if(a[j]&i)continue;
            gud=0;
        }
        if(gud)bes=i;
    }
    printf("%d\n",__builtin_popcount(bes));
    for(int i=0;i<n;i++)if((bes>>i)&1)printf("%d ",i+1);
}