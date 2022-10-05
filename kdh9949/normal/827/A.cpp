#include <bits/stdc++.h>
using namespace std;

set<int> ss;
int n, mx;
char tmp[1000010], str[2000010];

void upd(char *s, int x, int l){
	while(true){
		auto t = ss.lower_bound(x);
		if(*t >= x + l) break;
		mx = max(mx, *t);
		str[*t] = s[*t - x];
		ss.erase(t);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= 2000001; i++) ss.insert(i);
	for(int i = 0, t, m; i < n; i++){
		scanf("%s%d", tmp, &t);
		m = strlen(tmp);
		for(int x; t--; ){
			scanf("%d", &x);
			upd(tmp, x, m);
		}
	}
	for(int i = 1; i <= mx; i++) putchar(max('a', str[i]));
	puts("");
}