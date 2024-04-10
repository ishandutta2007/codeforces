//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2E5+7;
ll A[DIM],B[DIM],suf[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> V1,V2;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
            if (A[i]>0)V2.push_back(A[i]);
            else V1.push_back(-A[i]);
        }

        vector<ll> BV1,BV2;
        for(ll i = 1;i<=m;++i){
            cin>>B[i];
            if (B[i]>0){
                BV2.push_back(B[i]);
            }
            else{
                BV1.push_back(-B[i]);
            }

        }
        ll ans = 0;
        {
            n = V1.size(),m = BV1.size();
            if (n!=0 && m!=0) {
                A[n + 1] = B[m + 1] = 0;
                reverse(V1.begin(), V1.end());
                reverse(BV1.begin(), BV1.end());
                for (ll i = 1; i <= n; ++i) {
                    A[i] = V1[i - 1];
                    suf[i] = 0;
                }
                suf[n + 1] = 0;
                set<ll> S;
                for (ll i = 1; i <= m; ++i) {
                    B[i] = BV1[i - 1];
                    S.insert(B[i]);
                }


                for (ll i = n; i >= 1; --i) {
                    suf[i] = suf[i + 1] + S.count(A[i]);
                }
                queue<ll> Q;
                ll ptr = 0;
                ll res = suf[1];
                for (ll i = 1; i <= m; ++i) {
                    while (i <= m && B[i] < A[1])++i;
                    if (i > m)break;
                    while (ptr < n && A[ptr + 1] <= B[i])
                        ++ptr;
                    Q.push(B[i]);
                    while (Q.front() < B[i] - ptr + 1)Q.pop();
                    res = max(res, Q.size() + suf[ptr + 1]);
                }
                ans += res;
            }
        }
        {

            n = V2.size(),m = BV2.size();
            if (n!=0 && m!=0) {
                A[n + 1] = B[m + 1] = 0;
                for (ll i = 1; i <= n; ++i) {
                    A[i] = V2[i - 1];
                    suf[i] = 0;
                }
                suf[n + 1] = 0;
                set<ll> S;
                for (ll i = 1; i <= m; ++i) {
                    B[i] = BV2[i - 1];
                    S.insert(B[i]);
                }


                for (ll i = n; i >= 1; --i) {
                    suf[i] = suf[i + 1] + S.count(A[i]);
                }
                queue<ll> Q;
                ll ptr = 0;
                ll res = suf[1];
                for (ll i = 1; i <= m; ++i) {
                    while (i <= m && B[i] < A[1])++i;
                    if (i > m)break;
                    while (ptr < n && A[ptr + 1] <= B[i])
                        ++ptr;
                    Q.push(B[i]);
                    while (Q.front() < B[i] - ptr + 1)Q.pop();
                    res = max(res, Q.size() + suf[ptr + 1]);
                }
                ans += res;
            }
        }
        cout<<ans<<endl;
    }



    return 0;
}