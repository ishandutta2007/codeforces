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
struct minq {
    vi q; // haha
    int p=0;
    void push(int v) {
        while(q.size()>p and q.back()<v) {
            q.pop_back();
        }
        q.push_back(v);
    }
    void remove(int v) {
        if(p!=q.size() and q[p]==v) p++;
    }
    int max() {return q[p];}
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w; cin >> n >> w;
    vector<ll> pref(w+1), res(w);
    while(n--) {
        int k; cin >> k;
        minq q;
        vi a(k); for(int& i : a) cin >> i;
        if(k*2<w) {
            int mx=0;
            for(int i=0;i<k;++i) {
                mx = max(mx,a[i]);
                res[i]+=mx;
            }
            mx = 0;
            for(int i=0;i<k;++i) {
                mx = max(mx,a[k-1-i]);
                res[w-1-i]+=mx;
            }
            pref[k]+=mx;
            pref[w-k]-=mx;
        } else {
            int l=0,r=-1;
            for(int i=0;i<w;++i) {
                while(r<k-1 and r<i) {
                    q.push(a[++r]);
                }
                while(k-l>w-i) {
                    q.remove(a[l++]);
                }
                auto tmp = q.max();
                if(i>=k or w-i-1>=k) tmp=max(tmp,0);
                res[i]+=tmp;
            }
        }
    }
    for(int i=0;i<w;++i) {
        if(i) pref[i]+=pref[i-1];
        cout << pref[i]+res[i] << ' ';
    }
}