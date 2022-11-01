#include<bits/stdc++.h>
using namespace std;

int main(){
	static int T , N , M , a , b;
	for(cin >> T ; T ; --T){
		cin >> N >> M >> a >> b; multiset < int > val; for(int i = 1 ; i <= M ; ++i){int V; cin >> V; val.insert(V);}
		int cnt = min(M , abs(a - b) - 1) , lst = a > b ? N - b : b - 1 , ans = 0;
		for(int i = 1 ; i <= cnt ; ++i){auto p = val.lower_bound(lst - i + 1); if(p != val.begin()){++ans; val.erase(--p);}}
		cout << ans << endl;
	}
	return 0;
}