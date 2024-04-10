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
map<pi,vi> dp;
const int B=128;
void addSub(vi& v, vi sub, int rt) {
    int extra=v.size();
    sub[0]=-extra+rt;
    for(auto& i : sub) v.push_back(i+extra);
}
bool perfectTree(int n) {
    return (n&(n+1))==0;
}
vi solve(int n, int k) {
    if(k<0 or n%2==0) return {};
    int leafs = (n+1)/2;
    if(n-leafs<k) return {};
    if(n==1) return {0};
    if(n<=B) {
        if(dp.count({n,k})) return dp[{n,k}];
        // brute force
        for(int a=1;a<n;++a) {
            int b = n-1-a;
            if(a>b) continue;
            int imbal = a*2<=b;
            for(int ka=0;ka<=k-imbal;++ka) {
                int kb = k-imbal-ka;
                auto v1 = solve(a,ka), v2 = solve(b,kb);
                if(v1.empty() or v2.empty()) continue;
                vi res = {0};
                addSub(res,v1,1);
                addSub(res,v2,1);
                return dp[{n,k}] = res;
            }
        }
        return dp[{n,k}] = {};
    } else {
        vi res = {0};
        int rt=1;
        while(n>B and k>2) {
            res.push_back(rt);
            res.push_back(rt);
            --k;
            rt+=2;
            n-=2;
        }
        rt = max(0,rt-2);
        res.pop_back();

        
        
        vi sub;
        if(n<=B) sub=solve(n,k);
        else {
            if(k==2) {
                int a = (n-1)/2;
                int b = n-1-a;
                while(a%2==0 or perfectTree(a) or perfectTree(b)) ++a,--b;
                auto v1 = solve(a,1), v2 = solve(b,1);
                if(!v1.empty() and !v2.empty()) {
                    sub = {0};
                    addSub(sub,v1,1);
                    addSub(sub,v2,1);
                }
            } else for(int i : {0,1}) {
                int a = (1<<(__lg(n-1)-i)) - 1;
                int b = n-1-a;
                bool bal = (a*2>b and b*2>a);
                if(bal or ((b+1)&b)==0) {
                    auto v1 = solve(a,0), v2 = solve(b,k-!bal);
                    if(!v1.empty() and !v2.empty()) {
                        sub = {0};
                        addSub(sub,v1,1);
                        addSub(sub,v2,1);
                        break;
                    }
                }
            }
        }
        if(sub.empty()) return {};
        
        addSub(res,sub,rt);
        return res; 
    }
}
int main() {
    int n,k; cin >> n >> k;
    auto res = solve(n,k);
    if(res.empty()) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << res << '\n';
    }
}