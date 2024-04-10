//Author: HeXun
//Date: 08-25-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1200000;
LL ans[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, w;
	cin >> n >> w;
	for(int i = 1; i <= n; i += 1){
		int l;
		cin >> l;
		vector<pair<int, int>> v;
		for(int i = 1; i <= l; i += 1){
			int a;
			cin >> a;
			v.push_back({a, i});
		}
		sort(v.begin(), v.end(), greater<pair<int, int>>());
		set<pair<int, int>> s;
		for(auto p : v){
			int i = p.second, x = p.first;
			int L = i, R = w - (l - i);
			int xL = L, xR = R;
			auto it = s.lower_bound({L, R});
			if(it != s.end()) xR = min(xR, it->first - 1);
			if(it != s.begin()){
				it --;
				xL = max(it->second + 1, xL);
			}
			if(x < 0){
				xL = max(xL, w - l + 1);
				xR = min(xR, l);
			}
			if(xL <= xR){
				//cout << x << " " << L << " " << R << " " << xL << " " << xR << "\n";
				ans[xL] += x;
				ans[xR + 1] -= x;
			}
			s.insert({L, R});
		}
	}
	for(int i = 1; i <= w; i += 1){
		ans[i] += ans[i - 1];
		cout << ans[i] << " ";
	}
	return 0;
}