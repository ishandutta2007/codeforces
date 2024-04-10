#include<iostream>
#include<cmath> 
#include<cstdio>
#include<algorithm>
#include<string>
#define N 200005
#define INF 0x4fffffff
#define PI 3.14159265358979323846
#define MM 1000000007

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

string s;
int n,m,i,j,k,l,ans,tmp;
int a[111][111],f[111][111];

int main(){
    scanf("%d%d",&n,&m);
    getline(cin,s);
    rep(i,1,n){
        getline(cin,s);
        rep(j,1,m)
            a[i][j]=-1+2*(s[j-1]=='W');
    } 
    rep(i,1,n)
    rep(j,1,m)
        f[i][j]=0;
    ans=0;
    rrep(i,n,1)
    rrep(j,m,1){
        if (f[i][j]!=a[i][j]){
            ans++;
            tmp=a[i][j]-f[i][j];
            rep(k,1,i)
            rep(l,1,j)
                f[k][l]+=tmp;
        }
    }
    printf("%d\n",ans);
    return 0;
}