#include<bits/stdc++.h>
using namespace std;

int T , N , M , K; unordered_set < int > nxt[100003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M >> K; for(int i = 1 ; i <= N ; ++i) nxt[i].clear();
		for(int i = 1 ; i <= M ; ++i){int p , q; cin >> p >> q; nxt[p].insert(q); nxt[q].insert(p);}
		if(K == 1){cout << "2\n1\n"; continue;}
		priority_queue < pair < int , int > > q; for(int i = 1 ; i <= N ; ++i){q.push(make_pair(-nxt[i].size() , i));}
		vector < int > ans; bool kans = 0;
		
		while(!q.empty()){
			int t = q.top().second; q.pop(); if(nxt[t].empty()) continue;
			if(nxt[t].size() >= K){kans = 1; break;}
			if(nxt[t].size() == K - 1 && K * (K - 1ll) / 2 <= M){
				bool f = 1;
				for(auto p = nxt[t].begin() ; f && p != nxt[t].end() ; ++p)
					for(auto q = p ; f && ++q != nxt[t].end() ;)
						f &= nxt[*p].find(*q) != nxt[*p].end();
				if(f){ans.push_back(t); ans.insert(ans.end() , nxt[t].begin() , nxt[t].end()); break;}
			}
			
			for(auto p : nxt[t]){nxt[p].erase(t); q.push(make_pair(-nxt[p].size() , p));}
			nxt[t].clear();
		}
		if(ans.size()){cout << 2 << '\n'; for(auto t : ans) cout << t << ' ';}
		else if(kans){
			for(int i = 1 ; i <= N ; ++i) if(nxt[i].size()) ans.push_back(i);
			cout << 1 << ' ' << ans.size() << '\n';
			for(auto t : ans) cout << t << ' ';
		}else cout << -1;
		cout << '\n';
	}
	return 0;
}