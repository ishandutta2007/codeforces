#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<iomanip>
using namespace std;

const int _ = 1e5 + 7;
struct Edge{int end , upEd;}Ed[_ << 1];
int N , Q , head[_] , cntEd;
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

int up[_][20] , dep[_];
void dfs(int x , int p){
	dep[x] = dep[p] + 1; up[x][0] = p;
	for(int i = 1 ; up[x][i - 1] ; ++i) up[x][i] = up[up[x][i - 1]][i - 1];;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p) dfs(Ed[i].end , x);
}

int LCA(int x , int y){
	if(dep[x] < dep[y]) swap(x , y);
	for(int i = 19 ; i >= 0 ; --i)
		if(dep[x] - (1 << i) >= dep[y]) x = up[x][i];
	if(x == y) return x;
	for(int i = 19 ; i >= 0 ; --i)
		if(up[x][i] != up[y][i]) {x = up[x][i]; y = up[y][i];}
	return up[x][0];
}

int dist(int p , int q){return dep[p] + dep[q] - 2 * dep[LCA(p , q)];;}

int main(){
	scanf("%d" , &N);
	for(int i = 1 ; i < N ; ++i){int x , y; scanf("%d %d" , &x , &y); addEd(x , y); addEd(y , x);}
	dfs(1 , 0); int Q , x , y , a , b , k;
	for(scanf("%d" , &Q) ; Q ; --Q){
		scanf("%d %d %d %d %d" , &x , &y , &a , &b , &k);
		int l1 = dist(a , b) , l2 = dist(a , x) + dist(y , b) + 1 , l3 = dist(a , y) + dist(b , x) + 1;
		bool flg = 0;
		if(l1 <= k && (k - l1) % 2 == 0) flg = 1;
		if(l2 <= k && (k - l2) % 2 == 0) flg = 1;
		if(l3 <= k && (k - l3) % 2 == 0) flg = 1;
		puts(flg ? "YES" : "NO");
	}
	
	return 0;
}