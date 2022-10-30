#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int mn[2003][2003] , N , M , X , Y , R , C;
bool Map[2003][2003];

int main(){
	cin >> N >> M >> R >> C >> X >> Y;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j){
			char c; cin >> c; Map[i][j] = c == '*';
		}
#define PII pair < int , int >
	deque < PII > q; memset(mn , 0x3f , sizeof(mn));
	q.push_back(PII(R , C)); mn[R][C] = 0;
	while(!q.empty()){
		PII t = q.front(); q.pop_front();
		for(int i = 0 ; i < 4 ; ++i){
			int x = t.first + dir[i][0] , y = t.second + dir[i][1];
			if(x > 0 && x <= N && y > 0 && y <= M && !Map[x][y] && mn[x][y] > mn[t.first][t.second] + (i == 3)){
				mn[x][y] = mn[t.first][t.second] + (i == 3);
				if(i == 3) q.push_back(PII(x , y));
				else q.push_front(PII(x , y));
			}
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			ans += mn[i][j] <= X && mn[i][j] - (C - j) <= Y;
	cout << ans;
	return 0;
}