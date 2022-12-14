#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int T , N , K , A[10] , sgn[10]; bool findans;

void dfs(int x , bool flg , int sum){
	if(x ==N){findans |= flg && sum == 0; return;}
	sgn[x] = 1; dfs(x + 1 , 1 , sum + abs(A[x]));
	sgn[x] = 0; dfs(x + 1 , flg , sum);
	sgn[x] = -1; dfs(x + 1 , 1 , sum - abs(A[x]));
}

int main(){
	for(T = read() ; T ; --T){
		findans = 0; cin >> N; for(int i = 0 ; i < N ; ++i) cin >> A[i];
		dfs(0 , 0 , 0); cout << (findans ? "YES" : "NO") << endl;
	}
	return 0;
}