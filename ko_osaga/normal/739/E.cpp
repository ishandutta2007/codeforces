#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int MAXN = 2005;

int n, p, q;
double a[MAXN], b[MAXN];

pair<double, int> trial(double K){
	vector<pair<double, int>> v;
	double ret = 0;
	int cnt = 0;
	for(int i=1; i<=n; i++){
		pair<double, int> ans1 = min(make_pair(1.0, 0), make_pair(b[i] + K, 1));
		pair<double, int> ans2 = min(make_pair(a[i],0), make_pair(a[i] * b[i] + K, 1));
		ret += ans1.first;
		cnt += ans1.second;
		v.push_back(make_pair(ans2.first - ans1.first, ans2.second - ans1.second));
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size() && i<p; i++){
		if(v[i].first >= 0) break;
		ret += v[i].first;
		cnt += v[i].second;
	}
	return make_pair(ret, cnt);
}

int main(){
	scanf("%d %d %d",&n,&p,&q);
	for(int i=1; i<=n; i++) cin >> a[i], a[i] = 1 - a[i];
	for(int i=1; i<=n; i++) cin >> b[i], b[i] = 1 - b[i];
	double s = -10, e = 10;
	for(int i=0; i<80; i++){
		double m = (s+e)/2;
		if(trial(m).second <= q) e = m;
		else s = m;
	}
	printf("%.10f\n",n - (trial(s).first - q * s));
}