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
const int mxN = 1e5+1, oo = 1e4;
int h,m;
int flip[10] = {0,1,5,oo,oo,2,oo,oo,8,oo};
int flipped(int a) {
    int f = a/10, s = a%10;
    return flip[s]*10 + flip[f];
} 
bool good(pi time) {
    int s = flipped(time.first);
    int f = flipped(time.second);
    return f<h and s<m;
}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> h >> m;
        string s; cin >> s;
        int a = 0,b=0;
        for(int i=0;i<2;++i) {
            a = a*10+(s[i]-'0');
            b = b*10+(s[i+3]-'0');
        }
        pi ori = {a,b};
        pi cur = {a,b};
        bool begin = true;
        while(true) {
            begin = false;
            if(good(cur)) {
                cout << setw(2) << setfill('0')<< cur.first << ":" << setw(2) << cur.second << '\n';
                break;
            }
            cur.second+=1;
            if(cur.second>=m) {
                cur.second-=m;
                cur.first+=1;
                if(cur.first>=h) {
                    cur.first-=h;
                }
            }
        }

    }
}