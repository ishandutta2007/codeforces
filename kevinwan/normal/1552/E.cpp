#include <bits/stdc++.h>
using namespace std;
 
mt19937_64 rng(time(0));
const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=2e5+10;
const ll mod=998244353;

pii ans[mn];
int c[mn];
int pr[mn];
bool done[mn];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n*k;i++)cin>>c[i],--c[i];
    memset(pr,-1,sizeof(pr));
    for(int i=0;i<n*k;i++){
        if(pr[c[i]]!=-1&&!done[c[i]]){
            done[c[i]]=ans;
            ans[c[i]]={pr[c[i]], i};
            int rg=c[i]/(k-1);
            for(int i=0;i<k-1;i++)pr[rg*(k-1)+i]=-1;
        }
        else pr[c[i]]=i;
    }
    for(int i=0;i<n;i++)printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}