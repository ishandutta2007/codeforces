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
    int n,m; cin >> n >> m;

    auto simulate = [&](int s, int t) {
        s+=s<m?t:-t;
        if(s<0) s+=n;
        else if(s>=n) s-=n;
        return s;
    };
    auto bigStep = [&](int s) {
        for(int t=n;t>0;--t) {
            s = simulate(s,t);
        }
        return s;
    };

    int s; ll t; cin >> s >> t;
    --s;

    vi p(n,-1);
    while(t%n!=0) {
        s=simulate(s,t%n);
        t--;
    }
    vi st;
    while(p[s]==-1) {
        st.push_back(s);
        p[s] = bigStep(s);
        s = p[s];
    }
    vi tail(st.begin(),find(all(st),s));
    vi cyc(find(all(st),s),st.end());

    ll steps= t/n;
    if(steps<tail.size()) {
        cout << tail[steps]+1 << '\n';
    } else {
        steps-=tail.size();
        cout << cyc[steps%cyc.size()]+1 << '\n';
    }


}