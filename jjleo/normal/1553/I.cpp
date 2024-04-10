#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

const int p = 998244353, G = 3, invG = 332748118, inv2 = p + 1 >> 1;

inline int fpow(int x, int y){
    int ans = 1;
    while(y){
        if(y & 1) ans = 1ll * ans * x % p;
        x = 1ll * x * x % p, y >>= 1;
    }
    return ans;
}

int add(int x, int y){ x += y; return x >= p ? x - p : x; }
int sub(int x, int y){ x -= y; return x < 0 ? x + p : x; }
int mul(int x, int y){ return 1ll * x * y % p; }
int prt[2][30];
void init(){
    for(int i = 1, j = 2;i <= 23;i++, j <<= 1) prt[0][i] = fpow(G, (p - 1) / j);
    for(int i = 1, j = 2;i <= 23;i++, j <<= 1) prt[1][i] = fpow(invG, (p - 1) / j);
}

#define Poly vector<int>
#define len(x) ((int)x.size())

int pos[maxn];
void NTT(Poly &a, int lim, int type){
    for(int i = 0;i < lim;i++) if(i < pos[i]) swap(a[i], a[pos[i]]);
    for(int mid = 1, pw = 1;mid < lim;mid <<= 1, pw++){
        int wn = prt[type == -1][pw];
        for(int i = mid << 1, j = 0;j < lim;j += i){
            for(int k = 0, w = 1;k < mid;k++, w = mul(w, wn)){
                int x = a[j + k], y = mul(w, a[j + k + mid]);
                a[j + k] = add(x, y), a[j + k + mid] = sub(x, y);
            }
        }
    }
    if(type == -1){
        int invlim = fpow(lim, p - 2);
        for(int i = 0;i < lim;i++) a[i] = mul(a[i], invlim);
    }
}

int n, x, m, len[maxn];

struct Node{
	vector<int> a[2][2];
};

Node solve(int l, int r){
	if(l == r){
		if(len[l] == 1) return (Node){vector<int>{0, 1}, vector<int>(2), vector<int>(2), vector<int>(2)};
		return (Node){vector<int>(2), vector<int>(2), vector<int>(2), vector<int>{0, 2}};
	}
	if(l + 1 == r){
		Node x;
		for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) x.a[i][j].resize(3);
		x.a[len[l] > 1][len[r] > 1][2] = (1 + (len[l] > 1)) * (1 + (len[r] > 1));
		x.a[1][1][1] = 2;
		return x;
	}
	if(l + 2 == r){
		Node x;
		for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) x.a[i][j].resize(4);
		x.a[len[l] > 1][len[r] > 1][3] = (1 + (len[l] > 1)) * (1 + (len[l + 1] > 1)) * (1 + (len[r] > 1));
		x.a[len[l] > 1][1][2] += 2 * (1 + (len[l] > 1));
		x.a[1][len[r] > 1][2] += 2 * (1 + (len[r] > 1));
		x.a[1][1][1] = 2;
		return x;
	}
	int mid = l + r >> 1;
	Node L = solve(l, mid), R = solve(mid + 1, r), x, y;
	int lim = 1;
	while(lim <= r - l + 1) lim <<= 1;
	for(int i = 0;i < lim;i++) pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? lim >> 1 : 0);
	for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++){
		L.a[i][j].resize(lim), R.a[i][j].resize(lim);
		x.a[i][j].resize(lim), y.a[i][j].resize(lim);
		NTT(L.a[i][j], lim, 1), NTT(R.a[i][j], lim, 1);
	}
	for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) for(int ii = 0;ii < 2;ii++) for(int jj = 0;jj < 2;jj++){
		for(int k = 0;k < lim;k++){
			x.a[i][jj][k] = (x.a[i][jj][k] + 1ll * L.a[i][j][k] * R.a[ii][jj][k]) % p;
			y.a[i][jj][k] = (y.a[i][jj][k] + 1ll * L.a[i][j][k] * R.a[ii][jj][k] % p * (j && ii ? inv2 : !j && !ii ? 2 : 1)) % p;
		}
	}
	for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++){
		NTT(x.a[i][j], lim, -1), NTT(y.a[i][j], lim, -1);
		for(int k = 0;k + 1 < lim;k++) x.a[i][j][k] = (x.a[i][j][k] + y.a[i][j][k + 1]) % p;
	}
	for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) x.a[i][j].resize(r - l + 2);
	/*for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++){
		printf("%d %d %d %d:", l, r, i, j);
		for(int k = 0;k <= r - l + 1;k++) printf("%d,%d ", x.a[i][j][k], y.a[i][j][k]);puts("");
	}*/
	return x;
}

int main(){
	scanf("%d", &n);
	int last = 0, cnt = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(x ^ last){
			if(last){
				if(cnt % last) return printf("0"), 0;
				for(int j = 1;j <= cnt / last;j++) len[++m] = last;
			}
			last = x, cnt = 0;
		}
		cnt++;
	}
	if(cnt % last) return printf("0"), 0;
	for(int j = 1;j <= cnt / last;j++) len[++m] = last;
	init();
	Node x = solve(1, m);
	int ans = 0;
	for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) for(int k = 1, sum = 1;k <= m;k++, sum = 1ll * sum * k % p){
		if((m - k) & 1) ans = (ans + p - 1ll * x.a[i][j][k] * sum % p) % p;
		else ans = (ans + 1ll * x.a[i][j][k] * sum) % p;
	}
	printf("%d", ans);
}