//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
map<ll,vector<ll> > M;
set<ll> del;
void add(ll x){
    ll base = x;
    ll last = 1;
    for(ll i = 2;i*i<=x;++i){
        if (x%i)continue;
        last = i;
        while(x%i==0)x/=i;
    }
    last = max(last,x);
    M[last].push_back(base);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll x = n;
        vector<ll> V;
        for(ll i = 2;i*i<=x;++i){
            if (x%i)continue;
            ll cnt = 0;
            while(x%i==0){
                x/=i;
                ++cnt;
            }
            V.push_back(i);
        }
        if (x!=1){
            V.push_back(x);
        }
        for(ll i = 2;i*i<=n;++i){
            if (n%i)continue;
            add(i);
            if (n/i!=i)add(n/i);
        }
        add(n);

        vector<ll> ans;
        ll res = 0;
        if (V.size()==1){
            for(ll to:M[V[0]])cout<<to<<' ';
            cout<<endl<<0<<endl;
        }
        else {
            for (ll i = 0; i < V.size(); ++i) {
                if (i > 0) {
                    ll prev = V[i - 1] * V[i];
                    if (n%prev==0)
                    cout << prev << ' ';
                    else ++res;
                    del.insert(prev);
                }
                ll nxt;
                if (V.size()-1==i) {
                    nxt = 0;
                }
                else nxt = -1;
                for (ll to:M[V[i]]) {
                    if (del.count(to) == 0){
                        if (nxt==0 && to%V[0]==0)nxt = to;
                        else
                            cout << to << ' ';
                    }
                }
                if (nxt > 0)
                    cout << nxt << ' ';
                else if (nxt==0)++res;
            }
            cout << endl << res << endl;
        }
        del.clear();
        M.clear();
    }
    return 0;
}