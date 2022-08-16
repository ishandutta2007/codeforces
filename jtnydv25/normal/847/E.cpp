#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], p[N], lst[N], nxt[N];
char c[N];
bool done[N];
int cnt, cnt1;
const int INF = 1e9;
int main(){
	int n, t;
	scanf("%d", &n);
	scanf("%s", c + 1);
	int x = 0;
	for(int i = 1; i <= n; i++){
		if(c[i] == '*'){
			a[i] = 1;
			cnt1++;
		}
		else if(c[i] == 'P'){
			p[i] = 1;
			lst[i] = x;
			x = i;
		}
	}

	x = n + 1;
	int LAST;
	for(int i = n; i >= 0; i--){
		nxt[i] = x;
		if(c[i] == '*') {
			if(x == n + 1) LAST = i;
			x = i;
		}
	}
	if(cnt1 == 0){
		cout << 0;
		return 0;
	}
	int lo = 1, hi = 2 * n;
	while(lo < hi){
		t = (lo + hi) >> 1;
		memset(done, 0, sizeof done);
		int present = nxt[0];
		bool fail = 0;
		for(int i = 1; i <= n; i++){
			if(!p[i]){
				continue;
			}
			if(present > n) break;
			
			if(i + t >= n && present >= i){
				present = n + 1;
				break;
			}
			if(present >= i){
				present = nxt[i + t];
			}
			else{
				if(min(2 * (n - i) + i - present, 2 * (i - present) + n - i) <= t){
					present = n + 1;
					break;
				}

				if(i - present > t){
					fail = 1;
					break;	
				}

				int x = i - present;
				present = nxt[i];
				if(t - 2 * x >= 0) present = max(present, nxt[i + t - 2 * x]);
				present = max(present, nxt[i + (t - x) / 2]);
			}
		}
		// cerr << t << " " << present << endl;
		if(present <= LAST) fail = 1;
		if(!fail){
			hi = t;
		}
		else lo = t + 1;
	}
	printf("%d\n", hi);	
}