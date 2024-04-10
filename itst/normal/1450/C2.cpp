#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

int N , T , cnt[2][3]; char Map[303][303];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; int num = 0; memset(cnt , 0 , sizeof(cnt));
		for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= N ; ++j){
				cin >> Map[i][j]; if(Map[i][j] == 'X') ++cnt[0][(i + j) % 3]; else if(Map[i][j] == 'O') ++cnt[1][(i + j) % 3];
			}
		for(int i = 0 ; i < 2 ; ++i) for(int j = 0 ; j < 3 ; ++j) num += cnt[i][j];
		int p , q;
		for(int i = 0 ; i < 3 ; ++i)
			for(int j = 0 ; j < 3 ; ++j)
				if(i != j && cnt[0][i] + cnt[1][j] <= num / 3){p = i; q = j; break;}
		for(int i = 1 ; i <= N ; ++i)
			for(int j = 1 ; j <= N ; ++j)
				if(Map[i][j] == 'O') Map[i][j] = (i + j) % 3 == q ? 'X' : 'O';
				else if(Map[i][j] == 'X') Map[i][j] = (i + j) % 3 == p ? 'O' : 'X';
		for(int i = 1 ; i <= N ; ++i , cout << endl) for(int j = 1 ; j <= N ; ++j) cout << Map[i][j];
		
	}
	return 0;
}