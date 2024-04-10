#include<bits/stdc++.h>
using namespace std;

/*
  REMEMBER:
  1.Think TWICE, code ONCE!
  Are there any counterexamples to your algo?
	
  2.Be careful about the BOUNDARIES in your algo!
  N=1? P=1? Is P a prime? Something about 0?
	
  3.Never make STUPID MISTAKES!
  Integer overflow? Array size? Time complexity? Memory usage? Precition error?
*/

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define int long long
const int _ = 1e6 + 7;
struct Edge{int end , upEd , w;}Ed[_ << 1];
int head[_] , cntEd , N , M;
void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}

#define PII pair < int , int >
int dfn[_] , low[_] , in[_] , cnt , stk[_] , top , ts; bool ins[_]; 
vector < PII > nxt[_]; int sum[_] , dp[_];
void pop(int x){
	++cnt;
	do{int t = stk[top]; in[t] = cnt; ins[t] = 0;}while(stk[top--] != x);
}

void tarjan(int x){
	stk[++top] = x; dfn[x] = low[x] = ++ts; ins[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd){
		if(!dfn[Ed[i].end]) tarjan(Ed[i].end);
		else if(!ins[Ed[i].end]) continue;
		low[x] = min(low[x] , low[Ed[i].end]);
	}
	if(dfn[x] == low[x]) pop(x);
}

int val[_] , psum[_];
int calc(int w){
	int L = 0 , R = 20000;
	while(L < R){
		int mid = (L + R + 1) >> 1;
		val[mid] <= w ? L = mid : R = mid - 1;
	}
	return (L + 1) * w - psum[L];
}

int search(int id){
	if(dp[id] != -1) return dp[id];
	dp[id] = 0;
	for(auto t : nxt[id]) dp[id] = max(dp[id] , search(t.first) + t.second);
	return dp[id] += sum[id];
}

signed main(){
	N = read(); M = read();
	for(int i = 1 ; i <= M ; ++i){int p = read() , q = read() , w = read(); addEd(p , q , w);}
	for(int i = 1 ; i <= 20000 ; ++i){
		val[i] = i * (i + 1) / 2; psum[i] = psum[i - 1] + val[i];
	}
	for(int i = 1 ; i <= N ; ++i) if(!dfn[i]) tarjan(i);
	for(int i = 1 ; i <= N ; ++i)
		for(int j = head[i] ; j ; j = Ed[j].upEd)
			if(in[i] == in[Ed[j].end]) sum[in[i]] += calc(Ed[j].w);
			else nxt[in[i]].push_back(PII(in[Ed[j].end] , Ed[j].w));
	memset(dp , -1 , sizeof(dp)); cout << search(in[read()]); return 0;
}