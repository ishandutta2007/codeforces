#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; int cnt[_] , N , M , Q , ans;

void add(int x){if(!(cnt[x]++)) --ans;}
void sub(int x){if(!--cnt[x]) ++ans;}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M; ans = N;
	for(int i = 1 ; i <= M ; ++i){int p , q; cin >> p >> q; add(min(p , q));}
	cin >> Q;
	for(int i = 1 ; i <= Q ; ++i){
		int tp , x , y; cin >> tp;
		if(tp == 3) cout << ans << '\n';
		else{
			cin >> x >> y; tp == 1 ? add(min(x , y)) : sub(min(x , y));
		}
	}
	return 0;
}