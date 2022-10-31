//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
#define endl '\n'
#define time fdgfdgdf
const ll DIM = 2E5+7;
const ll INF = 1E18;
ll A[2][DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i){
            A[0][i] = A[1][i] = -1;
        }
        ll left = n;
        ll cnt[] = {0,0};

        for(ll i = 1;i<=n;++i){
            char ch;
            cin>>ch;
            if (ch=='0') {
                ll fi = 0, sc = 1;
                if (cnt[0] > cnt[1]) {
                    swap(fi, sc);
                }
                A[fi][i] = 0;
                A[sc][i] = 1;
                cnt[fi]++;
                cnt[sc]--;
                --left;
            }

        }
        ll posit = (left-cnt[0])/2; // posit-neg+cnt = 0 ;  neg = sum-posit;  posit-sum+posit = -cnt; posit = (sum-cnt)/2/2
        if (cnt[0]!=cnt[1] || cnt[0]%2!=left%2 || posit<0 || posit>left){
            cout<<"NO\n";
            continue;
        }
        ll cur[] = {0,0},flag = 0;
        for(ll i = 1;i<=n;++i){
            if (A[0][i]==-1 && posit){
                --posit;
                A[0][i] = A[1][i] = 0;
            }
            else if (A[0][i]==-1){
                A[0][i] = A[1][i] = 1;
            }
            if (A[0][i]==0)++cur[0];
            else --cur[0];
            if (A[1][i]==0)++cur[1];
            else --cur[1];
            if (cur[0]<0 || cur[1]<0)flag = 1;
        }
        if (flag || cur[0]!=0 || cur[1]!=0){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(ll c = 0;c<2;++c) {
            for (ll i = 1; i <= n; ++i)
                if (A[c][i]==0)
                    cout<<'(';
                else cout<<')';
            cout<<endl;
        }
    }
    return 0;
}