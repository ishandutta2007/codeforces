//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
ll A[DIM];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        n*=2;
        ll sum = 0;
        map<ll,ll> M;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
            M[A[i]]++;
            sum+=A[i];
        }
        sort(A+1,A+1+n);
        vector<pair<ll,ll> > ans;
        map<ll,ll> left;
        ll res = 0;
        for(ll pos = 1;pos<n;++pos){
            ll flag = 0;

            ll x = A[n]+A[pos];
            ll base = x;
            left = M;
            ans.push_back({A[pos],A[n]});
            left[A[pos]]--;
            left[A[n]]--;
            x = A[n];
            for(ll i = n-1;i>=1;--i){
                if (left[A[i]]==0)continue;
                ll need = x-A[i];
                if (left[need]==0 || (need==A[i] && left[need]<2)){
                    flag = 1;
                    break;
                }
                left[need]--;
                left[A[i]]--;
                ans.push_back({need,A[i]});
                x = A[i];
            }
            if (flag==1)ans.clear();
            else{
                res = base;
                break;
            }
        }
        if (!ans.empty()){
            cout<<"YES\n"<<res<<endl;
            for(auto to:ans){

                cout<<to.first<<' '<<to.second<<endl;
            }
        }
        else cout<<"NO\n";

    }

    return 0;
}