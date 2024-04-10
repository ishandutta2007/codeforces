#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int _ = 1e5 + 7; int N , C[_] , W[_] , cnt[_] , num[_]; bool flg[_];

int main(){
	N = read(); cnt[0] = read(); long long sum = 0; for(int i = 1 ; i <= N ; ++i) C[i] = read();
	for(int i = 1 ; i <= N ; ++i){
		W[i] = read(); sum += W[i] * ((100 - C[i] % 100) % 100);
		cnt[i] = cnt[i - 1] + (100 - C[i] % 100) % 100; num[i] = cnt[i] / 100; cnt[i] %= 100;
	}
	
	priority_queue < pair < int , int > > q;
	for(int i = N ; i ; --i){
		if(C[i] % 100) q.push(make_pair(W[i] * ((100 - C[i] % 100) % 100) , i));
		while(q.size() && num[i]--){sum -= q.top().first; flg[q.top().second] = 1; q.pop();}
	}
	printf("%lld\n" , sum);
	for(int i = 1 ; i <= N ; ++i)
		if(flg[i] || C[i] % 100 == 0) printf("%d %d\n" , C[i] / 100 , C[i] % 100);
		else printf("%d 0\n" , C[i] / 100 + 1);
	return 0;
}