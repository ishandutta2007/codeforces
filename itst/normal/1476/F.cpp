#include<bits/stdc++.h>
using namespace std;

const int _ = 3e5 + 7; int T , N , L[_] , pre[_][2];
vector < int > pot[_]; int to[20][_] , alto[20][_] , logg2[_];

int qst(int arr[20][_] , int l , int r){int t = logg2[r - l + 1]; return max(arr[t][l] , arr[t][r - (1 << t) + 1]);}
void build(int arr[20][_]){
	for(int i = 1 ; 1 << i <= N ; ++i)
		for(int j = 1 ; j + (1 << i) - 1 <= N ; ++j)
			arr[i][j] = max(arr[i - 1][j] , arr[i - 1][j + (1 << (i - 1))]);
}

void init(){
	for(int i = 1 ; i <= N ; ++i){pre[i][0] = pre[i][1] = -1; pot[i].clear();}
	int posr = N - 1;
	for(int i = N ; i ; --i){
		posr -= i == posr;
		for(int j = posr ; j && j >= i - L[i] ; --j) pot[j].push_back(i);
		while(pot[posr].size() == 40) --posr;
	}
	for(int i = 1 ; i <= N ; ++i){to[0][i] = i + L[i];} build(to);
    vector < pair < int , int > > stk; alto[0][N] = N; stk.push_back(make_pair(N , N));
	for(int i = N - 1 ; i ; --i){
		if(!L[i]){stk.push_back(make_pair(i , alto[0][i] = i)); continue;}
		while(stk.size() >= 2 && stk[stk.size() - 2].first <= i + L[i]) stk.pop_back();
		alto[0][i] = stk.back().second; stk.back().first = i;
	}
	build(alto);
}

int qrygo(int L , int R){
	if(L == R) return R - 1;
	int tor = min(N , qst(to , L , R - 1)); return tor <= R ? tor : qst(alto , R + 1 , tor);
}

int solve(int x , int y){
	if(x > N) return 1;
	if(~pre[x][y]) return pre[x][y];
	for(auto t : pot[x]){int r = qrygo(x + y , t); if(solve(r + 1 , r + 1 == t)) return pre[x][y] = t;}
	return pre[x][y] = 0;
}

char ans[_];
void getans(){
	int x = 1 , y = 0; vector < int > pot;
	while(x <= N){int c = pre[x][y] , r = qrygo(x + y , c); pot.push_back(c); y = c == r + 1; x = r + 1;}
	for(int i = 1 ; i <= N ; ++i) ans[i] = 'R';
	for(auto t : pot) ans[t] = 'L';
	ans[N + 1] = 0; puts("YES"); puts(ans + 1);
}

int main(){
	ios::sync_with_stdio(0); for(int i = 2 ; i <= 3e5 ; ++i) logg2[i] = logg2[i >> 1] + 1;
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> L[i];
		init(); if(!solve(1 , 0)) puts("NO"); else getans();
	}
	return 0;
}