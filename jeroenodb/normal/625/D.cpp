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
    string n; cin >> n;

    auto makeA = [&](deque<char> dq, bool cl=0,bool cr=0) -> string {
        string tl,tr;
        while(!dq.empty()) {
            if(cl) dq[0]+=10;
            if(cr) dq.back()--;
            cl=0,cr=0;
            if(dq.size()==1) {
                if(dq[0]%2!=0) return "";
                tl.push_back(dq[0]/2);
                break;
            }
            int sm = dq[0];
            if(sm%10!=(10+dq.back())%10) sm--,cl=1;
            if(sm%10!=(10+dq.back())%10) return "";
            if(sm-dq.back()==10) cr=1;
            if(sm<0 or sm>18) return "";
            auto use = min(sm,9);
            tl.push_back(use);
            sm-=use;
            tr.push_back(sm);
            dq.pop_front();
            dq.pop_back();
        }
        if(cl!=cr) return "";
        reverse(all(tr));
        tl+=tr;
        for(auto& i : tl) i+='0';
        
        if(tl[0]=='0') return "";
        return tl;
    };
    deque<char> dq(all(n));
    for(auto& i : dq) i-='0';
    
    auto res = makeA(dq);
    if(res.empty() and dq.size()>1 and dq[0]==1) {
        dq.pop_front();
        res = makeA(dq,true);
    }
    if(res.empty()) res='0';
    cout << res << '\n';
}