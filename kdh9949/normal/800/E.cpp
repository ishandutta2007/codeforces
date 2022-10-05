#include <bits/stdc++.h>
using namespace std;

int n, r;
int lc[2010], rc[2010], p[2010], chk[2010], sz[2010];

int ask(int x, int y, int z){
	printf("%d %d %d\n", x, y, z);
	fflush(stdout);
	char buf[3];
	scanf("%s", buf);
	return buf[0] == 'X' ? 1 : buf[0] == 'Y' ? 2 : 3;
}

int av(int x){
	return x && !chk[x];
}

int cf(int x, int t){
	if(av(lc[x]) && sz[lc[x]] > t / 2) return cf(lc[x], t);
	if(av(rc[x]) && sz[rc[x]] > t / 2) return cf(rc[x], t);
	return x;
}

int sf(int x){
	sz[x] = 1;
	if(av(lc[x])) sz[x] += sf(lc[x]);
	if(av(rc[x])) sz[x] += sf(rc[x]);
	return sz[x];
}

int fnd(int x){
	if(x <= n) return x;
	if(lc[x]){
		int t = fnd(lc[x]);
		if(t > 0) return t;
	}
	if(rc[x]){
		int t = fnd(rc[x]);
		if(t > 0) return t;
	}
	return -1;
}

int main(){
	scanf("%d", &n);
	p[1] = p[2] = n + 1;
	lc[n + 1] = 1;
	rc[n + 1] = 2;
	r = n + 1;
	for(int i = 3; i <= n; i++){
		fill(chk + 1, chk + 2 * n, 0);
		int tr = r;
		while(true){
			int x = cf(tr, sf(tr));
			if(sz[tr] == 1){
				int nx = i + n - 1;
				if(tr == r){
					lc[nx] = tr;
					p[tr] = nx;
					rc[nx] = i;
					p[i] = nx;
					r = nx;
				}
				else{
					if(lc[p[tr]] == tr){
						lc[p[tr]] = nx;
						p[nx] = p[tr];
						p[tr] = nx;
						lc[nx] = tr;
						p[i] = nx;
						rc[nx] = i;
					}
					else{
						rc[p[tr]] = nx;
						p[nx] = p[tr];
						p[tr] = nx;
						rc[nx] = tr;
						p[i] = nx;
						lc[nx] = i;
					}
				}
				break;
			}
			int ret = ask(fnd(lc[x]), fnd(rc[x]), i);
			if(ret == 1){
				chk[lc[x]] = 1;
				chk[rc[x]] = 1;
			}
			else if(ret == 2){
				tr = rc[x];
			}
			else{
				tr = lc[x];
			}
		}
	}
	puts("-1");
	for(int i = 1; i < 2 * n; i++) printf("%d ", p[i] ? p[i] : -1);
	fflush(stdout);
}