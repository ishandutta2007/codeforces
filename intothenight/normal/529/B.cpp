#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pii> p(n);
	int MIN = 0, MAX = 0;
	for(auto &x: p){
		cin >> x.first >> x.second;
		MIN = max(MIN, min(x.first, x.second));
		MAX = max({MAX, x.first, x.second});
	}
	sort(p.begin(), p.end(), [](pii X, pii Y){
		return abs(X.first - X.second) > abs(Y.first - Y.second);
	});
	int res = 1e9;
	for(int h = MIN; h <= MAX; h ++){
		vector<pii> v;
		int k = n / 2, w = 0;
		bool failed = false;
		for(int i = 0; i < n; i ++){
			if(p[i].second > h){
				if(!k){
					failed = true;
					break;
				}
				k --;
				w += p[i].second;
			}
			else if(p[i].first <= h){
				v.push_back(p[i]);
			}
			else{
				w += p[i].first;
			}
		}
		if(failed){
			continue;
		}
		for(int i = 0; i < v.size(); i ++){
			if(k){
				if(v[i].first > v[i].second){
					k --;
					w += v[i].second;
				}
				else{
					w += v[i].first;
				}
			}
			else{
				w += v[i].first;
			}
		}
		res = min(res, h * w);
	}
	cout << res;
	return 0;
}