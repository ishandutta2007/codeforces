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
const int NUM = 8;
using substate = array<char,NUM>;
using state= array<substate,2>;
map<state,int> mp;

// state = [sorted numbers of the current player] [sorted numbers of the second player]
state normalized(state s) {
    sort(all(s[0])),sort(all(s[1]));
    return s;
}
int outgoing(const state& s) {
    set<state> f;
    for(int i=0;i<NUM;++i) if(!i or s[0][i]!=s[0][i-1]) {
        for(int j=0;j<NUM;++j) if(!j or s[1][j]!=s[1][j-1]) {
            if(s[0][i]*s[1][j]==0) continue;
            auto t = s;
            t[0][i] = (s[0][i]+s[1][j]+5)%5;
            f.insert(normalized(t));
        }
    }
    return f.size();
}
void checkState(const state& s) {
    if(!mp.count(s)) 
        mp[s] = outgoing(s);
}

state read() {
    state res;
    int a;
    for(int rep=0;rep<2;++rep)
        for(int i=0;i<NUM;++i) {
            cin >> a;
            res[rep][i]=a;
        }
    return normalized(res);
}
set<state> from(const state& s) {
    set<state> f;
    for(int i=0;i<NUM;++i) if(!i or s[0][i]!=s[0][i-1]) {
        for(int j=0;j<NUM;++j) if(!j or s[1][j]!=s[1][j-1])  {
            
            auto t = s;
            t[1][j] = (5+s[1][j]-s[0][i])%5;
            if(t[0][i]*t[1][j]!=0) {
                swap(t[0],t[1]);
                f.insert(normalized(t));
            }
        }
    }
    return f;
}

vector<substate> STATES;
substate cur;
void rec(int d, int have) {
    if(d==0) {
        STATES.push_back(cur);
        return;
    }
    while(have<5) {
        cur[NUM-d] = have;
        rec(d-1,have++);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    queue<state> q;
    rec(NUM,0);
    int n = STATES.size();
    for(int i=1;i<n;++i) {
        state s = {STATES[0],STATES[i]};
        q.push(s);
        mp[s]=-1;
        s = {STATES[i],STATES[0]};
        mp[s]=0;
        q.push(s);
    }
    while(!q.empty()) {
        
        auto at = q.front(); q.pop();
        auto winlose = mp[at];
        auto f = from(at);
        if(winlose==0) {
            // losing state every state leading to this is a winning state.
            for(const auto& u : f) {
                if(mp.count(u) and mp[u]<=0) 
                    continue;
                mp[u]=-1;
                q.push(u);
            }
        } else {
            for(const auto& u : f) {
                checkState(u);
                auto& tmp = mp[u];
                if(tmp>0) {
                    tmp--;
                    
                    if(tmp==0) {
                        q.push(u);
                    }
                }
            }
        }
    }
    debug(mp.size());
    int t; cin >> t;
    while(t--) {
        int f; cin >> f;
        state s = read();
        if(f==1) swap(s[0],s[1]);
        int tmp = mp.count(s)?mp[s]:1000;
        if(tmp>0) {
            cout << "Deal\n";
        } else if(!f  == (mp[s]==-1)) {
            cout << "Alice\n";
        } else cout << "Bob\n";
    }
    
}