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
const int mxN = 2e5+1, oo = 1e9;
string s;
unordered_map<string,int> ssid;
vvi got;
vi lens;
vector<string> substrings;
vvi ids;
int* lookup[mxN], prv[mxN],nxt[mxN];
int n,k;
void makelookup(int big) {
    auto& v = ids[big];
    auto it = v.begin();
    fill(prv,prv+n,-oo);
    fill(nxt,nxt+n,oo);
    for(int i=0;i<n;++i) {
        while(it!=v.end() and *it<i) ++it;
        if(it!=v.begin()) {
            prv[i]=*prev(it);
        }
        if(it!=v.end()) {
            nxt[i]=*it+lens[big];
        }
    }
    lookup[big] = new int[k];
    auto mylook = lookup[big];
    fill(mylook,mylook+k,oo);
    for(int j=0;j<k;++j) {
        for(int occ : ids[j]) {
            int best = min(nxt[occ]-occ, occ+lens[j]-prv[occ]);
            mylook[j] = min(mylook[j], best);
        }
        mylook[j] = max({lens[j],lens[big],mylook[j]});
    }
}
int bruteforce(int i, int j) {
    int li = lens[i], lj = lens[j];
    auto it = ids[j].begin();
    int ans = oo;
    for(auto a : ids[i]) {
        while(it!=ids[j].end() and *it<a) {
            ans = min(ans,a+li-*it);
            it++;
        }
        if(it!=ids[j].end()) {
            ans = min(ans,abs(*it+lj-a));
        }
    }
    return max({li,lj,ans});
}
const int B=400;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    n = s.size();
    s+="$$$";
    {
        unordered_map<string,vi> ssm;
        for(int i=0;i<n;++i) {
            for(int j=1;j<=4;++j) {
                ssm[s.substr(i,j)].push_back(i);
            }
        }
        k=ssm.size();
        got.resize(n);
        for(auto [ss,places]: ssm) {
            ssid[ss]=lens.size();
            for(auto i : places) {
                got[i].push_back(lens.size());
            }
            substrings.push_back(ss);
            lens.push_back(ss.size());
            ids.push_back(places);
        }
    }
    for(int i=0;i<k;++i) {
        if(ids[i].size()>=B) {
            // make lookup table
            makelookup(i);
        }
    }
    int q; cin >> q;
    while(q--) {
        string a,b; cin >> a >> b;
        if(!ssid.count(a) or !ssid.count(b)) {
            cout << "-1\n";
        } else {
            int i=ssid[a],j=ssid[b];
            if(ids[j].size()>ids[i].size()) swap(i,j);
            if(ids[i].size()>=B) {
                // precomputed the answer
                cout << lookup[i][j] << '\n';
            } else cout << bruteforce(i,j) << '\n';
        }
    }
}