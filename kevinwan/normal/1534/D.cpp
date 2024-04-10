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
const int mn=2e3+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;

int d[mn],num[2],dis[mn];
vector<pii> ans;

int main(){
    int n;
    scanf("%d",&n);
    printf("? 1\n");
    fflush(stdout);
    for(int i=1;i<=n;i++){
        scanf("%d",d+i);
    }
    for(int i=2;i<=n;i++)num[d[i]&1]++;
    bool pty = (num[1]<num[0]);
    if(pty ==0) for(int i=1;i<=n;i++) if(d[i]==1)ans.push_back({1,i});
    for(int i=2;i<=n;i++) if((d[i]&1)==pty){
        printf("? %d\n",i);
        fflush(stdout);
        for(int j=1;j<=n;j++){
            scanf("%d",dis+j);
            if(dis[j]==1)ans.push_back({i,j});
        }
    }
    printf("!\n");
    for(pii p:ans)printf("%d %d\n",p.first,p.second);
    fflush(stdout);
}