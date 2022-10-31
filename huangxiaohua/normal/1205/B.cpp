#include <cstdio> 

using namespace std;

const int sz = 2000000, maxn = 130, inf = 70000000;

char buf[sz], *p1 = buf, *p2 = buf;
inline char gc() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,sz,stdin), p1==p2)?EOF:*p1++; }
inline long long read() {
    long long x = 0;
    int f = 1;
    char ch = gc();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = gc(); }
    while(ch >= '0' && ch <= '9') x = (x<<3)+(x<<1)+(ch&15), ch = gc();
    return x *= f;
}

inline int min(int a, int b) { return a < b ? a : b; }

long long a[maxn];
int f[maxn][maxn], m[maxn][maxn];

int main() {
	int n = (int)read();
	int ans = inf;
	for(int i = 1; i <= n; i++) {
		if(i >= 128) break;
		a[i] = read();
		if(!a[i]) {
			n--; i--;	
		}
	}
	if(n >= 128) {
		printf("3\n");
		return 0;	
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if((a[i] & a[j]) && (i != j))
				f[i][j] = m[i][j] = 1;
			else
				f[i][j] = m[i][j] = inf;
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) {
				if(i == j || j == k || k == i) continue;
				ans = min(ans, f[i][j]+m[i][k]+m[k][j]);
			}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(f[i][j] > f[i][k] + f[k][j])
					f[i][j] = f[i][k] + f[k][j];
	}
	printf("%d\n", ans==inf?-1:ans);	
	return 0;	
}