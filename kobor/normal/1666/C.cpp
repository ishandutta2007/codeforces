#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int)s.size()

#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>

const int INF = 1e9;

int main(){
	vii pkt(3);
	vi x;
	vi y;
	
	for(int i = 0; i < 3; i++){
		cin >> pkt[i].f >> pkt[i].s;
		y.pb(pkt[i].s);
		x.pb(pkt[i].f);
	}
	
	sort(all(pkt));
	sort(all(x));
	sort(all(y));
	vector<vi> ans;
	
	for(int i = 0; i < 3; i++){
		if(pkt[i].s != y[1])
			ans.pb({pkt[i].f, pkt[i].s, pkt[i].f, y[1]});
	}
	
	if(x[0] != x[2]){
		ans.pb({x[0], y[1], x[2], y[1]}); 
	}
	
	cout << sz(ans) << '\n';
	for(auto & u : ans){
		for(auto & v : u){
			cout << v << ' ';
		}
		cout<< '\n';
	}
}