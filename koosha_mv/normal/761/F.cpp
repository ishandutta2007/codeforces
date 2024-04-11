#include <bits/stdc++.h>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e3+9,M=27,K=3e5+99;

ll n,m,k,ans=1e18,cor[K][2][2],cnt[N][N][M],dist[N][N][M];
string s[N];
int c[K];

void read(){
    cin>>n>>m>>k;
    f(i,0,m+2) s[0]+=' ';
    f(i,1,n+1){
        cin>>s[i];
        s[i]=' '+s[i]+' ';
        f(j,1,m+1)
            s[i][j]=s[i][j]-'a';
    }
    s[n+1]=s[0];
    f(i,0,k){
        Gett(cor[i][0][0],cor[i][0][1]);
        Gett(cor[i][1][0],cor[i][1][1]);
        char mv;
        cin>>mv;
        c[i]=mv-'a';
        cnt[cor[i][1][0]][cor[i][1][1]][c[i]]++;
        cnt[cor[i][0][0]-1][cor[i][0][1]-1][c[i]]++;
        cnt[cor[i][1][0]][cor[i][0][1]-1][c[i]]--;
        cnt[cor[i][0][0]-1][cor[i][1][1]][c[i]]--;
    }
}
void calc(int x,int y){
    int t=0,sum=0;
    f(i,0,M) t+=cnt[x][y][i];
   	cnt[x][y][s[x][y]]+=k-t;
    f(i,0,M) sum+=i*cnt[x][y][i];
    t=k;
    f(i,0,M-1){
        t-=cnt[x][y][i];
        dist[x][y][i]=sum;
        sum-=t;
        sum+=(k-t);
    }
    dist[x][y][M-1]=dist[x][y][s[x][y]];
}
void make(){
    f_(i,n,1)
        f_(j,m,1)
            f(l,0,M)
                cnt[i][j][l]+=cnt[i+1][j][l]+cnt[i][j+1][l]-cnt[i+1][j+1][l];
    f(i,1,n+1)
        f(j,1,m+1)
            calc(i,j);
    f(x,1,n+1)
        f(y,1,m+1)
            f(l,0,M)
                dist[x][y][l]+=dist[x-1][y][l]+dist[x][y-1][l]-dist[x-1][y-1][l];
}
void solve(int i){
    ll res;
    res=dist[n][m][M-1];
    res-=dist[cor[i][1][0]][cor[i][1][1]][M-1];
    res-=dist[cor[i][0][0]-1][cor[i][0][1]-1][M-1];
    res+=dist[cor[i][1][0]][cor[i][0][1]-1][M-1];
    res+=dist[cor[i][0][0]-1][cor[i][1][1]][M-1];
    res+=dist[cor[i][1][0]][cor[i][1][1]][c[i]];
    res+=dist[cor[i][0][0]-1][cor[i][0][1]-1][c[i]];
    res-=dist[cor[i][1][0]][cor[i][0][1]-1][c[i]];
    res-=dist[cor[i][0][0]-1][cor[i][1][1]][c[i]];
    minm(ans,res);
}
void do_it(){
    f(i,0,k)
        solve(i);
}
main(){
    read();
    make();
    do_it();
    cout<<ans;
}