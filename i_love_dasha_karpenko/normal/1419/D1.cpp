//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    t = 1;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i) {
            cin>>A[i];
        }
        deque<ll> Q;
        sort(A+1,A+1+n);
        for(ll i = 1;i<=n;++i){
            Q.push_back(A[i]);
        }
        ll res = 0;
        for(ll i = 1;i<=n;++i){
            if (i%2){
                A[i] = Q.back();
                Q.pop_back();
            }
            else{
                if (i!=n)++res;
                A[i] = Q.front();
                Q.pop_front();
            }
        }
        cout<<res<<endl;
        for(ll i = 1;i<=n;++i)
            cout<<A[i]<<' ';
        cout<<endl;

    }
    return 0;
}