#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n;
pi a[150005];

bool cmp(pi a, pi b){
	return 1ll * a.first * b.second > 1ll * b.first * a.second;
}

struct tp{
	int x;
	double mn, mx;
};

double mx[150005], mn[150005];

bool trial(double c){
	lint sum = 0;
	for(int i=0; i<n; i++) sum += a[i].second;
	lint cur = 0;
	for(int i=0; i<n; ){
		lint ncur = cur;
		int e = i;
		while(e < n && cmp(a[i], a[e]) == 0){
			ncur += a[e++].second;
		}
		for(int j=i; j<e; j++){
			mn[j] = a[j].first * (1 - (c * ncur) / sum);
			mx[j] = a[j].first * (1 - (c * (cur + a[j].second)) / sum);
		}
		i = e;
		cur = ncur;
	}
	vector<tp> v(n);
	for(int i=0; i<n; i++){
		v[i] = {a[i].first, mn[i], mx[i]};
	}
	sort(v.begin(), v.end(), [&](const tp &a, const tp &b){
		return a.x < b.x;
	});
	double cmx = -1e18;
	for(int i=0; i<n; ){
		int e = i;
		while(e < n && v[e].x == v[i].x) e++;
		for(int j=i; j<e; j++){
			if(cmx > v[j].mn){
				return 0;
			}
		}
		for(int j=i; j<e; j++){
			cmx = max(cmx, v[j].mx);
		}
		i = e;
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].first);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&a[i].second);
	}
	sort(a, a+n, cmp);
	double s = 0, e = 1;
	for(int i=0; i<30; i++){
		double m = (s+e)/2;
		if(trial(m)) s = m;
		else e = m;
	}
	printf("%.10f", s);
}