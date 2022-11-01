#include<bits/stdc++.h>
using namespace std;

set < pair < int , int > > Mon , Pol; int Q , cnt;

int main(){
	ios::sync_with_stdio(0); cin >> Q;
	for(int i = 1 ; i <= Q ; ++i){
		int op , m; cin >> op;
		if(op == 1){cin >> m; Mon.insert(make_pair(++cnt , -m)); Pol.insert(make_pair(-m , cnt));}
		else if(op == 2){pair < int , int > t = *Mon.begin(); Pol.erase(make_pair(t.second , t.first)); Mon.erase(t); cout << t.first << ' ';}
		else{pair < int , int > t = *Pol.begin(); Mon.erase(make_pair(t.second , t.first)); Pol.erase(t); cout << t.second << ' ';}
	}
	return 0;
}