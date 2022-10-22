#include <bits/stdc++.h>
using namespace std;

int T , t , m , ml , mr , x , l , r;

int main(){
	cin >> T;
	while(T--){
		scanf("%d %d" , &t , &m); ml = mr = m; int cur = 0; bool flg = 1;
		for(int i = 1 ; i <= t ; ++i){
			scanf("%d %d %d" , &x , &l , &r);
			ml -= x - cur; mr += x - cur; cur = x;
			ml = max(ml , l); mr = min(mr , r); flg &= ml <= mr;
		}
		puts(flg ? "YES" : "NO");
	}
	return 0;
}