#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + m);
		vector<int> v;
		a[m + 1] = a[1] + n;
		for(int i = 1;i <= m;i++){
			if(a[i] + 1 < a[i + 1]) v.push_back(a[i + 1] - a[i] - 1);
		}
		int ans = m;
		sort(v.begin(), v.end(), greater<int>());
		int x = 0;
		for(int i = 0;i < v.size();i++){
			if(x * 2 >= v[i]) ans += v[i];
			else if(x * 2 + 1 == v[i]) ans += x * 2, x++;
			else if(x * 2 + 2 == v[i]) ans += x * 2 + 1, x++;
			else ans += x * 2 + 1, x += 2;
		}
		printf("%d\n", ans);
	}
}