#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, d, m;
vector<long long> v[2];
int x;
long long ans;

int main(){
	scanf("%d%d%d", &n, &d, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		v[x > m].push_back(x);
	}
	sort(v[0].begin(), v[0].end()), sort(v[1].begin(), v[1].end());
	reverse(v[0].begin(), v[0].end()), reverse(v[1].begin(), v[1].end());
	for(int i = 1;i < v[0].size();i++) v[0][i] += v[0][i - 1];
	for(int i = 1;i < v[1].size();i++) v[1][i] += v[1][i - 1];
	if(v[1].size()) ans = v[1][min(n / (d + 1) + (n % (d + 1) != 0), (int)v[1].size()) - 1];
	for(int i = 1;i <= v[0].size();i++){
		long long sum = v[0][i - 1];
		if(v[1].size()) sum += v[1][min((n - i) / (d + 1) + ((n - i) % (d + 1) != 0), (int)v[1].size()) - 1];
		ans = max(ans, sum);
	}
	printf("%lld", ans);
}