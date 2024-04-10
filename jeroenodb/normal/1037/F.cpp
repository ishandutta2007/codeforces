#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
typedef vector<int> vi;
const long long MOD = 1e9+7;

struct mint {
    int d;
    mint () {d=0;}
    mint (long long _d) : d((_d+MOD)%MOD){};
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }
    friend mint& operator-=(mint& a, const mint& o) {
        a.d-=o.d;
        if(a.d<0) a.d+=MOD;
        return a;
    }
};
void solve() {
    int n,k; cin >> n >> k;
    vi a(n);
    for(auto& i : a) cin >> i;
    vi prv(n,-1);
    for(int i=1;i<n;++i) {
        prv[i] = i-1;
        while(prv[i]!=-1 and a[prv[i]]<=a[i]) {
            prv[i]=prv[prv[i]];
        }
    }
    vi nxt(n,n);
    for(int i=n-2;i>=0;--i) {
        nxt[i] = i+1;
        while(nxt[i]!=n and a[nxt[i]]<a[i]) {
            nxt[i]=nxt[nxt[i]];
        }
    }
    vector<mint> change(n+5);
    for(int i=0;i<n;++i) {
        change[0]+=a[i];
        int t = i-prv[i]; // time at which change in derivative occurs
        change[t]-=a[i];
        t= nxt[i]-i;
        change[t]-=a[i];
        t = nxt[i]-prv[i];
        change[t]+=a[i];
    }
    int j=0,left=n,i=1;
    mint delta=0,res=0,cur=0;
    while(left>=k) {
        while(j<=i*(k-1)) {
            delta+=change[j++];
            cur+=delta;
        }
        res+=cur;
        left-=k-1;
        i++;
    }
    cout << res.d << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}