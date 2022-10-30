#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

#define PII pair < int , int >
int T , N , M , arr[13][2003] , mx[2003] , id[2003];

int mat[5][5] , ans;

void dfs(int x){
	if(x > N || x > M){
		int sum = 0;
		for(int i = 0 ; i < N ; ++i){
			int mx = 0;
			for(int j = 0 ; j < N ; ++j)
				mx = max(mx , mat[i][j]);
			sum += mx;
		}
		ans = max(ans , sum); return;
	}
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j)
			mat[(i + j) % N][x - 1] = arr[j + 1][id[x]];
		dfs(x + 1);
	}
}

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> M; ans = 0; memset(mx , 0 , sizeof(mx)); 
		memset(mat , 0 , sizeof(mat));
		for(int i = 1 ; i <= N ; ++i){
			for(int j = 1 ; j <= M ; ++j){
				cin >> arr[i][j];
				mx[j] = max(mx[j] , arr[i][j]);
			}
		}
		for(int i = 1 ; i <= M ; ++i) id[i] = i;
		sort(id + 1 , id + M + 1 , [&](int A , int B){return mx[A] > mx[B];});
		dfs(1); cout << ans << endl;
	}
	return 0;
}