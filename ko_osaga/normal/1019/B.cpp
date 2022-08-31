#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 3005;

int main(){
	int n; cin >> n;
	auto query = [&](int x){
		if(x > n) x -= n;
		printf("? %d\n", x);
		fflush(stdout);
		int v; cin >> v;
		return v;
	};
	int l = query(1);
	int r = query(n / 2 + 1);
	if(l == r){
		printf("! 1\n");
		fflush(stdout);
		return 0;
	}
	int s = 1, e = n / 2 + 1;
	while(e - s >= 3){
		int m = (s+e)/2;
		int diff = query(m) - query(m + n/2);
		if(diff == 0){
			printf("! %d\n", m);
			fflush(stdout);
			return 0;
		}
		if(diff * (l - r) > 0) s = m;
		else e = m;
	}
	for(int i=s; i<=e; i++){
		if(query(i) == query(i + n / 2)){
			printf("! %d\n", i);
			fflush(stdout);
			return 0;
		}
	}
	puts("! -1");
	fflush(stdout);
}