#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    while(!isdigit(c))
        c = getchar();
    while(isdigit(c)){
        a = a * 10 + c - 48;
        c = getchar();
    }
    return a;
}

#define PII pair < int , int >
#define st first
#define nd second
#define ll long long
const int MAXN = 1e5 + 7;
vector < PII > ch[MAXN];
int poww10[MAXN] , inv10[MAXN];
int N , M , cntEd , nowSz , minSz , minInd;
bool vis[MAXN];
map < int , int > times;
ll sum , inv;

inline void addEd(int a , int b , int c){
	ch[a].push_back(PII(b , c)); ch[b].push_back(PII(a , c));
}

void exgcd(ll a , ll b , ll &x , ll &y){
    !b ? (x = 1 , y = 0) : (exgcd(b , a % b , y , x) , y -= a / b * x);
}

void getSz(int x){
	vis[x] = 1; ++nowSz;
	for(auto t : ch[x])
		if(!vis[t.st]) getSz(t.st);
	vis[x] = 0;
}

int getRt(int x){
	int sz = vis[x] = 1 , maxSz = 0;
	for(auto t : ch[x])
		if(!vis[t.st]){
			int num = getRt(t.st);
			sz += num; maxSz = max(maxSz , num);
		}
	maxSz = max(maxSz , nowSz - sz);
	if(maxSz < minSz){minSz = maxSz; minInd = x;}
	vis[x] = 0; return sz;
}

void getVal(int x , int val , int dep){
	vis[x] = 1; ++times[val];
	for(auto t : ch[x])
		if(!vis[t.st]) getVal(t.st , (val + 1ll * poww10[dep] * t.nd) % M , dep + 1);
	vis[x] = 0;
}

void calc(int x , int val , int dep){
	vis[x] = 1;
	int cur = 1ll * inv10[dep] * val % M;
	if(cur) cur = M - cur;
	if(times.find(cur) != times.end()) sum += times[cur];
	for(auto t : ch[x])
		if(!vis[t.st]) calc(t.st , (val * 10ll + t.nd) % M , dep + 1);
	vis[x] = 0;
}

void solve(int x){
	times.clear(); nowSz = 0; minSz = 1e9;
	getSz(x); getRt(x);
	vis[x = minInd] = 1;
	times[0] = 1;
	for(auto t : ch[x])
		if(!vis[t.st]){
			calc(t.st , t.nd % M , 1);
			getVal(t.st , t.nd % M , 1);
		}
	times.clear();
	auto t = --ch[x].end();
	do{
		if(!vis[t->st]){
			calc(t->st , t->nd % M , 1);
			getVal(t->st , t->nd % M , 1);
		}
	}while(t-- != ch[x].begin());
	sum += times[0];
	for(auto t : ch[x]) if(!vis[t.st]) solve(t.st);
}

signed main(){
    N = read(); M = read();
    ll a; exgcd(10 , M , inv , a); inv = (inv + M) % M;
	poww10[0] = inv10[0] = 1;
	for(int i = 1 ; i <= N ; ++i){
		poww10[i] = poww10[i - 1] * 10ll % M;
		inv10[i] = inv10[i - 1] * inv % M;
	}
    for(int i = 1 ; i < N ; ++i){
        int a = read() , b = read() , c = read();
        addEd(a , b , c);
    }
	solve(1); cout << sum << endl;
    return 0;
}