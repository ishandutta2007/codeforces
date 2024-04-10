#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(15);
	int n, m;
	cin >> n >> m;
	vector<pii> a(n), b(m);
	for(auto &x: a){
		cin >> x.first >> x.second;
	}
	for(auto &x: b){
		cin >> x.first >> x.second;
	}
	auto match = [](pii x, pii y){
		if(x.first == y.first && x.second != y.second){
			return x.first;
		}
		if(x.first != y.first && x.second == y.second){
			return x.second;
		}
		if(x.first == y.second && x.second != y.first){
			return x.first;
		}
		if(x.first != y.second && x.second == y.first){
			return x.second;
		}
		return 0;
	};
	int res;
	set<int> pos;
	vector<set<int>> fqa(n), fqb(m);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			pii x(a[i]), y(b[j]);
			if(match(x, y)){
				res = match(x, y);
				fqa[i].insert(res), fqb[j].insert(res);
				pos.insert(res);
			}
		}
	}
	if(pos.size() == 1){
		cout << *pos.begin();
	}
	else if(all_of(fqa.begin(), fqa.end(), [](set<int> &x){return x.size() <= 1;}) && all_of(fqb.begin(), fqb.end(), [](set<int> &x){return x.size() <= 1;})){
		cout << 0;
	}
	else{
		cout << -1;
	}
	return 0;
}