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
typedef array<int,3> block;
int query(int a, int b, int c) {
    cout << "? " << a+1 << ' '<< b+1 << ' ' << c+1 << endl;
    cin >> a;
    return a;
}
int query(block b) { return query(b[0],b[1],b[2]); }
void solve() {
    int n; cin >> n;
    auto makeB = [&](int i) {
        return block{i,i+1,i+2};
    };
    vector<block> bs[2];
    for(int i=0;i<n;i+=3) {
        auto tmp = makeB(i);
        bs[query(tmp)].push_back(tmp);
    }
    vector<bool> ans(n);
    int z=-1,o=-1;
    auto dumb = [&](int i) {
        ans[i] = query(i,o,z);
    };
    {
        auto a = bs[0].back(); 
        auto b = bs[1].back(); 
        // budget of 12 queries to find all values of blocks a and b
        // consider a[i],b[i], try all others -> 8 queries
        // then have the z and o, Now that they are 0,1,1 0,1,0   or  1,0,1 1,0,0, only need 1 more query
        auto isgood = [&](int i) {
            int h[2] = {};
            int got[2] = {};
            vector<bool> tmp(n);
            for(int jj=2;jj>=1;--jj) {
                int j = (jj+i)%3;
                auto t = query(a[i],b[i],a[j]);
                h[t]=true;
                tmp[a[j]] = t;
                got[t]=a[j];
                t=query(a[i],b[i],b[j]);
                h[t]=true;
                tmp[b[j]] = t;
                got[t]=b[j];
            }
            if(h[0] and h[1]) {
                z=a[i], o=b[i];
                if(query(z,got[0],got[1])) swap(z,o);
                ans=tmp;
                return true;
            } else {
                ans[a[i]] = ans[b[i]] = h[1];
            }
            return false;
        };
        if(!isgood(0) and !isgood(1)) {
            z = a[2], o = b[2];
        }
        bs[0].pop_back();
        bs[1].pop_back();
        ans[z]=0;
        ans[o]=1;
    }
    

    for(auto b : bs[0]) {
        if(query(o,b[0],b[1])) {
            // b[0],b[1] are 0 and 1
            ans[b[2]]=0;
            dumb(b[0]);
            ans[b[1]] = !ans[b[0]];
        } else {
            ans[b[0]]=ans[b[1]]=0;
            dumb(b[2]);
        }
    }
    for(auto b : bs[1]) {
        if(!query(z,b[0],b[1])) {
            // b[0],b[1] are 0 and 1
            ans[b[2]]=1;
            dumb(b[0]);
            ans[b[1]] = !ans[b[0]];
        } else {
            ans[b[0]]=ans[b[1]]=1;
            dumb(b[2]);
        }
    }
    vi res;
    for(int i=0;i<n;++i) if(!ans[i]) res.push_back(i+1);
    cout << "! " << res.size() << ' ' << res << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}