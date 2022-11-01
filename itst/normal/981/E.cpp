#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int P = 1e9 + 7; int upd(int x){return x + (x >> 31 & P);}
int N , Q , num[10001]; bool flg[10001]; vector < int > pot[10001];

int main(){
	N = read(); Q = read(); num[0] = 1;
	for(int i = 1 ; i <= Q ; ++i){int l = read() , r = read() , v = read(); pot[l].push_back(v); pot[r + 1].push_back(-v);}
	
	for(int i = 1 ; i <= N ; ++i){
		for(auto p : pot[i])
			if(p > 0) for(int q = N ; q >= p ; --q) num[q] = upd(num[q] + num[q - p] - P);
			else for(int q = -p ; q <= N ; ++q) num[q] = upd(num[q] - num[q + p]);
		for(int j = 1 ; j <= N ; ++j) flg[j] |= num[j];
	}
	
	int cnt = 0; for(int i = 1 ; i <= N ; ++i) cnt += flg[i];
	cout << cnt << endl; for(int i = 1 ; i <= N ; ++i) if(flg[i]) cout << i << ' ';
	return 0;
}