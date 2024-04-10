// Hydro submission #62c672b28672efa577bf9b5b@1657172658420
#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace IO{
	template <typename T> inline void write(T x) {
	    if(x < 0)
	        putchar('-') , x = - x;
	    if(x == 0) {
	        putchar('0') ;
	        return ;
	    }
	    if(x > 9) write(x / 10);
	    putchar(x % 10 + '0');
	    return ;
	}
	template <typename T> inline void read(T &x) {
	    x = 0; int w = 1; char ch = getchar();
	    while (!isdigit(ch)) { if (ch == '-') w = -1; ch = getchar(); }
	    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48) , ch = getchar();
	    x *= w;
	    return ;
	}
}
#define writeln(x) write(x) , putchar('\n')
#define writesp(x) write(x) , putchar(' ')
using namespace IO;
#define For(i, j, k) for(int i = (j); i <= (k); ++i)
#define Dec(i, j, k) for(int i = (j); i >= (k); --i)
#define mp make_pair
#define pii pair<int, int> 
#define ppi pair<pii, int>
#define ckmax(a, b) ((a) = max((a), (b)))
#define ckmin(a, b) ((a) = min((a), (b)))
#define pb emplace_back
#define inf 0x3f3f3f3f
#define fi first
#define se second
#define N 101
#define M 10001
#define mod 998244353

int n, t[N][N], cnt, ans[M][N];

int check() {
	For(i, 1, n) 
		For(j, 1, n)
			if(t[i][j] > 1) return i;
	return 0;
}


signed main() {
	read(n) ;
	For(i, 1, n)
		for(int x, j = 1; j <= n; j++)
			read(x) , t[i][x]++ ;
	while(1) {
		int k = check();
		if(!k) break ;
		int las = 0; cnt++;
		For(i, 1, n)
			if(t[k][i] > 1) { 
				t[k][i]--, ans[cnt][k] = las = i;
				break;
			}
		for(int i = k % n + 1; i != k; i = i % n + 1) {
			bool flag = 0;
			For(j, 1, n)
				if(t[i][j] > 1) {
					flag = 1; t[i][las]++; t[i][j]--; ans[cnt][i] = las = j;
					break;
				}
			if (!flag) ans[cnt][i] = las;
		}
		t[k][las]++;
	}
	For(i, 2, n) {
		For(j, 1, i - 1) {
			cnt++;
			For(k, 1, n) {
				int tmp = (k + i - j + n) % n ? (k + i - j + n) % n : n;
				ans[cnt][k] = tmp, t[k][tmp]--, t[k % n + 1][tmp]++;
			}
		}	
	}
	writeln(cnt);
	For(i, 1, cnt) {
		For(j, 1, n - 1)
			writesp(ans[i][j]);
		writeln(ans[i][n]);		
	}
	return 0 ;
}