#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 3e5 + 7; int T , N , ans[_]; vector < int > pot[_];

int main(){
	for(T = read() ; T ; --T , putchar('\n')){
		N = read(); for(int i = 1 ; i <= N ; ++i) pot[i].clear();
		for(int i = 1 ; i <= N ; ++i) pot[read()].push_back(i);
		for(int i = 0 ; i <= N + 1 ; ++i) ans[i] = 1e9;
		for(int i = 1 ; i <= N ; ++i)
			if(pot[i].size()){
				int v = max(pot[i][0] , N - pot[i].back() + 1);
				for(int j = 1 ; j < pot[i].size() ; ++j) v = max(v , pot[i][j] - pot[i][j - 1]);
				ans[v] = min(ans[v] , i);
			}
		for(int i = 1 ; i <= N ; ++i) printf("%d " , (ans[i] = min(ans[i] , ans[i - 1])) == 1e9 ? -1 : ans[i]);
	}
	return 0;
}