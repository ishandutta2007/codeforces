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
struct smallmap {
    int to[12] = {};
    int& operator[](int i) {return to[i-'a'];}
};
const int MSK = 1<<12;

int main() {
    int n; cin >> n;
    vector<smallmap> tr = {{}};
    vi par = {{-1}}, w = {{0}}, suf = {{0}};
    auto add = [&](string s, int c) {
        int at = 0;
        for(auto c : s) {
            if(!tr[at][c]) {
                w.push_back(0);
                suf.push_back(0);
                par.push_back(at);
                tr.push_back({});
                tr[at][c] = w.size()-1;
            }
            at = tr[at][c];
        }
        w[at]+=c;
    };
    for(int i=0;i<n;++i) {
        int ww; cin>>ww;
        string s; cin >> s;
        deque<char> t = {};
        int at=0;
        bool bad=0;
        for(auto c : s) {
            if(at+1<t.size() and t[at+1]==c) {
                ++at;
            } else if(at>0 and t[at-1]==c) {
                --at;
            } else if(at==0) {
                t.push_front(c);
            } else if(at==t.size()-1) {
                t.push_back(c);
                ++at;
            } else {
                bad=true;
                break;
            }
        }
        if(set<char>(all(t)).size()!=t.size() ) {
            bad=1;
        }
        if(!bad) {
            add(string(all(t)),ww);
            auto rt = t;
            reverse(all(rt));
            if(rt!=t) {
                add(string(all(rt)),ww);
            }
        }
    }
    // create AC automaton
    vi q= {0};
    for(int r=0;r<int(q.size());++r) {
        int at = q[r];
        w[at]+=w[suf[at]];
        for(char c='a';c<'a'+12;++c) {
            int& to = tr[at][c];
            if(to) {
                q.push_back(to);
                suf[to] = at?tr[suf[at]][c]:0;
            } else {
                to = tr[suf[at]][c];
            }
        }
    }
    // make giant DP
    n = tr.size();
    vector<array<int,MSK>> dp(n);
    vector<array<pi,MSK>> pdp(n);
    for(auto& i : dp) fill(all(i),-oo);
    dp[0][0]=0;
    
    for(int j=0;j<MSK;++j) {
        for(int st=0;st<n;++st) if(dp[st][j]!=-oo) {
            for(int c=0;c<12;++c) if(!(1<<c & j)) {
                int to = tr[st][c+'a'];
                int nmsk = 1<<c | j;
                if(dp[st][j]+w[to]>dp[to][nmsk]) {
                    dp[to][nmsk] = dp[st][j]+w[to];
                    pdp[to][nmsk] = {st,j};
                }
            }
        }
    }
    int at=0;
    for(int i=0;i<n;++i) {
        if(dp[at][MSK-1]<dp[i][MSK-1]) {
            at=i;
        }
    }
    string ans;
    int msk= MSK-1;
    while(ans.size()<12) {
        auto [to,nmsk] = pdp[at][msk];
        ans.push_back(__lg(nmsk^msk)+'a');
        msk=nmsk;
        at=to;
    }
    cout << ans << '\n';

}