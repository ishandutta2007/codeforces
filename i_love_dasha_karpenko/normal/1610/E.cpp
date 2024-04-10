//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;
const int N = 2e5+7;
int A[N],n;
int calc(int start){
    int beg = A[start];
    int cur = upper_bound(A+1,A+1+n,beg)-A;
    --cur;
    cur = max(cur,start+1);
    int ret = cur-start+1;
    while(cur<=n){
        int nxt = A[cur]*2-beg;
        int npos = lower_bound(A+cur+1,A+1+n,nxt)-A;
        if (npos>n)
            break;
        ++ret;
        cur = npos;
    }
    return ret;
}
void solve(){

    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    sort(A+1,A+1+n);
    int res = 2;
    for(int pos = 1;pos+2<=n;++pos){
        res = max(res,calc(pos));
    }
    cout<<n-res<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}