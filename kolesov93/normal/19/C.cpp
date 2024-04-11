#include <stdio.h>
#include <algorithm>
#include <queue>
#include <math.h>
#include <map>
#include <deque>
#include <string>
#include <string.h>
#define N 111111
std::map<int,int> q;
struct cell {
	int len,kol;
} w[N][11];
struct ev {
	int b,e;
	
	bool operator <(const ev& A) const {
		return e-b<A.e-A.b || (e-b==A.e-A.b && b<A.b);
	}
} b[N];
int m,next[N],a[N],n,var[N];


int main(void) {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for (int i=n;i;i--) {
		int res = q[a[i]];
		next[i] = res;
		q[a[i]] = i;
		if (res == 0) {
			
			continue;
		}
		
		int j = 0;
		while (res) {
			w[i][++j].len = res - i;
			w[i][j].kol = 1;
			res = next[res];
		}
		var[i] = j;
		
		j = 1;
		bool flag = 0;
		for (int k=1;k<=var[i+1];k++) {
			while (j<=var[i] && w[i][j].len < w[i+1][k].len) j++;
			if (j>var[i]) break;
			if (w[i][j].len == w[i+1][k].len) w[i][j].kol = w[i+1][k].kol+1;
		}
		
		for (int k=1;k<=var[i];k++)
			if (!flag && w[i][k].kol >= w[i][k].len) {
				flag = 1;
				b[m++] = (ev) {i,i+w[i][k].len-1};
			}
	}
	std::sort(b,b+m);
	
	int good = 1;
	for (int i=0;i<m;i++) 
		if (b[i].b >= good) good = b[i].e+1;
	
	printf("%d\n",n-good+1);
	for (int i=good;i<=n;i++)
		if (i != n) printf("%d ",a[i]);
		else printf("%d\n",a[i]);
			
	return 0;
}