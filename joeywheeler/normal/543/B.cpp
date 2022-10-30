#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m, c, e[6005], k[6005], p[3005], d[3005][3005], r;
int s[2],t[2],l[2];

int q[3005], w, x;
void g(int i) {
	FO(j,1,n+1) d[i][j] = 1e6;
	d[i][i]=0;
	q[w=x=0]=i;
	while (w<=x) {
		int j=q[w++];
		for (int z = p[j]; ~z; z = k[z]) if (d[i][e[z]] > 1e5) {
			d[i][e[z]] = d[i][j]+1;
			q[++x] = e[z];
		}
	}
}

void h() {
	FO(i,1,n+1) FO(j,1,n+1) {
		int cr=d[i][j];
		FO(z,0,2) if (d[s[z]][i] + d[i][j] + d[j][t[z]] > l[z]) cr = 1e6;
		else cr += d[s[z]][i] + d[j][t[z]];
		r = min(r,cr);
	}
}

int main() {
	memset(p,-1,sizeof p);
	scanf("%d%d", &n, &m);
	FO(i,0,m) {
		int u,v; scanf("%d%d", &u, &v);
		k[c] = p[u]; e[c] = v; p[u] = c++;
		k[c] = p[v]; e[c] = u; p[v] = c++;
	}
	FO(i,1,n+1) g(i);
	FO(i,0,2) {
		scanf("%d%d%d", s+i, t+i, l+i);
		if (d[s[i]][t[i]] > l[i]) {
			puts("-1");
			return 0;
		}
		r += d[s[i]][t[i]];
	}
	h(); swap(s[0],t[0]); h();
	printf("%d\n", m-r);
}