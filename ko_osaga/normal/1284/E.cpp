#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
const int MAXN = 2505;
using lint = long long;
using pi = pair<int, int>;

int n; 
pi a[MAXN];

lint bino(int x, int y){
	lint ret = 1;
	for(int i=0; i<y; i++){
		ret *= x - i;
		ret /= i + 1;
	}
	return ret;
}

lint ccw(pi a, pi b){
	return 1ll * a.first * b.second - 1ll * b.first * a.second;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d %d",&a[i].first,&a[i].second);
	lint tot = 0;
	for(int i=0; i<n; i++){
		vector<pi> v;
		for(int j=0; j<n; j++){
			if(i != j){
				v.emplace_back(a[j].first - a[i].first, a[j].second - a[i].second);
			}
		}
		sort(all(v), [&](const pi &a, const pi &b){
			bool bh1 = a < pi(0, 0);
			bool bh2 = b < pi(0, 0);
			if(bh1 != bh2) return bh1 < bh2;
			return ccw(a, b) > 0;
		});
		int j = 0;
		for(int i=0; i<sz(v); i++){
			while(j < i + sz(v) && ccw(v[i], v[j % sz(v)]) >= 0) j++;
			tot += bino(j - i - 1, 3);
		}
	}
	cout << bino(n, 5) * 5 - tot << endl;
}