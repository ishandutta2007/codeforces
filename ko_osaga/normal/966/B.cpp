#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
const int MAXN = 300005;

int n, x1, x2;
pi a[MAXN];

int fuck(int x, int y){ return (x + y - 1) / y; }

int main(){
	cin >> n >> x1 >> x2;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a+1, a+n+1);
	// x1 gets low
	for(int i=n; i; i--){
		int v = fuck(x1, a[i].first);
		if(v + i > n) continue;
		int w = fuck(x2, a[v + i].first);
		if(w + v + i - 1 > n) continue;
		printf("Yes\n%d %d\n", v, n + 1 - v - i);
		for(int j=i; j<v+i; j++) printf("%d ", a[j].second);
		puts("");
		for(int j=v+i; j<=n; j++) printf("%d ", a[j].second);
		return 0;
	}
	swap(x1, x2);
	for(int i=n; i; i--){
		int v = fuck(x1, a[i].first);
		if(v + i > n) continue;
		int w = fuck(x2, a[v + i].first);
		if(w + v + i - 1 > n) continue;
		printf("Yes\n%d %d\n", n+1-v-i, v);
		for(int j=v+i; j<=n; j++) printf("%d ", a[j].second);
		puts("");
		for(int j=i; j<v+i; j++) printf("%d ", a[j].second);
		return 0;
	}
	puts("No");
}