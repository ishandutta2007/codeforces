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
const int mxN = 3.01e5+1, oo = 1e9;
struct persistentarray {
    struct node {
        int c[2]={};
    };
    node* seg = new node[mxN*50];
    int n,roots[mxN]={},p=1;
    int build(int l, int r) {
        int at = p++, mid = (l+r)/2;
        if(l!=r) {
            seg[at].c[0] = build(l,mid);
            seg[at].c[1] = build(mid+1,r);
        } else {
            seg[at].c[0] = -1;
        }
        return at;
    }
    persistentarray(){}
    void init(int nn) {
        n = nn;
        p=1;
        roots[0] = build(0,n-1);
    }
    int getImp(int l, int r, int i, int j) {
        while(true) {
            if(l==r) return seg[i].c[0];
            int mid = (l+r)/2;
            if(j<=mid) {
                r = mid;
                i = seg[i].c[0];
            } else {
                l = mid+1;
                i = seg[i].c[1];
            }
        }
    }
    int updateImp(int l, int r, int i, int j, int val) {
        if(l==r) {
            int at = p;
            seg[p++].c[0] = val;
            return at;
        }
        int mid = (l+r)/2, at= p;
        seg[p++] = seg[i];
        if(j<=mid) {
            seg[at].c[0] = updateImp(l,mid,seg[i].c[0],j,val);
        } else {
            seg[at].c[1] = updateImp(mid+1,r,seg[i].c[1],j,val);
        }
        return at;
    }
    int get(int v, int i) {
        return getImp(0,n-1,roots[v],i);
    }
    int update(int newroot, int v, int i, int val) {
        roots[newroot] = updateImp(0,n-1,roots[v],i,val);
        return roots[newroot];
    }

};
persistentarray ps;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    
    while(t--) {
        int n; cin >> n;
        ps.init(n);
        vi dp(n+1), l(n,-1);
        vi a(n); for(auto& i : a) cin >> i,--i;
        ll ans=0;
        for(int i=0;i<n;++i) {
            l[i] = ps.get(i,a[i]);
            if(l[i]!=-1) dp[i+1]=dp[l[i]--]+1;
            ans+=dp[i+1];
            ps.update(i+1,l[i]+1,a[i],i);
        }
        cout << ans << '\n';
    }
}