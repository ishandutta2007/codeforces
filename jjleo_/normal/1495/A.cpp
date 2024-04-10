#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int x, y;
vector<int> a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		a.clear(), b.clear();
		for(int i = 1;i <= 2 * n;i++){
			scanf("%d%d", &x, &y);
			if(x) a.push_back(abs(x));
			else b.push_back(abs(y));
		}
		sort(a.begin(), a.end()), sort(b.begin(), b.end());
		long double ans = 0;
		for(int i = 0;i < n;i++) ans += sqrt(1ll * a[i] * a[i] + 1ll * b[i] * b[i]);
		printf("%.15Lf\n", ans);
	}
}