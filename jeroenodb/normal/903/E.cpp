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
void nope() {
    cout << "-1\n";
    exit(0);
}

int main() {
    int k,n; cin >> k >> n;
    vector<string> s(k);
    auto check = [&](string t) {
        bool multiple = false;
        set<char> cnt;
        for(auto c : t) {
            if(cnt.count(c)) multiple=true;
            cnt.insert(c);
        }
        for(auto i : s) {
            vi bad;
            for(int j=0;j<n;++j) {
                if(i[j]!=t[j]) bad.push_back(j);
            }
            if(bad.size()>2 or bad.size()==1) return;
            if(bad.size()==2) {
                swap(i[bad[0]],i[bad[1]]);
                if(i!=t) return;
            }
            if(bad.size()==0) {
                // check if multiple
                if(!multiple) return;
            }
        }
        cout << t << '\n';
        exit(0);
    };
    for(auto& i : s) cin >> i;
    array<int,3> best = {-1};
    for(int i=0;i<k;++i) {
        for(int j=i+1;j<k;++j) {
            int bad=0;
            for(int o=0;o<n;++o) {
                if(s[i][o]!=s[j][o]) bad++;
            }
            best = max(best,{bad,i,j});
        }
    }
    if(best[0]>4) nope();
    // now check a bunch of candidates
    vi bad;
    for(int i=0;i<n;++i) {
        if(s[best[1]][i]!=s[best[2]][i]) bad.push_back(i);
    }
    int b = bad.size();
    check(s[best[1]]);

    for(int i=0;i<n;++i) for(int j=0;j<b;++j) {
        auto t = s[best[1]];
        swap(t[i],t[bad[j]]);
        check(t);
    }
    auto t = s[0];
    swap(t[0],t[1]);
    check(t);
    nope();

    
}