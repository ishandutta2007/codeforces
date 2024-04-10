#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> cntx(51), cnty(51);
	vector<pii> p;
	int nc = 4 * n + 1;
	while(nc --){
		int x, y;
		cin >> x >> y;
		p.push_back({x, y});
		cntx[x] ++, cnty[y] ++;
	}
	int l, r, u, d;
	for(int x = 0; x <= 50; x ++){
		if(cntx[x] >= n){
			l = x;
			break;
		}
	}
	for(int x = 50; x >= 0; x --){
		if(cntx[x] >= n){
			r = x;
			break;
		}
	}
	for(int y = 0; y <= 50; y ++){
		if(cnty[y] >= n){
			u = y;
			break;
		}
	}
	for(int y = 50; y >= 0; y --){
		if(cnty[y] >= n){
			d = y;
			break;
		}
	}
	for(auto x: p){
		if(x.first != l && x.first != r && x.second != u && x.second != d || x.first < l || x.first > r || x.second < u || x.second > d){
			cout << x.first << " " << x.second << "\n";
			break;
		}
	}
	return 0;
}