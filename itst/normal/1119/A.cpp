#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;
inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}
const int MAXN = 3e5 + 7;
int col[MAXN] , N;
signed main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		col[i] = read();
	int ans = 0;
	for(int i = 1 ; i <= N ; ++i){
		if(col[i] != col[1]) ans = max(ans , i - 1);
		if(col[i] != col[N]) ans = max(ans , N - i);
	}
	cout << ans;
	return 0;
}