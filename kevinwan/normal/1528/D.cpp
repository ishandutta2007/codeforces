#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=610;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=998244353;
vi num[mn];
ll d[mn][mn];
ll ca[mn][mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    memset(d,0x3f,sizeof(d));
    memset(ca,0x3f,sizeof(ca));
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ca[a][b]=min(ca[a][b],ll(c));
    }
    for(int s=0;s<n;s++){
        for(int i=0;i<n;i++)num[i].clear();
        ll mi = LLONG_MAX;
        for(int i=0;i<n;i++)mi=min(mi,ca[s][i]);
        cerr<<mi<<endl;
        for(int i=0;i<n;i++)if(ca[s][i]<mi+n)num[ca[s][i]-mi].push_back(i);
        for(int i=0;i<n;i++)for(int x:num[i]){
            if(d[s][x]!=0x3f3f3f3f3f3f3f3f)continue;
            d[s][x]=mi+i;
            if(i==n-1)continue;
            num[i+1].push_back((x+1)%n);
            for(int j=0;j<n;j++){
                if(i+ca[x][j]<n)num[i+ca[x][j]].push_back((j+mi+i)%n);
            }
        }
    }
    for(int i=0;i<n;i++){
        d[i][i]=0;
        for(int j=0;j<n;j++)printf("%lld ",d[i][j]);
        printf("\n");
    }
}