#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define x first
#define y second

const int N = 300005;

int n, m, k, r, a[N];
set<pii> s;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int x, y; m--; ){
		scanf("%d%d", &x, &y);
		s.insert(pii(x, y));
	}
	k = a[n];
	for(int i = n - 1; i >= 1; i--){
		for(int j = i; j < n; j++){
			if(s.count(pii(a[j], a[j + 1]))) swap(a[j], a[j + 1]);
			else break;
		}
	}
	for(int i = 1; i <= n; i++) if(a[i] == k) r = n - i;
	printf("%d\n", r);
}