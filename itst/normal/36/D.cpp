#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T , K;
	for(cin >> T >> K ; T ; --T){
		int x , y; cin >> x >> y;
		if(--x > --y) swap(x , y);
		int t = x / (K + 1); x -= t * (K + 1); y -= t * (K + 1);
		if(x == K) puts("+");
		else puts(((x + y) & 1) ^ (K != 1 && (t & 1)) ? "+" : "-");
	}
	return 0;
}