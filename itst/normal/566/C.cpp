#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define ld double
const int _ = 2e5 + 7; struct Edge{int end , upEd , w;}Ed[_ << 1]; int head[_] , cntEd , N , W[_];
void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}

ld mn; int id , nsz , msz , rt; bool vis[_];
void getsz(int x){vis[x] = 1; ++nsz; for(int i = head[x] ; i ; i = Ed[i].upEd) if(!vis[Ed[i].end]) getsz(Ed[i].end); vis[x] = 0;}
int getrt(int x){
	vis[x] = 1; int mx = 0 , sz = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){int t = getrt(Ed[i].end); sz += t; mx = max(mx , t);}
	mx = max(mx , nsz - sz); if(msz > mx){msz = mx; rt = x;} vis[x] = 0; return sz;
}

void calc(int x , int p , ld L , ld &ans , ld &dec){
	ld v = W[x] * sqrt(L); ans += v * L; dec += v;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p) calc(Ed[i].end , x , L + Ed[i].w , ans , dec);
}

void solve(int x){
	nsz = 0; msz = 1e9; getsz(x); getrt(x); x = rt;
	ld ans = 0 , dec = 0; calc(x , 0 , 0 , ans , dec); vis[x] = 1;
	if(mn > ans){mn = ans; id = x;}
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){
			ld ans = 0 , dec1 = 0; calc(Ed[i].end , x , Ed[i].w , ans , dec1);
			if(dec1 * 2 > dec){solve(Ed[i].end); break;}
		}
}

int main(){
	N = read(); for(int i = 1 ; i <= N ; ++i) W[i] = read();
	for(int i = 1 ; i < N ; ++i){int p = read() , q = read() , w = read(); addEd(p , q , w); addEd(q , p , w);}
	mn = 1e60; solve(1); cout << id << ' ' << setprecision(10) << mn << endl;
	return 0;
}