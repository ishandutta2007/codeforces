#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

namespace flow{
	const int __ = 1e7 + 7 , _ = 1e5 + 7;
	struct Edge{
		int end , upEd , f , c;
	}Ed[__];
	int head[_] , dis[_] , pre[_] , f[_] , cntEd = 1 , S , T;
	queue < int > q; bool vis[_];

	void addEd(int a , int b , int c , int d){
		Ed[++cntEd] = (Edge){b , head[a] , c , d};
		head[a] = cntEd;
	}

	void addE(int a , int b , int c , int d = 0 , bool flg = 0){
		//cerr << a << ' ' << b << ' ' << c << '.' << d << endl;
		addEd(a , b , c , d); addEd(b , a , c * flg , -d);
	}
	
	bool SPFA(){
		memset(dis , 0x3f , sizeof(int) * (T + 1));
		while(!q.empty()) q.pop();
		dis[S] = 0; q.push(S); f[S] = 1e9;
		while(!q.empty()){
			int t = q.front(); q.pop(); vis[t] = 0;
			for(int i = head[t] ; i ; i = Ed[i].upEd)
				if(Ed[i].f && dis[Ed[i].end] > dis[t] + Ed[i].c){
					dis[Ed[i].end] = dis[t] + Ed[i].c;
					pre[Ed[i].end] = i;
					f[Ed[i].end] = min(f[t] , Ed[i].f);
					if(!vis[Ed[i].end]){
						q.push(Ed[i].end);
						vis[Ed[i].end] = 1;
					}
				}
		}
		return dis[T] != 0x3f3f3f3f;
	}

	int EK(int s , int t){
		S = s; T = t; int ans = 0;
		while(SPFA()){
			int cur = T;
			while(cur != S){
				Ed[pre[cur]].f -= f[T];
				Ed[pre[cur] ^ 1].f += f[T];
				ans += f[T] * Ed[pre[cur]].c;
				cur = Ed[pre[cur] ^ 1].end;
			}
		}
		return ans;
	}
}
int N , K , M , c , d , s[61] , t[61] , num[61];

#define id(i , j) ((i) * N + (j))

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	cin >> N >> M >> K >> c >> d;
	for(int i = 1 ; i <= K ; ++i){
		int a; cin >> a; ++num[a];
	}
	for(int i = 1 ; i <= M ; ++i)
		cin >> s[i] >> t[i];
	for(int i = 2 ; i <= N ; ++i)
		if(num[i])
			flow::addE(0 , id(0 , i) , num[i]);
	for(int i = 0 ; i < N + K ; ++i){
		flow::addE(id(i + 1 , 1) , id(N + K + 1 , 1) , 1e9);
		for(int j = 1 ; j <= M ; ++j){
			for(int k = 1 ; k <= min(25 , K) ; ++k){
				flow::addE(id(i , s[j]) , id(i + 1 , t[j]) , 1 , d * (2 * k - 1) + c);
				flow::addE(id(i , t[j]) , id(i + 1 , s[j]) , 1 , d * (2 * k - 1) + c);
			}
		}
		for(int j = 2 ; j <= N ; ++j)
			flow::addE(id(i , j) , id(i + 1 , j) , 1e9 , c);
	}
	cout << flow::EK(0 , id(N + K + 1 , 1));
	return 0;
}