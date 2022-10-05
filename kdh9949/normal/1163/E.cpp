#include <bits/stdc++.h>
using namespace std;

const int N = 200005, L = 20;

int n, a[N], b[L], c;

int ins(int x){
	for(int i = 0; i < c; i++){
		int bc = __builtin_clz(b[i]), xc = __builtin_clz(x);
		if(bc > xc) break;
		else if(bc < xc) continue;
		else x ^= b[i];
		if(!x) return 0;
	}
	for(int i = 0; i <= c; i++){
		if(b[i] > x) continue;
		for(int j = c; j > i; j--) b[j] = b[j - 1];
		b[i] = x;
		break;
	}
	c++;
	return 1;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	for(int t = L; t; t--){
		vector<int> v;
		memset(b, 0, sizeof(b));
		c = 0;
		for(int i = 0; i < n; i++){
			if(a[i] >= (1 << t)) break;
			if(ins(a[i])) v.push_back(a[i]);
		}
		if(v.size() == t){
			printf("%d\n0 ", t);
			int c = 0;
			for(int i = 1; i < (1 << t); i++){
				c ^= v[__builtin_ctz(i & -i)];
				printf("%d ", c);
			}
			puts("");
			return 0;
		}
	}
	puts("0\n0");
}