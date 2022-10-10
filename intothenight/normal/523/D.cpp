#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<pll> d(n);
	set<tuple<ll, int, bool>> e;
	for(int i = 0; i < n; i ++){
		cin >> d[i].first >> d[i].second;
		e.insert({d[i].first, i, false});
	}
	int server = 0;
	deque<int> wait;
	vector<ll> res(n);
	while(!e.empty()){
		auto cur = *e.begin();
		e.erase(e.begin());
		ll time = get<0>(cur);
		int index = get<1>(cur), type = get<2>(cur);
		if(!type){
			if(server < k){
				server ++;
				e.insert({time + d[index].second, index, true});
			}
			else{
				wait.push_back(index);
			}
		}
		else{// if waitq isn't empty -> get one from it
			server --;
			res[index] = time;
			if(!wait.empty()){
				index = wait.front();
				wait.pop_front();
				server ++;
				e.insert({time + d[index].second, index, true});
			}
		}
	}
	for(auto x: res){
		cout << x << "\n";
	}
	return 0;
}