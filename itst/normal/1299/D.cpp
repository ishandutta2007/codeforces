#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

struct BASE{
	int val[5]; BASE(){memset(val , 0 , sizeof(val));}
	int& operator [](int x){return val[x];}

	bool ins(int x){
		for(int i = 4 ; i >= 0 ; --i)
			if(x >> i & 1) if(val[i]) x ^= val[i]; else{val[i] = x; return 1;}
		return 0;
	}

	void maintain(){
		for(int j = 4 ; ~j ; --j)
			for(int k = j + 1 ; k < 5 ; ++k)
				if(val[k] >> j & 1) val[k] ^= val[j];
	}

	int value(){
		maintain(); int sum = 0;
		for(int i = 4 ; i >= 0 ; --i) sum = (sum << (i + 1)) + val[i];
		return sum;
	}
	
	friend bool merge(BASE &p , BASE q){
		for(int i = 0 ; i < 5 ; ++i)
			if(q[i] && !p.ins(q[i])) return 0;
		return 1;
	}
}pot[403]; map < int , int > bid; int cntid , trs[403][403] , dp[403];

void dfs(BASE now , int id){
	if(id < 0){
		int t = now.value();
		if(bid.find(t) == bid.end()){pot[++cntid] = now; bid.insert(make_pair(t , cntid));}
		return;
	}
	dfs(now , id - 1);
	for(int j = 1 << id ; j < 1 << (id + 1) ; ++j){now[id] = j; dfs(now , id - 1);}
}

const int _ = 1e5 + 7 , MOD = 1e9 + 7;
struct Edge{int end , upEd , w;}Ed[_ << 1];
int head[_] , cntEd , N , M;
void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}

bool nxt[_] , in0[_]; int len[_] , rtlen[_] , dep[_]; BASE circ[_];
void dfs1(int x , int p , int r){
	dep[x] = dep[p] + 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd){
		int t = Ed[i].end;
		if(t != p)
			if(!dep[t] && !nxt[t]){len[t] = len[x] ^ Ed[i].w; dfs1(t , x , r);}
			else if(nxt[x] && nxt[t] && dep[t]){
				in0[r] &= in0[t] & merge(circ[r] , circ[t]);
				in0[t] = 0; rtlen[r] = len[t] ^ len[x] ^ Ed[i].w;
			}else if(dep[t] && dep[t] < dep[x])
				in0[r] &= circ[r].ins(len[t] ^ len[x] ^ Ed[i].w);
	}
}

int main(){
	dfs(BASE() , 4); //cntid = 374
	for(int i = 1 ; i <= cntid ; ++i)
		for(int j = 1 ; j <= cntid ; ++j){BASE tmp = pot[i]; trs[i][j] = merge(tmp , pot[j]) ? bid[tmp.value()] : 0;}

	N = read(); M = read(); dp[1] = 1;
	for(int i = 1 ; i <= M ; ++i){int x = read() , y = read() , w = read(); addEd(x , y , w); addEd(y , x , w);}
	
	for(int i = head[1] ; i ; i = Ed[i].upEd) nxt[Ed[i].end] = 1;
	for(int i = head[1] ; i ; i = Ed[i].upEd){
		in0[Ed[i].end] = 1; rtlen[Ed[i].end] = -1;
		len[Ed[i].end] = Ed[i].w; dfs1(Ed[i].end , 1 , Ed[i].end);
	}
	
	for(int i = head[1] ; i ; i = Ed[i].upEd)
		if(in0[Ed[i].end]){
			static int tmp[403]; memcpy(tmp , dp , sizeof(tmp));
			int id = bid[circ[Ed[i].end].value()];
			for(int j = 1 ; j <= cntid ; ++j)
				tmp[trs[j][id]] = (tmp[trs[j][id]] + (1ll + (rtlen[Ed[i].end] != -1)) * dp[j]) % MOD;
			if(~rtlen[Ed[i].end] && circ[Ed[i].end].ins(rtlen[Ed[i].end])){
				id = bid[circ[Ed[i].end].value()];
				for(int j = 1 ; j <= cntid ; ++j) tmp[trs[j][id]] = (tmp[trs[j][id]] + dp[j]) % MOD;
			}
			memcpy(dp , tmp , sizeof(tmp));
		}

	int sum = 0; for(int i = 1 ; i <= cntid ; ++i) sum = (sum + dp[i]) % MOD;
	printf("%d\n" , sum); return 0;
}