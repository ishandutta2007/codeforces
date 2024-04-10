#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, p[N], sz[N], chk[N];
vector<int> e[N];

int q(char t, int x){
	printf("%c %d\n", t, x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

int sf(int x, int y){
	sz[x] = 1;
	for(int i : e[x]) if(i != y && !chk[i]) sz[x] += sf(i, x);
	return sz[x];
}

int cf(int x, int y, int t){
	for(int i : e[x]) if(i != y && !chk[i] && sz[i] > t / 2) return cf(i, x, t);
	return x;
}

void g(int x, int y, int targ, int cdst, int &fnd, int &dst){
	if(x == targ){
		fnd = 1;
		dst = cdst;
		return;
	}
	for(int i : e[x]) if(i != y && !chk[i]) g(i, x, targ, cdst + 1, fnd, dst);
}

int f(int x, int y, int z){
	if(!z){ printf("! %d\n", y); exit(0); }
	sf(x, 0);
	if(sz[x] <= 2){
		for(int i : e[y]) if(!chk[i]) printf("! %d\n", i);
		exit(0);
	}
	x = cf(x, 0, sz[x]);
	chk[x] = 1;
	if(y == x){
		if(x > 1){
			int nz = q('d', p[x]);
			if(z > nz) return f(p[x], p[x], nz);
		}
		int dir = q('s', x);
		return f(dir, dir, z - 1);
	}
	for(int i : e[x]){ if(chk[i]) continue;
		int fnd = 0, dst;
		g(i, x, y, 1, fnd, dst);
		if(fnd){
			if(i == p[x]){
				int nz = q('d', x);
				if(!nz){ printf("! %d\n", x); exit(0); }
				if(nz != z - dst) return f(p[x], p[x], nz - 1);
				int dir = q('s', x);
				return f(dir, dir, nz - 1);
			}
			else{
				if(x > 1){
					int nz = q('d', p[x]);
					if(z == dst && nz == 1){ printf("! %d\n", x); exit(0); }
					if(nz == z - dst - 1) return f(p[x], p[x], nz);
					int dir = q('s', x);
					return f(dir, dir, nz - 2);
				}
				else{
					int nz = q('d', x);
					if(!nz){ printf("! %d\n", x); exit(0); }
					int dir = q('s', x);
					return f(dir, dir, nz - 1);
				}
			}
		}
	}
}

void h(int x, int y){
	p[x] = y;
	for(int i : e[x]) if(i != y) h(i, x);
}

int main(){
	scanf("%d", &n);
	for(int i = 0, x, y; i < n - 1; i++){
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	h(1, 0);
	int d = q('d', 1);
	if(!d){ puts("! 1"); return 0; }
	printf("! %d\n", f(1, 1, d));
	return 0;
}