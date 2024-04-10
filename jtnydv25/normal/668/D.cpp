#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define T pair<int,int>
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
map<int,int> ind;
vii queries;
const int N = 1e5+10;
ordered_set add[N], del[N];
int cnt[N];
int main()
{
    int n,a,t,x;
    sd(n);
    int l = 0;
    rep(i,1,n+1)
    {
        sd(a),sd(t),sd(x);
        if(!ind[x])
            ind[x] = ++l;
        if(a==1)
            add[ind[x]].insert(mp(t,++cnt[ind[x]]));
        if(a==2)
            del[ind[x]].insert(mp(t,++cnt[ind[x]]));
        if(a==3)
        {
            // cerr<<ind[x]<<endl;
            int ans = add[ind[x]].order_of_key(mp(t+1,0)) - del[ind[x]].order_of_key(mp(t+1,0));
            pd(ans);
        }
    }
}