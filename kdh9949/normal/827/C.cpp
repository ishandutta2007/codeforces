#include <bits/stdc++.h>
using namespace std;

char str[100010];
int n, q, num[256];

const int sz = 131072;
struct Seg{
	int dat[4][11][10][2 * sz];
	void upd(int t, int x, int v){
		int fx = x;
		for(x += sz; x; x /= 2){
			for(int i = 1; i <= 10; i++){
				dat[t][i][fx % i][x] += v;
			}
		}
	}
	int get(int t, int l, int m, int s, int e){
		int ret = 0;
		for(s += sz, e += sz; s <= e; s /= 2, e /= 2){
			if(s % 2 == 1) ret += dat[t][l][m][s++];
			if(e % 2 == 0) ret += dat[t][l][m][e--];
		}
		return ret;
	}
} S;

int main(){
	scanf("%s%d", str + 1, &q);
	n = strlen(str + 1);
	num['A'] = 0; num['C'] = 1; num['G'] = 2; num['T'] = 3;
	for(int i = 1; i <= n; i++) S.upd(num[str[i]], i, 1);
	for(int t, x, y; q--; ){
		char buf[12];
		scanf("%d", &t);
		if(t == 1){
			scanf("%d%s", &x, buf);
			S.upd(num[str[x]], x, -1);
			str[x] = buf[0];
			S.upd(num[str[x]], x, 1);
		}
		else{
			scanf("%d%d%s", &x, &y, buf);
			int l = strlen(buf);
			int ret = 0;
			for(int i = 0; i < l; i++) ret += S.get(num[buf[i]], l, (x + i) % l, x, y); 
			printf("%d\n", ret);
		}
	}
}