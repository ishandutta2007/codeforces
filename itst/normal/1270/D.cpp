#include<bits/stdc++.h>
using namespace std;

pair < int , int > query(vector < int > pot){
	cout << "? "; for(auto t : pot) cout << t << ' ';
	cout << endl; int ans , val; cin >> ans >> val; return make_pair(ans , val);
}

int main(){
	int N , K; cin >> N >> K;
	if(K == 1){cout << "! 1" << endl; return 0;}
	vector < int > pot; vector < pair < int , int > > now; for(int i = 1 ; i <= K ; ++i) pot.push_back(i);
	for(int i = K ; i <= N ; ++i){pair < int , int > t = query(pot); pot.erase(find(pot.begin() , pot.end() , t.first)); now.push_back(t); pot.push_back(i + 1);}
	if(now.size() >= K){
		pot.clear(); for(int i = 0 ; i < K ; ++i) pot.push_back(now[i].first);
		sort(now.begin() , now.begin() + K , [&](pair < int , int > p , pair < int , int > q){return p.second < q.second;});
		int M = (find(now.begin() , now.end() , query(pot)) - now.begin()) + 1; cout << "! " << M << endl;
	}else{
		sort(now.begin() , now.end() , [&](pair < int , int > p , pair < int , int > q){return p.second < q.second;});
		for(auto t : now) pot.push_back(t.first);
		int M = 1; vector < int > pot1;
		for(int i = 1 ; i <= N ; ++i){
			bool flg = 0; for(auto t : now) if(t.first == i) flg = 1;
			if(!flg) pot1.push_back(i);
		}
		for(auto t : pot1){
			pot = pot1; pot.push_back(now[0].first); pot.push_back(now[1].first);
			pot.erase(find(pot.begin() , pot.end() , t)); M += query(pot) == now[1];
		}
		cout << "! " << M << endl;
	}
	return 0;
}