#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int _ = 1e5 + 7; int N , Q , ans[_][53] , all[53]; ll L[53];
struct Edge{int end , upEd , w;}Ed[_ << 1]; int head[_] , cntEd;
void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}

int id; ll mx , dst[_];
void qmx(int x , int p , ll v){
	if(v >= mx){mx = v; id = x;}
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p) qmx(Ed[i].end , x , v + Ed[i].w);
}

void fil(int x , int p , ll v){
	dst[x] = max(dst[x] , v);
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p) fil(Ed[i].end , x , v + Ed[i].w);
}

ll stk[_][2]; int top;
void dfs(int x , int p){
	stk[++top][0] = x; stk[top][1] = dst[x];
	for(int i = 1 ; i <= Q ; ++i){
		++ans[x][i];
		if(L[i] < dst[x] - stk[1][1]){
			int l = 1 , r = top;
			while(l < r){int mid = (l + r) >> 1; dst[x] - stk[mid][1] <= L[i] ? r = mid : l = mid + 1;}
			--ans[stk[l - 1][0]][i];
		}
	}
	
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){dfs(Ed[i].end , x); for(int j = 1 ; j <= Q ; ++j) ans[x][j] += ans[Ed[i].end][j];}
	for(int j = 1 ; j <= Q ; ++j) all[j] = max(all[j] , ans[x][j]);
	--top;
}

signed main(){
	ios::sync_with_stdio(0); cin >> N;
	for(int i = 1 ; i < N ; ++i){int p , q , w; cin >> p >> q >> w; addEd(p , q , w); addEd(q , p , w);}
	qmx(1 , 0 , 0); int l = id; qmx(l , 0 , 0); int r = id; fil(l , 0 , 0); fil(r , 0 , 0);
	cin >> Q; for(int i = 1 ; i <= Q ; ++i) cin >> L[i];
	int mn = 1; for(int i = 1 ; i <= N ; ++i) if(dst[i] < dst[mn]) mn = i;
	dfs(mn , 0); for(int i = 1 ; i <= Q ; ++i) cout << all[i] << endl;
	return 0;
}