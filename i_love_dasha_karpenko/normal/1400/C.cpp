#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E5+7;
const ll INF = 1E17;
const ll MAXN = 1E6;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll x,n;
        cin>>x;
        n = s.length();
        for(ll i = 0;i<n;++i){
            if (s[i]=='1'){
                if (i-x>=0)A[i-x]++;
                if (i+x<n)A[i+x]++;
            }
        }
        for(ll i = 0;i<n;++i){
            if (A[i]==2)A[i] = 1;
            else if (A[i]==0)A[i] = 0;
            else{
                if (i-x<0 || i+x>=n)A[i] = 1;
                else A[i] = 0;
            }
        }
        ll flag = 0;
        for(ll i = 0;i<n;++i){
            if (s[i]=='0'){
                if (i+x<n && A[i+x]==1)flag = 1;
                if (i-x>=0 && A[i-x]==1)flag = 1;
            }
            if (s[i]=='1'){
                ll ct = 0;
                if (i+x<n && A[i+x]==1)ct = 1;
                if (i-x>=0 && A[i-x]==1)ct = 1;
                if (ct==0)flag = 1;
            }
        }
        if (flag){
            cout<<"-1\n";
            forn(i,n)A[i-1] = 0;
            continue;
        }
        forn(i,n)cout<<A[i-1];
        cout<<endl;
        forn(i,n)A[i-1] = 0;

    }
    return 0;
}