#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define rep(a,b,c) for(int a=b;a<c;a++)
// [0,L) , N-1 is virtual , 1 is rt , init!!

const int N = 205;
const ll inf = (1ll<<60);
char str[N];
ll l;
int n, a[N];

struct Trie{
    static const int N = 205 , M = 26;
    int ne[N][M] , fail[N] , fa[N] , rt , L, val[N];
    void ini(){ fill_n(ne[fail[0] = N-1],M,0);L = 0;rt = newnode();}
    int newnode(){ fill_n(ne[L],M,0); return L++; }
    void add(char *s, int id){
        int p = rt;
        for(int i=0;s[i];++i){
            int c = s[i] - 'a';// modify
            if(!ne[p][c]) ne[p][c] = newnode() , fa[L-1] = p;
            p = ne[p][c];
        }
        val[p] += a[id];
    }
    void Build(){
        vi v;v.pb(rt);
        rep(i,0,sz(v)){
			int c = v[i];
			rep(i,0,M) {
				ne[c][i] ?
					v.pb(ne[c][i]) , fail[ne[c][i]] = ne[fail[c]][i], val[ne[c][i]] += val[fail[ne[c][i]]] :
					ne[c][i] = ne[fail[c]][i];
			}
		}
	}
} gao;

struct Mat {
	ll v[N][N];
	Mat() {
		for (int i = 0; i < gao.L; i++)
			for (int j = 0; j < gao.L; j++)
				v[i][j] = -inf;
	}
	Mat operator * (const Mat& c) const {
		Mat ans;
		for (int i = 0; i < gao.L; i++) {
			for (int j = 0; j < gao.L; j++) {
				for (int k = 0; k < gao.L; k++) {
					if (v[i][k] != -inf && c.v[k][j] != -inf)
						ans.v[i][j] = max(ans.v[i][j], v[i][k] + c.v[k][j]);
				}
			}
		}
		return ans;
	}
};

Mat pow_mod(Mat x, ll k) {
	Mat ans;
	for (int i = 0; i < gao.L; i++) ans.v[i][i] = 0;
	while (k) {
		if (k&1) ans = ans * x;
		x = x * x;
		k >>= 1;
	}
	return ans;
}

int main() {
	scanf("%d%lld", &n, &l);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	gao.ini();
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		gao.add(str, i);
	}
	gao.Build();
	Mat A;
	for (int i = 0; i < gao.L; i++) {
		for (int j = 0; j < gao.L; j++) A.v[i][j] = -inf;
		for (int j = 0; j < 26; j++) {
			int v = gao.ne[i][j];
			A.v[i][v] = max(A.v[i][v], 1ll * gao.val[v]);
		}
	}
	A = pow_mod(A, l);
	ll ans = 0;
	for (int i = 0; i < gao.L; i++) ans = max(ans, A.v[0][i]);
	printf("%lld\n", ans);
	return 0;
}