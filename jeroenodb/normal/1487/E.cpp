#pragma GCC optimize "Ofast"
// #pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
const int mxN = 1.5e5+1, oo = 1e9;
const int lograd= 16,radix = (1<<lograd)-1, secondrad = int(1e9) >> lograd;
int counts[radix+1];
pi b[mxN];
void fastsort(vector<pi>& a) {
	fill(counts, counts+radix+1 ,0);
    int n = a.size();
	for(int i=0;i<n;++i) {
		counts[a[i].first&radix]++;
	}
	for(int i=1;i<radix+1;++i) {
		counts[i]+=counts[i-1];
	}
	for(int i=n-1;i>=0;--i) {
		b[--counts[a[i].first&radix]] = a[i];
	}
	fill(counts,counts+secondrad+1 ,0);
	for(int i=0;i<n;++i) {
		counts[a[i].first>>lograd]++;
	}
    for(int i=1;i<secondrad+1;++i) {
		counts[i]+=counts[i-1];
	}
	for(int i=n-1;i>=0;--i) {
		a[--counts[b[i].first>>lograd]] = b[i];
	}
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n[4];
    for(int i=0;i<4;++i) scanf("%d",&n[i]);
    vector<pi> a[4];
    for(int i=0;i<4;++i) {
        a[i].resize(n[i]);
        for(int j=0;j<n[i];++j) {
            auto& c = a[i][j];
            scanf("%d",&c.first);
            c.second = j;
        }
    }
    int m[3];
    vvi adj[3];
    for(int i=0;i<3;++i) {
        scanf("%d",&m[i]);
        adj[i].resize(n[i]);
        while(m[i]--) {
            int u,v; scanf("%d%d",&u,&v);
            --u,--v;
            adj[i][u].push_back(v);
        }
    }
    for(int iter=0;iter<3;++iter) {
        fastsort(a[iter]);
        vi get(n[iter+1],0);
        int rank = 1;
        for(auto& [cost,id]: a[iter]) {
            for(int to: adj[iter][id]) {
                if(get[to]==rank-1) {
                    get[to]++;
                }
            }
            rank++;
        }
        for(int i=0;i<n[iter+1];++i) {
            if(get[i]==n[iter]) {
                a[iter+1][i].first = oo;
            } else {
                a[iter+1][i].first += a[iter][get[i]].first;
                if(a[iter+1][i].first>oo) a[iter+1][i].first = oo;
            }
        }
    }
    int best =oo;
    for(auto [cost,id]: a[3]) {
        best = min(best,cost);
    }
    cout << (best==oo?-1:best) << '\n';
    
}