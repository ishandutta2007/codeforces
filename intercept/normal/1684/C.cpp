#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=2e5+9;
int n,m;
vector<int>a[M];
bool pd(){
    for(int i=1;i<=n;++i){
        for(int j=2;j<=m;++j){
            if(a[i][j]<a[i][j-1])return 0;
        }
    }
    return 1;
}
void work(){
    int x,y;
    x=y=1;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        a[i].clear();
        a[i].resize(m+1);
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
            if(j>1&&a[i][j]<a[i][j-1]&&x==1&&y==1){
                x=j-1,y=j;
            }
            else{
                if(j>1&&y!=1&&a[i][j]<a[i][x])y=j;
            }
        }
        while(a[i][x-1]>a[i][y])x--;
    }
    for(int i=1;i<=n;++i){
        swap(a[i][x],a[i][y]);
    }
    if(pd())cout<<x<<" "<<y<<endl;
    else puts("-1");
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}