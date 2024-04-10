#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pii> d{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	int qq;
	cin >> qq;
	while(qq --){
		int n;
		cin >> n;
		pii rangex{-1e5, 1e5}, rangey{-1e5, 1e5};
		for(int i = 0; i < n; i ++){
			int x, y;
			cin >> x >> y;
			int f;
			cin >> f;
			if(!f){
				rangex.first = max(rangex.first, x);
			}
			cin >> f;
			if(!f){
				rangey.second = min(rangey.second, y);
			}
			cin >> f;
			if(!f){
				rangex.second = min(rangex.second, x);
			}
			cin >> f;
			if(!f){
				rangey.first = max(rangey.first, y);
			}
		}
		if(rangex.first <= rangex.second && rangey.first <= rangey.second){
			cout << "1 " << rangex.first << " " << rangey.first << "\n";
		}
		else{
			cout << "0\n";
		}
	}
	return 0;
}