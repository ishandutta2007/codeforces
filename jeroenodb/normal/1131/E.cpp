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
const int mxN = 1e5+1;
const ll oo = 6e9;
void cmax(int& a, int b) {a = max(a,b);}
int ch(char c) {return c-'a';}
int main() {
    int n; cin >> n;
    vector<string> p(n);
    for(auto& i : p) cin >> i;
    struct DS {
        int ans[26]= {};
        DS(string s) {
            int cur=0;
            int n = s.size();
            for(int i=0;i<n;++i) {
                cur++;
                if(i==n-1 or s[i]!=s[i+1]) {
                    cmax(ans[ch(s[i])], cur);
                    cur=0;
                }
            }
        }
    };
    auto multiply = [](DS& ds, string s) {
        char l = s[0],r = s.back();
        int n = s.size();
        DS res(s);
        if(count(all(s),l)==n) {
            for(int i=0;i<26;++i) {
                cmax(res.ans[i], min(ds.ans[i],1));
                if(i==ch(l)) {
                    cmax(res.ans[i], ds.ans[i]*(n+1)+n);
                }
            }
        } else {
            int lo=1,hi=1;
            while(s[lo]==s[0]) lo++;
            while(s.back()==s[n-1-hi]) hi++;
            for(int i=0;i<26;++i) if(ds.ans[i]) {
                int cur=1;
                if(ch(l)==i) cur+=lo;
                if(ch(r)==i) cur+=hi;
                cmax(res.ans[i], cur);
            }
        }
        swap(ds,res);
    };

    DS ds(p[0]);
    for(int i=1;i<n;++i) {
        multiply(ds,p[i]);
    }
    cout << *max_element(ds.ans,ds.ans+26) << '\n';
}