#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mxN = 1e5+1, oo = 1e9;
vi kmpi(const string& p) { // constructs PI function for pattern p
    int n = p.size();
    vi pi(n);
    for(int i=1,j=0;i<n;++i) {
        while(j!=0 and p[j]!=p[i]) {
            j=pi[j-1]; // simulating KMP
        }
        if(p[i]==p[j]) j++;
        pi[i] = j;
    }
    return pi;
}
int k;
struct tree { // walking up on tree amortization trick, made into a data structure
    vi from;
    vector<bool> got;
    vi pi;
    tree(string s) {
        got.resize(s.size()+1);
        from.resize(s.size()+1,-1);
        pi = kmpi(s);
        got[0]=true;
    }
    vi add(int j, int i=-1) {
        vi nw;
        while(!got[j]) {
            got[j]=true;
            nw.push_back(j);
            from[j]=i;
            j = pi[j-1];
        }
        return nw;
    }
};
vi KMP(const string& p, const string& s) {
    auto pi = kmpi(p);
    int n = s.size();
    vi ans(n);
    for(int i=0,j=0;i<n;++i) {
        while(j!=0 and (j==(int)p.size() or p[j]!=s[i])) {
            j = pi[j-1];
        }
        if(p[j]==s[i]) j++;
        // j now at maximum matching suffix
        ans[i]=j;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m >> k;
    string s,t; cin >> s >> t;
    reverse(all(s)),reverse(all(t));
    auto maxsufrev = KMP(t,s);

    tree tr(t);
    for(int i=k-1;i<n;++i) 
        tr.add(maxsufrev[i], n-1-i);
    tr.from[0]=n-k;
    reverse(all(s)),reverse(all(t));
    auto maxsuf = KMP(t,s);
    // easy case, one word is entirely in one substring
    auto check = [&](int a, int b) {
        if(a<0 or b+k>n) return;
        cout << "Yes\n" << a+1 << ' ' << b+1 << '\n';
        exit(0);
    };
    if(m<=k) for(int i=0;i<n;++i) {
        if(maxsuf[i]==m) {
            int leftmost = max(0,i-k+1);
            check(leftmost,leftmost+k);
            int rightmost = min(i-m+1, n-k);
            check(rightmost-k, rightmost);
        }
    }
    tree tr2(t);
    for(int i=0;i+k<n;++i) {
        if(i>=k-1) {
            auto nw = tr2.add(maxsuf[i]);
            for(auto j : nw) {
                int o = m-j;
                if(j<=k and o<=k and tr.from[o]>i) {
                    // found answer
                    check(i-k+1, tr.from[o]);
                }
            }
        }
    }
    cout << "No\n";
    
    
}