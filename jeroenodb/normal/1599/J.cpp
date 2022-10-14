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
typedef vector<double> vd;
const double eps = 1e-12;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define sz(x) int(size(x))

void answer(vi v) {
    cout << "YES\n" << v << '\n';
    exit(0);
}
typedef double F;
void gaussianElim(vector<valarray<F>>& A) {
    int at= 0;
    for(int i=0;i<4;++i) {
        for(int j=at;j<A.size();++j) if(abs(A[j][i])>abs(A[at][i])) 
            swap(A[j],A[at]);
        if(A[at][i]==0) 
            continue;
        for(int j=0;j<4;++j) if(j!=at and A[j][i]!=0) {
            A[j]-=A[at]*(A[j][i]/A[at][i]);
        }
        ++at;
    }
    for(auto v : A) {
        debug(v);
    }
    cout << '\n';
}
void nope() {
    cout << "NO\n";
    exit(0);
}
int main() {
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;    
    // vector<valarray<F>> A = {{1,1,0,0,1,0,0,0},{0,1,1,0,0,1,0,0},{0,0,1,1,0,0,1,0},{1,0,0,1,0,0,0,1}};
    // gaussianElim(A);
    {
        set<int> s(all(a));
        if(s.size()<n) {
            vi b(n);
            copy(all(s),b.begin());
            answer(b);
        }
    }
    vi c[2] = {};
    for(auto i : a) c[i%2].push_back(i);
    vi cyc;
    if(c[0].size()>=3) {
        for(int i=0;i<3;++i) 
            cyc.push_back(c[0].back()),c[0].pop_back();
    } else if(c[0].size()>=1 and c[1].size()>=2) {
        cyc = {c[0].back(),c[1].back()};
        c[0].pop_back(),c[1].pop_back();
        cyc.push_back(c[1].back());
        c[1].pop_back();
    }
    auto extend= [&](vi res,vi need)  {
        for(auto& i : need) {
            res.push_back(-res[0]+i);
        }
        answer(res);
    };
    if(!cyc.empty()) {
        int cc = (cyc[0]+cyc[1]-cyc[2])/2;
        vi res = {cyc[0]-cc,cyc[1]-cc,cc};
        c[0].insert(c[0].end(),all(c[1]));
        extend(res,c[0]);
    }
    if(n<=3) {
        nope();
    }
    assert(c[0].empty());
    vi left;
    if(n>=27) {
        left=vi(a.begin()+27,a.end());
        a.erase(a.begin()+27,a.end());
        n=27;
    }
    // now go through all subsets?
    vi res;
    auto find = [&](int t) {
        vi from(t*int(1e6)+1);
        vector<bool> have(n);
        for(int i=0;i<t;++i) have[n-i-1]=true;
        do {
            int sm=0,m1=0;
            for(int i=0;i<n;++i) if(have[i]) sm+=a[i],m1|=1<<i;
            if(from[sm]) {
                // construct cycle
                int m2 = from[sm];
                int gone = m2&m1;
                m1&=~gone,m2&=~gone;
                vi r[2] = {};
                for(int i=0;i<n;++i) {
                    if(1<<i & m1) r[0].push_back(a[i]);
                    else if(1<<i & m2) r[1].push_back(a[i]);
                    else left.push_back(a[i]);
                }
                vi res = {0};
                for(int i=0;i<r[0].size();++i) {
                    res.push_back(-res.back()+r[0][i]);
                    res.push_back(-res.back()+r[1][i]);
                }
                res.pop_back();
                extend(res,left);
            }
            from[sm]=m1;
        } while(next_permutation(all(have)));
    };
    if(n==27) find(13);
    else {
        for(int t=1;t<=n/2;++t) find(t);
    }
    nope();

}