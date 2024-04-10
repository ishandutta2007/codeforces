#include<bits/stdc++.h>
//This code is written by Itst
#define ll long long
using namespace std;

int num[16] , N;

void dfs(int cur , int deg){
	if(cur > N){
		if(deg == 0){
			puts("YES");
			exit(0);
		}
		return;
	}
	dfs(cur + 1 , (deg + num[cur]) % 360);
	dfs(cur + 1 , (deg - num[cur] + 360) % 360);
}

int main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i)
		cin >> num[i];
	dfs(1 , 0);
	puts("NO");
	return 0;
}