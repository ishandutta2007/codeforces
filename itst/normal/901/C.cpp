#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair < int , int >
const int _ = 3e5 + 7;
struct Edge{int end , upEd;}Ed[_ << 1];
int head[_] , cntEd , N , M , Q , pre[_] , dep[_] , fa[_] , rht[_] , sum[_] , cnts; PII seg[_];
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

int dfs(int x , int p){
	int t = 0; dep[x] = dep[p] + 1; fa[x] = p;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p)
			if(!dep[Ed[i].end]){
				int c = dfs(Ed[i].end , x);
				if(pre[c] == x){
					int mx = c , mn = c;
					do{c = fa[c]; mx = max(mx , c); mn = min(mn , c);}while(c != x);
					seg[++cnts] = PII(mn , mx);
				}
				else t |= c;
			}
			else if(dep[Ed[i].end] < dep[x]) pre[t = x] = Ed[i].end;
	return t;
}

signed main(){
	ios::sync_with_stdio(0); cin >> N >> M;
	for(int i = 1 , x , y ; i <= M ; ++i){cin >> x >> y; addEd(x , y); addEd(y , x);}
	for(int i = 1 ; i <= N ; ++i) if(!dep[i]) dfs(i , 0);
	sort(seg + 1 , seg + cnts + 1);
	for(int i = N , r = N + 1 ; i ; --i){
		while(seg[cnts].first == i) r = min(r , seg[cnts--].second);
		rht[i] = r - 1;
	}
	for(int i = 1 ; i <= N ; ++i) sum[i] = sum[i - 1] + rht[i] - i + 1;
	for(cin >> Q ; Q ; --Q){
		int l , r; cin >> l >> r; int t = max(l , (int)(lower_bound(rht + 1 , rht + N + 1 , r) - rht));
		cout << sum[t - 1] - sum[l - 1] + (r - t + 1) * (r - t + 2) / 2 << endl;
	}
	return 0;
}