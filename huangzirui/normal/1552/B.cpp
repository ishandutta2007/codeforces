#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500010,mod=998244353;
int i,j,n,m,l,k,r[maxn][6];
void check(int &x,int y){
    int sum=0;
    for(int i=1;i<=5;i++)if(r[x][i]>r[y][i])++sum;
    if(sum>=3)x=y;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++)scanf("%d%d%d%d%d",&r[i][1],&r[i][2],&r[i][3],&r[i][4],&r[i][5]);
        int now=1;
        for(i=2;i<=n;i++)check(now,i);
        int last=now,b=0;
        for(i=1;i<=n;i++){check(now,i);if(now!=last)b=1;}
        printf("%d\n",b?-1:now);
    }
}