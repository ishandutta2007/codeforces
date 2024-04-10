//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
ll A[DIM],B[DIM];
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

        sort(A+1,A+1+n);
        ll l = 0,r = (n-1)/2;
        while(l!=r){
            ll tm = (l+r+1)/2;
            deque<ll> Q;
            for(ll i = 1;i<=tm;++i){
                Q.push_back(A[i]);
            }

            for(ll i = tm+1;i<n-tm;++i){
                Q.push_back(A[i]);
            }
            for(ll i = n;i>=n-tm;--i)
                Q.push_back(A[i]);
            for(ll i = 1;i<=n;++i){
                if (i%2==0){
                    B[i] = Q.front();
                    Q.pop_front();
                }
                else{
                    B[i] = Q.back();
                    Q.pop_back();
                }
            }
            ll cnt = 0;
            for(ll i = 2;i<n;++i){
                if (B[i]<B[i+1] && B[i]<B[i-1])++cnt;
            }
            if (cnt<tm)r = tm-1;
            else l = tm;
        }
        cout<<l<<endl;
        ll tm = l;
        deque<ll> Q;
        for(ll i = 1;i<=tm;++i){
            Q.push_back(A[i]);
        }

        for(ll i = tm+1;i<n-tm;++i){
            Q.push_back(A[i]);
        }
        for(ll i = n;i>=n-tm;--i)
            Q.push_back(A[i]);
        for(ll i = 1;i<=n;++i){
            if (i%2==0){
                B[i] = Q.front();
                Q.pop_front();
            }
            else{
                B[i] = Q.back();
                Q.pop_back();
            }
        }
        for(ll i = 1;i<=n;++i)
            cout<<B[i]<<' ';
        cout<<endl;

    }
    return 0;
}