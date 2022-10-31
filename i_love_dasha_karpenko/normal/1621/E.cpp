#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int INF = 1e18;
const int N = 1e5+7;
struct drib{
    ll a,b;
    drib(ll _a = 0,ll _b = 0){
        a = _a;
        b = _b;
    }
    const bool operator < (drib cmp){
        return a*cmp.b<b*cmp.a;
    }
    const bool operator <= (drib cmp){
        return a*cmp.b<=b*cmp.a;
    }
};
int dp_shift[2][N];
bool dp_suf[N],dp_pref[N];
drib A[N],B[N];
vector<int> in_B[N];
ll SS[N];
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<=m+1;++i){
        in_B[i].clear();
        dp_shift[0][i] = dp_shift[1][i] = 0;
        dp_suf[i] = dp_pref[i] = 0;
        SS[i] = 0;
    }
    for(int i = 1;i<=n;++i) {
        int val;
        cin>>val;
        A[i] = drib(val,1);
    }
    sort(A+1,A+1+n);
    for(int i = 1;i<=m;++i)
        A[i] = A[i+(n-m)];
    for(int i = 1;i<=m;++i){
        int len;
        cin>>len;
        in_B[i].resize(len);
        ll sum = 0;
        for(int j = 0;j<len;++j)
            cin>>in_B[i][j],sum+=in_B[i][j];
        B[i] = drib(sum,len);
        SS[i] = sum;
    }
    sort(B+1,B+1+m);
    // calc_dp
    dp_shift[0][0] = dp_shift[1][0] = 1;
    dp_pref[0] = 1;
    for(int i = 1;i<=m;++i){
        dp_shift[0][i] = dp_shift[0][i-1];
        dp_shift[1][i] = dp_shift[1][i-1];
        dp_pref[i] = dp_pref[i-1];
        if (A[i+1]<B[i]){
            dp_shift[1][i] = i+1;
        }
        if (i==1 || A[i-1]<B[i]){
            dp_shift[0][i] = i+1;
        }
        if (A[i]<B[i])
            dp_pref[i] = 0;
    }
    dp_suf[m+1] = 1;
    for(int i = m;i>=1;--i){
        dp_suf[i] = dp_suf[i+1];
        if (A[i]<B[i])
            dp_suf[i] = 0;
    }

    for(int i = 1;i<=m;++i){
        int len = in_B[i].size();
        int pos = lower_bound(B+1,B+1+m,drib(SS[i],len))-B;
        for(int left:in_B[i]){
            drib n_val = drib(SS[i]-left,len-1);
            int ne = lower_bound(B+1,B+1+m,n_val)-B;
            bool flag = 0;
            if (ne<=pos){
                flag = dp_pref[ne-1] && dp_shift[1][pos-1]<=ne && n_val<=A[ne] && dp_suf[pos+1];
            }
            else{
                --ne;
                flag = dp_pref[pos-1] && dp_shift[0][ne]<=pos+1 && n_val<=A[ne] && dp_suf[ne+1];
            }
            cout<<flag;
        }
    }
    cout<<endl;
}
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}