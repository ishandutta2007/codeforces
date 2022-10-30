#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update> ms;
const ll DIM = 200000+7;
const ll INF = 10e14;
const ll MOD = 1000000007;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)

ll n,V[DIM];
vector<ll> A[30];
inline ll gi(char ch){
    return ch-'a';
}
vector<ll> P[DIM];
void bfs(ll v){
    queue<ll> q;
    q.push(v);
    while(!q.empty()){
        v = q.front(); q.pop();
        V[v] = 1;

        for(ll to:P[v]){
            while(!A[to].empty()){
                if (V[A[to].back()]==0){
                    q.push(A[to].back());
                    V[A[to].back()]= 1;
                }
                A[to].pop_back();
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n){
        string s; cin>>s;
        sort(s.begin(),s.end());
        for(ll j = 0;j<s.length();j++){
                //cout<<gi(s[j])<<endl;
            if (j==0 || s[j-1]!=s[j]){
                P[i].pb(gi(s[j]));
            }
            if (A[gi(s[j])].empty() || A[gi(s[j])].back()!=i){
                A[gi(s[j])].pb(i);
            }

        }
    }
    ll res = 0;
    forn(i,n){
        if (V[i]==0){res++;bfs(i);}

    }
    cout<<res<<endl;
    return 0;
}