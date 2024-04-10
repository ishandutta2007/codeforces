#include<bits/stdc++.h>
using namespace std;

int T , N , ans[200003]; string s;
vector < int > pot[2];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> s; pot[0].clear(); pot[1].clear(); int cnt = 0;
		for(int i = 0 ; i < s.size() ; ++i){
			bool f = s[i] == '1'; if(pot[f].empty()) pot[f].push_back(++cnt);
			ans[i] = pot[f].back(); pot[f ^ 1].push_back(pot[f].back()); pot[f].pop_back();
		}
		cout << cnt << endl;
		for(int i = 0 ; i < s.size() ; ++i) cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}