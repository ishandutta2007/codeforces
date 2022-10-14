#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
vector<ll> sg;
bitset<20> rev;
ll query(int i, int l, int r, int a, int b, int d, bool myrev=false) {
    if(b<l or r<a) return 0;
    myrev^=rev[d];
    if(a<=l and r<=b) 
        return sg[i];
    int mid = (l+r)/2;
    return query(i*2+myrev,l,mid, a,b,d-1,myrev)+query(i*2+!myrev,mid+1,r, a,b,d-1,myrev);
}
void update(int i, int l, int r, int q, int x, int d , bool myrev=false) {
    if(q<l or r<q) return;
    myrev^=rev[d];
    if(l==r) {
        sg[i]=x;
        return;
    }
    int mid = (l+r)/2;
    update(i*2+myrev,l,mid, q ,x,d-1,myrev),update(i*2+!myrev,mid+1,r, q ,x,d-1,myrev);
    sg[i] = sg[i*2]+sg[i*2+1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    int pw = 1<<n;
    sg.resize(pw*2);
    for(int i=pw;i<pw*2;++i) {
        cin >> sg[i];
    }
    for(int i=pw-1;i>0;--i) {
        sg[i] = sg[i*2]+sg[i*2+1];
    }

    while(q--) {
        int t; cin >> t;
        if(t==1) {
            int x,k; cin >> x >> k,--x;
            update(1,0,pw-1,x,k,n);

        } else if(t==4) {
            int l,r; cin >> l >> r,--l,--r;
            cout << query(1,0,pw-1,l,r,n) << '\n';
        } else {
            int k; cin >> k;
            rev.flip(k);
            if(t==3) rev.flip(k+1); 
        }
    }
}