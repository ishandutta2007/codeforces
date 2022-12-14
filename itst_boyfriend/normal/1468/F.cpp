#include<bits/stdc++.h>
using namespace std;

map < pair < int , int > , int > cnt;

int main(){
	ios::sync_with_stdio(0); int T , N;
	for(cin >> T ; T ; --T){
		cin >> N; cnt.clear(); long long ans = 0;
		for(int i = 1 ; i <= N ; ++i){
			int x1 , y1 , x2 , y2; cin >> x1 >> y1 >> x2 >> y2; x2 -= x1; y2 -= y1;
			int t = __gcd(abs(x2) , abs(y2)); x2 /= t; y2 /= t;
			ans += cnt[make_pair(-x2 , -y2)]; ++cnt[make_pair(x2 , y2)];
		}
		cout << ans << endl;
	}
	return 0;
}