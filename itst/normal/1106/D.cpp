#include<bits/stdc++.h>
#define int long long
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
	    if(c == '-')
			f = 1;
        c = getchar();
    }
    while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 1e5 + 7;
priority_queue < int , vector < int > , greater < int > > q;
int ans[MAXN] , head[MAXN] , cntEd , N , M;
bool vis[MAXN];
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

inline void tz(int x){
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!vis[Ed[i].end]){
			vis[Ed[i].end] = 1;
			q.push(Ed[i].end);
		}
}

signed main(){
	#ifndef ONLINE_JUDGE
	//freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
	#endif
	N = read();
	M = read();
	for(int i = 1 ; i <= M ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
	vis[1] = 1;
	ans[1] = 1;
	tz(1);
	int cnt = 1;
	while(!q.empty()){
		int t = q.top();
		q.pop();
		ans[++cnt] = t;
		tz(t);
	}
	for(int i = 1 ; i <= N ; ++i)
		cout << ans[i] << ' ';
	return 0;
}