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
const int P=10;
int eq[P], k=0;
void ask(vi a) {
    cout << "next " << a << endl;
    cin >> k;
    for(int i=0;i<k;++i) {
        string s; cin >> s;
        for(auto c : s) {
            eq[c-'0']=i;
        }
    }
}
int main() {
    do {
        ask({0});
        ask({0,1});
    } while(eq[0]!=eq[1]);
    vi order(P); iota(all(order),0);
    do {
        ask(order);
    } while(k>1);
    cout << "done" << endl;
}