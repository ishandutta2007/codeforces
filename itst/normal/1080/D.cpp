#include<bits/stdc++.h>
#define int long long
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

int dp[40] , maxN = 0;

signed main(){
	for(maxN = 0 ; 4 * dp[maxN] + 1 <= 1e18 ; ++maxN)
		dp[maxN + 1] = 4 * dp[maxN] + 1;
	for(int T = read() ; T ; --T){
		int P = read() , Q = read();
		if(P - 1 > maxN){
			cout << "YES " << P - 1 << endl;
			continue;
		}
		int cur = 1 , L = 0 , R = 0 , i;
		for(i = P - 1 ; i >= 0 ; --i){
			L += cur;
			R += cur + (cur * 2 - 1) * dp[i];
			if(L <= Q && Q <= R)
				break;
			cur = cur * 2 + 1;
		}
		if(i >= 0)
			cout << "YES " << i << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}