#include<bits/stdc++.h>
using namespace std;

int nxt[100003] , L; char str[100003]; bool in[100003];

int main(){
	scanf("%s" , str + 1); L = strlen(str + 1);
	vector < int > match[2]; int cnt[2] = {} , ans = L - 1;
	for(int i = 1 ; i <= L ; ++i){
		bool flg = str[i] == 'R'; ++cnt[flg];
		if(match[!flg].size()){nxt[match[!flg].back()] = i; match[!flg].pop_back(); in[i] = 1; --ans;}
		match[flg].push_back(i);
	}
	int fir = -1; vector < pair < int , int > > pot[2][2];
	for(int i = 1 ; i <= L ; ++i)
		if(!in[i]){
			bool flg = str[i] == 'R';
			if(!~fir && cnt[flg] >= cnt[!flg]) fir = flg;
			int t = i; while(nxt[t]) t = nxt[t];
			bool flg1 = str[t] == 'R'; pot[flg][flg1 ^ 1].push_back(make_pair(i , t));
		}
	if(pot[0][1].empty() && pot[1][0].empty() && pot[0][0].size() && pot[1][1].size()){
		pair < int , int > p = pot[0][0].back() , q = pot[1][1].back();
		pot[0][0].pop_back(); pot[1][1].pop_back();
		if(p.first < q.first){
			pot[1][0].push_back(make_pair(nxt[p.first] , p.second)); nxt[p.first] = q.first;
			pot[0][1].push_back(make_pair(p.first , q.second));
		}else{
			pot[0][1].push_back(make_pair(nxt[q.first] , q.second)); nxt[q.first] = p.first;
			pot[1][0].push_back(make_pair(q.first , p.second));
		}
	}
	
	int pre = 0;
	if(pot[fir][fir].size()){
			for(auto t : pot[fir][fir]){nxt[pre] = t.first; pre = t.second;}
			pot[fir][fir].clear();
		}
	while(pot[0][1].size() || pot[1][0].size() || pot[0][0].size() || pot[1][1].size()){
		nxt[pre] = pot[fir][fir ^ 1].back().first; pre = pot[fir][fir ^ 1].back().second;
		pot[fir][fir ^ 1].pop_back(); fir ^= 1;
		if(pot[fir][fir].size()){
			for(auto t : pot[fir][fir]){nxt[pre] = t.first; pre = t.second;}
			pot[fir][fir].clear();
		}
	}
	
	cout << ans << endl;
	for(int i = nxt[0] ; i ; i = nxt[i]) cout << i << ' ';
	
	return 0;
}