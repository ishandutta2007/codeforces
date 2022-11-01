#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7;
int fa[_] , l[_] , r[_] , sz[_]; int N , cnt;
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
void merge(int p , int q){
	if((p = find(p)) == (q = find(q))) return;
	fa[p] = q; l[q] = min(l[p] , l[q]); r[q] = max(r[p] , r[q]); sz[q] += sz[p];
}

#define mid ((l + r) >> 1)
vector < int > pot[_ * 40]; int cntc , ch[_ * 40][2];
void modify(int &x , int l , int r , int L , int R , int id){
	if(!x) x = ++cntc;
	if(l >= L && r <= R) return pot[x].push_back(id);
	if(mid >= L) modify(ch[x][0] , l , mid , L , R , id);
	if(mid < R) modify(ch[x][1] , mid + 1 , r , L , R , id);
}

void link(int x , int l , int r , int tar , int id){
	for(auto t : pot[x]) merge(t , id);
	if(pot[x].size() > 1) pot[x].resize(1);
	if(!x) return;
	mid >= tar ? link(ch[x][0] , l , mid , tar , id) : link(ch[x][1] , mid + 1 , r , tar , id);
}

int main(){
	ios::sync_with_stdio(0); cin >> N; int rt = 0;
	for(int i = 1 ; i <= N ; ++i){
		int op , x , y; cin >> op >> x >> y;
		if(op == 1){
			l[++cnt] = x; r[cnt] = y; sz[cnt] = 1; fa[cnt] = cnt;
			if(l[cnt] + 1 < r[cnt]) modify(rt , -1e9 , 1e9 , l[cnt] + 1 , r[cnt] - 1 , cnt);
			link(rt , -1e9 , 1e9 , x , cnt); link(rt , -1e9 , 1e9 , y , cnt);
		}
		else{
			int p = find(x) , q = find(y); 
			puts(l[p] >= l[q] && r[p] <= r[q] && !(l[p] == l[q] && r[p] == r[q] && sz[p] == 1) ? "YES" : "NO");
		}
	}
	return 0;
}