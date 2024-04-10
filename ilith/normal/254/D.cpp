#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
typedef vector<int> vi;
const int N = 1010;
char s[N][N];
map<int,int> v[N];
int n , m , D , _;
 
map<int,int> bfs(int sx,int sy){
	int S = sx * m + sy;
	vi q;q.pb(S);
	map<int,int> dis;dis[S] = 0;
	rep(i,0,sz(q)){
		int c = q[i];
		if(dis[c] >= D) break;
		rep(d,0,4){
			int nx = c / m + (d == 2) - (d == 0);
			int ny = c % m + (d == 1) - (d == 3);
			int ns = nx * m + ny;
			if(!dis.count(ns) && s[nx][ny] != 'X') dis[ns] = dis[c] + 1 , q.pb(ns);
		}
	}
	return dis;
}
 
bool solve(int p1,int p2){
	rep(i,0,_) if(!v[i].count(p1) && !v[i].count(p2)) return false;
	return true;
}
bool solve(int p1){
	rep(i,0,_) if(!v[i].count(p1)){
		for(auto b : v[i]) if(solve(p1 , b.fi)){
			printf("%d %d %d %d\n",p1 / m + 1, p1 % m + 1 , b.fi / m + 1 , b.fi % m + 1);
			return 1;
		}
		return 0;
	}
	int p2 = 0;s[p1 / m][p1 % m] = 'X';
	rep(i,0,n) rep(j,0,m) if(s[i][j] != 'X') p2 = i * m + j;
	printf("%d %d %d %d\n",p1 / m + 1 , p1 % m + 1 , p2 / m + 1 , p2 % m + 1);
	return 1;
}
 
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&D);
	rep(i,0,n) scanf("%s",s[i]);
	rep(i,0,n) rep(j,0,m){
		if(s[i][j] == 'R') v[_++] = bfs(i , j);
		if(_ >= 1000) return puts("-1") , 0;
	}
	for(auto a : v[0]) if(solve(a.fi)) return 0;
	puts("-1");
	return 0;
}