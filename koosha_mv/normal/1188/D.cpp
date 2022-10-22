#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define is_bit(x,y) (0<(x&(1ll<<y)))
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e5+9,Lg=62,S=2;
 
int n,dp[Lg][N],Rank[Lg][N],Rnk[Lg][N];
ll mx,a[N];
pair<int,int> res[Lg][N][S];
pair<ll,int> b[N];
 
void Fupdate(int lg,int bit){
    f(i,1,n+1){
        res[lg][0][bit].F+=((is_bit(a[i],lg)+bit)&1);
        if(is_bit(a[i],lg)+bit==2){
             maxm(res[lg][0][bit].S,Rank[lg][i]);
        }
    }
    minm(dp[lg+1][res[lg][0][bit].S],dp[lg][0]+res[lg][0][bit].F);
}
void update(int x,int lg,int bit){
    ll u=a[Rnk[lg][x]];
    res[lg][x][bit]=res[lg][x-1][bit];
    if(2<=is_bit(u,lg)+bit+1){
        maxm(res[lg][x][bit].S,Rank[lg][Rnk[lg][x]]);
    }
    if((is_bit(u,lg)+bit+1)&1) res[lg][x][bit].F+=2;
    res[lg][x][bit].F--;
    minm(dp[lg+1][res[lg][x][bit].S],dp[lg][x]+res[lg][x][bit].F);
}
 
int main(){
    cin>>n;
    f(i,1,n+1){
        cin>>a[i];
        maxm(mx,a[i]);
    }
    f(i,1,n+1)
        a[i]=mx-a[i];
    f(i,0,Lg-1){
        f(j,1,n+1)
            b[j]=mp(a[j]%(1ll<<(i+1)),j);
        sort(b+1,b+1+n);
        reverse(b+1,b+1+n);
        f(j,1,n+1){
            Rank[i][b[j].S]=j;
            Rnk[i+1][j]=b[j].S;
        }
    }
    f(j,0,Lg)
        f(i,0,n+1) 
            dp[j][i]=N*Lg;
    dp[0][0]=0;
    f(i,0,Lg-1){
        Fupdate(i,0);
        Fupdate(i,1);
        f(j,1,n+1){
            update(j,i,0);
            update(j,i,1);
        }
    }
    cout<<dp[Lg-2][0]<<'\n';
}