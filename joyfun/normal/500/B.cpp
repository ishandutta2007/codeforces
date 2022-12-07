#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 305;

int n, a[N], g[N][N], vis[N];
char str[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 	for (int i = 0; i < n; i++) {
  		scanf("%s", str);
  		for (int j = 0; j < n; j++)
  			g[i][j] = str[j] - '0';
		g[i][i] = 1;
  	}
  	for (int k = 0; k < n; k++) {
  		for (int i = 0; i < n; i++) {
  			for (int j = 0; j < n; j++) {
  				g[i][j] |= (g[i][k]&g[k][j]);
     		}
    	}
   	}
   	for (int i = 0; i < n; i++) {
   		int Min = n;
  		for (int j = 0; j < n; j++) {
  			if (g[j][i] && !vis[a[j]]) {
  				Min = min(Min, a[j]);
     		}
    	}
    	vis[Min] = 1;
    	printf("%d ", Min);
   	}
	return 0;
}