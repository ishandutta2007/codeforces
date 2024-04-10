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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    if(s[0]>s[1]) swap(s[0],s[1]);
    if(s == "01") {
        cout << 0;
        exit(0);
    }
    int digs=1;
    int pw=1, lg=1;
    while(digs+lg<s.size()) {
        digs++;
        if(digs==pw*10) pw*=10,lg++;
    }
    assert(digs+lg==s.size());
    int cnt[11] = {};
    for(auto c : s) cnt[c-'0']++;
    for(auto c : to_string(digs)) cnt[c-'0']--;
    string sub; cin >> sub;
    int leading = sub[0]-'0';
    bool lt = true;
    for(int i=1;i<sub.size();++i) {
        if(sub[i]-'0'!=leading) {
            lt = (sub[i]-'0')<leading;
            break;
        }
    }
    for(auto c : sub) cnt[c-'0']--;
    // tricky cases with zeros
    int left= digs-sub.size();
    if(left==cnt[0]) {
        // all zeroes
        string res = sub+ string(left ,'0');
        cout << res;
        exit(0);
    }
    string res;
    string res2;
    if(leading==0 or cnt[0]) {
        if(leading!=0) {
            res2=sub;
            for(int i=0;i<10;++i) {
                for(int j=0;j<cnt[i];++j) res2.push_back('0'+i);
            }
        }
        for(int i=1;i<=10;++i) if(cnt[i]) {
            cnt[i]--;
            res.push_back(i+'0');
            break;
        }
    }
    if(!lt) leading++;
    for(int i=0;i<=10;++i) {
        if(leading==i) res+=sub;
        while(cnt[i]--) res.push_back('0'+i);
    }
    if(res2.size()!=digs) res2 = string(digs,'9');
    cout << min(res,res2);
}