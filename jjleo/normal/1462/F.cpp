#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

int t;
int n;
int l[maxn], r[maxn], mx[maxn];
vector<int> v;
int in[maxn], out[maxn], val[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		v.clear();
		for(int i = 1;i <= n;i++){
			scanf("%d%d", &l[i], &r[i]);
			v.push_back(l[i]), v.push_back(r[i]); 
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i = 1;i <= v.size();i++) in[i] = out[i] = val[i] = mx[i] = 0;
		for(int i = 1;i <= n;i++){
			in[l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1]++;
			out[r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin() + 1]++;
			mx[l[i]] = max(mx[l[i]], r[i]);
		}
		int sum = 0, ans = 0, r = 0;
		for(int i = 1;i <= v.size();i++){
			sum += in[i];
			r = max(r, mx[i]);
			ans = max(ans, sum);
			val[r] += out[i]; 
			sum -= val[i];
		}
		printf("%d\n", n - ans);
	}
}