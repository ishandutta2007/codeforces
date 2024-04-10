#include<bits/stdc++.h>
using namespace std;

const int _ = 3003 , __ = 2e5 + 7; struct Edge{int end , upEd , f;}Ed[__]; 
int head[_] , cntEd = 1 , S , T , C;
void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}
void addE(int a , int b , int c){addEd(a , b , c); addEd(b , a , 0);}

int dep[_] , cur[_]; queue < int > q;
bool bfs(){
	memset(dep , 0 , sizeof(int) * (C + 1)); while(!q.empty()) q.pop();
	dep[S] = 1; q.push(S);
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(!dep[Ed[i].end] && Ed[i].f){
				dep[Ed[i].end] = dep[t] + 1; q.push(Ed[i].end);
				if(Ed[i].end == T){memcpy(cur , head , sizeof(int) * (C + 1)); return 1;}
			}
	}
	return 0;
}

int dfs(int x , int mn){
	if(x == T) return mn;
	int sum = 0;
	for(int &i = cur[x] ; i ; i = Ed[i].upEd)
		if(dep[Ed[i].end] == dep[x] + 1 && Ed[i].f){
			int t = dfs(Ed[i].end , min(mn - sum , Ed[i].f)); Ed[i].f -= t; Ed[i ^ 1].f += t;
			if((sum += t) == mn) break;
		}
	return sum;
}

int N , A[_] , B[_] , id[_];

int main(){
	cin >> N; S = 0; T = C = N + 1; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	int sum = 0; for(int i = 1 ; i <= N ; ++i){cin >> B[i]; if(B[i] > 0){sum += B[i]; addE(S , i , B[i]);} else addE(i , T , -B[i]);}
	for(int i = 1 ; i <= N ; ++i){for(int j = 1 ; j <= A[i] ; ++j){if(id[j] && A[i] % j == 0) addE(i , id[j] , 1e9);} id[A[i]] = i;}
	while(bfs()) sum -= dfs(S , 1e9);
	cout << sum; return 0;
}