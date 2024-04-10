#include <iostream>
#include <queue>
// #include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::move;

char map[1000][1001];
int distance[1000][1000];
bool isPushed[1000][1000];
int r, c, sr, sc, er, ec;

struct P{
	int r, c;
};

inline void checkPush1(queue<P>& q, int y, int x){
	if( y >= 0 && y < r && x >= 0 && x < c && !isPushed[y][x]){
		isPushed[y][x] = true;
		q.push(P{y, x});
	}
}
void bfs1(){
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++){
			isPushed[i][j] = map[i][j] == 'T';
			distance[i][j] = 999999999;
		}
	queue<P> q;
	checkPush1(q, er, ec);
	int dis = 0;
	while(!q.empty()){
		queue<P> q1;
		while(!q.empty()){
			P p = q.front();
			q.pop();
			checkPush1(q1, p.r, p.c + 1);
			checkPush1(q1, p.r, p.c - 1);
			checkPush1(q1, p.r + 1, p.c);
			checkPush1(q1, p.r - 1, p.c);
			distance[p.r][p.c] = dis;
		}
		dis++;
		q = move(q1);
	}
}

int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++)
		cin >> map[i];
	// find 'S', 'E'
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			if(map[i][j] == 'S')
				sr = i, sc = j;
			else if(map[i][j] == 'E')
				er = i, ec = j;
	// bfs from 'S'
	bfs1();
	int s2e = distance[sr][sc];
	int battles = 0;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			if(distance[i][j] <= s2e && '1' <= map[i][j] && map[i][j] <= '9')
				battles += map[i][j] - '0';
	cout << battles << endl;
	return 0;
}