#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int mxN = 1e5+1;
struct bounds {
    int ls[mxN*3+20];
    int* h = ls+mxN+3;
    void shift(int from, int to) {
        h[to]+=h[from];
        h[from]=0;
    }
} l,r;
int n;
void step(int i) {
    l.shift(i,i+1),r.shift(i,i-1);
    l.h++,r.h--;
    l.shift(-1,0),r.shift(n,n-1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin >> n >> m;
    for(int i=0;i<n;++i) l.h[i]=r.h[i]=1;
    if(n==1) {
        cout << "0\n";
        exit(0);
    }
    step(-2);
    for(int i=0;i<m;++i) {
        int a; cin >> a,--a;
        step(a);
    }
    ll ans=0;
    for(int i=0;i<n;++i) {
        ans-=(ll)l.h[i]*(i-1);
        ans+=(ll)r.h[i]*i;
    }
    cout << ans << '\n';
}