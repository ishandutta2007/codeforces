#include<bits/stdc++.h>
using namespace std;

set < int > pot; int T , N , M; map < int , int > plc;

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> M; plc.clear(); for(int i = 1 ; i <= M ; ++i){int p , q; cin >> p >> q; plc[q] |= 1 << (p - 1);}
		set < int > move; move.insert(1); move.insert(N);
		for(auto t : plc){
			if(t.first > 1) move.insert(t.first - 1);
			move.insert(t.first); if(t.first != N) move.insert(t.first + 1);
		}
		int pre = 0; pot.clear(); pot.insert(3);
		for(auto t : move){
			if((t - pre) % 2 == 0){set < int > tmp; for(auto t : pot){tmp.insert(t ^ 3);} pot = tmp;}
			int ban = plc[t]; set < int > tmp; pre = t;
			for(auto p : pot)
				for(int x = 0 ; x < 2 ; ++x)
					for(int y = 0 ; y < 2 ; ++y)
						if((x ^ (p & 1)) && (y ^ (p >> 1)) && !(x & (ban & 1)) && !(y & (ban >> 1))){
							tmp.insert(ban | x | (y << 1));
							if(!x && !y && !ban) tmp.insert(3);
						}
			pot = tmp;
		}
		cout << (pot.find(3) == pot.end() ? "NO" : "YES") << endl;
	}
	return 0;
}