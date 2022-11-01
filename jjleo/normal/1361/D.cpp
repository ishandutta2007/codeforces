#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int n, k;
int cnt;
map<pair<int, int>, int> mp;
vector<int> v[maxn];
int x[maxn], y[maxn];
int mx;

double val[maxn], ans;
priority_queue<double> q;

inline bool cmp(int i, int j){
	return abs(x[i]) ^ abs(x[j]) ? abs(x[i]) < abs(x[j]) : abs(y[i]) < abs(y[j]);//debug:x x=0 
}

inline double dist(int i){
	return sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]);
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &x[i], &y[i]);
		if(x[i] == 0 && y[i] == 0) continue;
		int gcd = abs(__gcd(x[i], y[i]));
		pair<int, int> p = {x[i] / gcd, y[i] / gcd};
		int id = mp[p];
		if(!id) id = mp[p] = ++cnt;
		v[id].push_back(i);
	}
	for(int i = 1;i <= cnt;i++){
		sort(v[i].begin(), v[i].end(), cmp);
		for(int j = 0;j < v[i].size();j++){
			val[v[i][j]] = dist(v[i][j]) * (k - 1 - ((int)v[i].size() - j - 1) * 2);
			//printf("%d %lf--\n", v[i][j], val[v[i][j]]);
		}
		if(v[i].size() > k / 2) mx = i;
		//printf("%d %d--\n", i, v[i].size()); 
	}
	int m = 0;
	for(int i = 1;i <= n;i++) if(val[i] > 0) q.push(val[i]);
	while(!q.empty() && m < k) ans += q.top(), q.pop(), m++;
	if(m < k){
		m++;
		for(int i = k - m - 1;i >= 0;i--){
			//printf("%d--\n", i);
			ans += dist(v[mx][i]) * (k - 1 - (k / 2 + k - m - 1 - i) * 2);//debug  
		}
	}
	printf("%.10lf", ans);
	
}