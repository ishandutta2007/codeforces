#include<bits/stdc++.h>
using namespace std;

int N , Q; vector < int > qry[13]; int arr[43]; bool vis[43];

bool solve(int x){
	if(x == Q + 1){
		bool flg = 1;
		for(int i = 1 ; i <= N ; ++i){
			if(!vis[i]) return 0;
			if(arr[i]) flg = 0;
			if(!flg && !arr[i]) return 0;
		}
		return 1;
	}
	int tarr[43]; bool tvis[43]; memcpy(tvis , vis , sizeof(vis)); memcpy(tarr , arr , sizeof(arr));
	int cnt = 0 , cnt0 = 0; for(auto t : qry[x]){cnt += !vis[t]; cnt0 += vis[t] && !arr[t]; vis[t] = 1;}
	for(int j = 0 ; j < qry[x].size() ; ++j) arr[qry[x][j]] = j >= cnt0;
	for(int i = 0 ; i <= cnt ; ++i){if(!solve(x + 1)){return 0;} if(i != cnt) arr[qry[x][i + cnt0]] = 0;}
	memcpy(arr , tarr , sizeof(arr)); memcpy(vis , tvis , sizeof(vis)); return 1;
}

int main(){
	cin >> N >> Q; if(N == 1){cout << "ACCEPTED"; return 0;}
	for(int i = 1 ; i <= Q ; ++i){
		int sz; cin >> sz; for(int j = 1 ; j <= sz ; ++j){int x; cin >> x; qry[i].push_back(x);}
	}
	cout << (solve(1) ? "ACCEPTED" : "REJECTED"); return 0;
}