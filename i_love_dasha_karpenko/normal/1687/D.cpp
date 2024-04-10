#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e6+7;
const ll INF = 1e18+7;
int A[N];
ll mlt[N],k[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
    }
    for(int i = 1;i<=n;i+=1){
        mlt[i] = sqrt(A[i]);
        while (mlt[i]*(mlt[i]+1)<A[i]){
            mlt[i] += 1;
        }
    }
    ll k = 0;
    while(1){
        bool flag = 1;
        ll nk = k;
        for(int i = 1;i<=n;){
            mlt[i] = sqrt(A[i]+k);
            while(A[i]+k>mlt[i]*(mlt[i]+1)){
                mlt[i] += 1;
            }
            ll l = mlt[i]*mlt[i];

            if (k<l-A[i]){
                nk = max(nk,l-A[i]);
                flag = 0;
            }
            int nxt = upper_bound(A+1+i,A+1+n,mlt[i]*(mlt[i]+1)-k) - A;
            i = nxt;
        }
        if (flag){
            break;
        }
        k = nk;
    }
    cout<<k<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}