#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;
const int MAXN = 200005;
const int B = 400;
using lint = long long;
using pi = pair<lint, int>;

int n;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool find_sub(vector<int>&a, vector<int>&p){
	vector<pi> v;
	lint sum = 0;
	for(int i=0; i<n; i++){
		sum += a[p[i]];
		if(sum == 0){
			printf("%d\n", i + 1);
			for(int j=0; j<=i; j++) printf("%d ", p[j] + 1);
			return 1;
		}
		v.emplace_back(sum, i + 1);
	}
	sort(all(v));
	for(int i=1; i<sz(v); i++){
		if(v[i-1].first == v[i].first){
			printf("%d\n", v[i].second - v[i-1].second);
			for(int k=v[i-1].second; k<v[i].second; k++){
				printf("%d ", p[k] + 1);
			}
			return 1;
		}
	}
	return 0;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		vector<int> a(n);
		vector<int> p(n);
		iota(all(p), 0);
		for(int i=0; i<n; i++) scanf("%d",&a[i]);
		int pos = find(all(a), 0) - a.begin();
		if(pos != n){
			printf("1\n%d\n", pos + 1);
			continue;
		}
		vector<int> mark(n);
		bool good = 0;
		for(int i=0; i<n; i++){
			if(a[i] > 0) mark[a[i]] = i + 1;
			if(a[i] < 0 && mark[-a[i]]){
				puts("2");
				printf("%d %d\n", mark[-a[i]], i + 1);
				good = 1;
				break;
			}
		}
		if(good) continue;
		sort(all(p), [&](const int &x, const int &y){
			return a[x] < a[y];
		});
		if(find_sub(a, p)) continue;
		sort(all(p), [&](const int &x, const int &y){
			return abs(a[x]) > abs(a[y]);
		});
		if(find_sub(a, p)) continue;
		while(true){
			shuffle(all(p), rng);
			if(find_sub(a, p)) break;
		}
	}
}