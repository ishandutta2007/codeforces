#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, w[N], h[N], x[2], y[2];

int ask(int a, int b, int c, int d){
	printf("? %d %d %d %d\n", a, b, c, d);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x & 1;
}

void ans(int a, int b, int c, int d){
	printf("! %d %d %d %d\n", a, b, c, d);
	fflush(stdout);
	exit(0);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++) w[i] = ask(1, 1, n, i);
	for(int i = 1; i < n; i++) h[i] = ask(1, 1, i, n);
	for(int i = 1; i <= n; i++){
		if(w[i] && !w[i - 1]) y[0] = i;
		if(!w[i] && w[i - 1]) y[1] = i;
		if(h[i] && !h[i - 1]) x[0] = i;
		if(!h[i] && h[i - 1]) x[1] = i;
	}
	if(!x[0]){
		int s = 1, e = n;
		while(s < e){
			int m = (s + e) / 2;
			if(ask(s, y[0], m, y[0])) e = m;
			else s = m + 1;
		}
		ans(s, y[0], s, y[1]);
	}
	else if(!y[0]){
		int s = 1, e = n;
		while(s < e){
			int m = (s + e) / 2;
			if(ask(x[0], s, x[0], m)) e = m;
			else s = m + 1;
		}
		ans(x[0], s, x[1], s);
	}
	else{
		vector<int> v;
		for(int i = 0; i < 4; i++){
			int cx = x[i & 1], cy = y[(i >> 1) & 1];
			if(ask(cx, cy, cx, cy)){
				v.push_back(cx);
				v.push_back(cy);
			}
		}
		ans(v[0], v[1], v[2], v[3]);
	}
}