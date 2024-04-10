#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll read(){
	ll a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int P = 1e9 + 7 , _ = 4e5 + 7;
struct Edge{int end , upEd; ll w;}Ed[_]; int head[_] , cntEd , N , M;
void addEd(int a , int b , ll c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}
namespace Base{
	ll sz , pot[62]; void clr(){memset(pot , 0 , sizeof(pot)); sz = 0;}
	void ins(ll v){for(int i = 61 ; ~i ; --i) if(v >> i & 1) if(!pot[i]){pot[i] = v; ++sz; return;} else v ^= pot[i];}
	bool qry(int x){for(int i = 0 ; i <= 61 ; ++i){if(pot[i] >> x & 1) return 1;}return 0;}
}

bool vis[_]; vector < int > node; ll val[_];
void dfs(int x){
	vis[x] = 1; node.push_back(x);
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){val[Ed[i].end] = val[x] ^ Ed[i].w; dfs(Ed[i].end);}
		else Base::ins(val[x] ^ val[Ed[i].end] ^ Ed[i].w);
}

int main(){
	N = read(); M = read(); int ans = 0;
	for(int i = 1 ; i <= M ; ++i){int p = read() , q = read(); ll w = read(); addEd(p , q , w); addEd(q , p , w);}
	for(int i = 1 ; i <= N ; ++i)
		if(!vis[i]){
			Base::clr(); node.clear(); dfs(i);
			for(int j = 0 ; j <= 61 ; ++j)
				if(Base::qry(j)) ans = (ans + (1ll << j) % P * ((1ll << (Base::sz - 1)) % P) % P * (node.size() * (node.size() - 1ll) / 2 % P)) % P;
				else{
					int cnt0 = 0 , cnt1 = 0; for(auto t : node) val[t] >> j & 1 ? ++cnt0 : ++cnt1;
					ans = (ans + (1ll << j) % P * ((1ll << Base::sz) % P) % P * cnt0 % P * cnt1) % P;
				}
		}
	cout << ans; return 0;
}