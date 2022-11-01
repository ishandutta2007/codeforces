#include <cstdio>
#include <vector>

using namespace std;

int n;
vector < int > veze[100005];
int vl[100005];

vector < int > out;
int dfs(int p, int b1, int b2, int par){
	int cr = vl[p] ^ b1;
	int r = 0;
	if (cr == 0){swap(b1, b2);} else {swap(b1, b2); b2 ^= 1; ++r; out.push_back(p);}
	for (int i = 0; i < veze[p].size(); ++i) if (veze[p][i] != par) r += dfs(veze[p][i], b1, b2, p);
	return r;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i){int a, b; scanf("%d%d", &a, &b); veze[a].push_back(b); veze[b].push_back(a);}
	for (int i = 1; i <= n; ++i){int a; scanf("%d", &a); vl[i] ^= a;}
	for (int i = 1; i <= n; ++i){int a; scanf("%d", &a); vl[i] ^= a;}
	printf("%d\n", dfs(1, 0, 0, -1));
	for (int i = 0; i < out.size(); ++i) printf("%d\n", out[i]);
	return 0;
}