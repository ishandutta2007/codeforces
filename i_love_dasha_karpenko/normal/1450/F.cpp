#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
ll A[DIM],cnt[DIM],cnt1[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i)cnt[i] = cnt1[i] = 0;
        ll res = 0;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
            if (A[i]==A[i-1]){
                cnt[A[i]]+=2;
                ++res;
            }
            ++cnt1[A[i]];
        }
        ++cnt[A[1]];
        ++cnt[A[n]];
        ll mx = 0,sum = 0,mx1 = 0;
        for(ll i = 1;i<=n;++i){
            mx = max(cnt[i],mx);
            mx1 = max(mx1,cnt1[i]);
            sum+=cnt[i];
        }
        if (mx1>n-mx1+1){
            cout<<"-1\n";
            continue;
        }
        cout<<res+max(0ll,mx-2-res)<<endl;

    }

    return 0;
}