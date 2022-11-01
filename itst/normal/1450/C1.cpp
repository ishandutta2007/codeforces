#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

const int _ = 303; char Map[_][_]; int T , N , cnt[3];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; memset(cnt , 0 , sizeof(cnt));
		for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= N ; ++j){cin >> Map[i][j]; if(Map[i][j] == 'X') ++cnt[(i + j) % 3];}
		int mn = 0; for(int i = 0 ; i < 3 ; ++i) if(cnt[i] < cnt[mn]) mn = i;
		for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= N ; ++j) if(Map[i][j] == 'X' && (i + j) % 3 == mn) Map[i][j] = 'O';
		for(int i = 1 ; i <= N ; ++i , cout << endl) for(int j = 1 ; j <= N ; ++j) cout << Map[i][j];
	}
	return 0;
}