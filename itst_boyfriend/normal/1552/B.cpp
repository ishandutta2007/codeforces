#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int V[50003][5] , N , T;

int main(){
	for(T = read() ; T ; --T){
		N = read(); for(int i = 0 ; i < N ; ++i) for(int j = 0 ; j < 5 ; ++j) V[i][j] = read();
		int mx = 0; bool flg = 1;
		for(int i = 1 ; i < N ; ++i){
			int cnt = 0; for(int j = 0 ; j < 5 ; ++j) cnt += V[i][j] > V[mx][j];
			if(cnt < 3) mx = i;
		}
		for(int i = 0 ; i < N ; ++i){
			int cnt = 0; for(int j = 0 ; j < 5 ; ++j) cnt += V[i][j] >= V[mx][j];
			flg &= cnt >= 3;
		}
		if(flg) cout << mx + 1 << endl; else cout << -1 << endl;
	}
	return 0;
}