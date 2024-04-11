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
#define F first
#define S second
#define NIL 0
#define INF (1<<28)


const int N=1e6+9,M=2002,Al=26;

int n,m,a[N];
string t,s[N];
pair<int,int> dp[N],mv[M][Al];
vector<vector<vector<int> > > mark(N);

pair<int,int> find(pair<int,int> x,int p){
    x.S++;
    if(x.S==sz(s[a[x.F]])){
        x.F++;
        x.S=0;
    }
    if(m<=x.F) return mp(N,N);
    if(mark[a[x.F]][x.S][p]<N) return mp(x.F,mark[a[x.F]][x.S][p]);
    if(x.F+1==m) return mp(N,N);
    return mv[x.F+1][p];
}
void do_it(){
    f(i,0,n){
        vector<int> e(Al);
        f(i,0,sz(e)) e[i]=N;
        f(j,0,sz(s[i]))
            mark[i].pb(e);

        f_(j,sz(s[i])-1,0)
            f(k,0,Al){
                if(j!=sz(s[i])-1)
                    mark[i][j][k]=mark[i][j+1][k];
                if(s[i][j]-'a'==k) mark[i][j][k]=j;
            }
    }
    f(i,0,M)
        f(j,0,Al)
            mv[i][j]=mp(N,N);
    f_(i,m-1,0)
        f(j,0,Al){
            mv[i][j]=mv[i+1][j];
            if(mark[a[i]][0][j]<N)
                mv[i][j]=mp(i,mark[a[i]][0][j]);
        //    erorp(mv[i][j]);
        }
}


int main(){
    dp[0]=mp(0,-1);
    f_(j,M-1,1) dp[j]=mp(N,N);
    cin>>n;
    f(i,0,n)
        cin>>s[i];
    cin>>m;
    f(i,0,m){
        cin>>a[i];
        a[i]--;
    }
    cin>>t;
    do_it();
    f(i,0,sz(t)){
        f_(j,M-1,1){
        //    cout<<i<<" "<<j<<endl;
            if(find(dp[j-1],t[i]-'a')<dp[j]){
                dp[j]=find(dp[j-1],t[i]-'a');
           //     erorp(dp[j]);
            }
        }
    }
    f_(i,M-1,0)
        if(dp[i].F<N)
            return cout<<i,0;
}