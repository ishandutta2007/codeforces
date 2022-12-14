#include<bits/stdc++.h>
using namespace std;

int T , N , M , type[200003] , defcnt[200003]; vector < int > nxt[200003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M; for(int i = 1 ; i <= N ; ++i){defcnt[i] = type[i] = 0; nxt[i].clear();}
		vector < int > ans; for(int i = 1 ; i <= M ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q);}
		for(int i = 1 ; i <= N ; ++i)
			if(defcnt[i]){
				if(type[i] == 2) for(auto t : nxt[i]) --defcnt[t];
				type[i] = 3;
			}
			else if(!type[i]){
				type[i] = 1; sort(nxt[i].begin() , nxt[i].end());
				for(auto t : nxt[i])
					if(!type[t]){type[t] = 2; for(auto p : nxt[t]) ++defcnt[p];}
			}
		for(int i = 1 ; i <= N ; ++i) if(type[i] == 3) ans.push_back(i);
		cout << ans.size() << endl;
		for(auto t : ans) cout << t << ' ';
		cout << endl;
	}
	return 0;
}