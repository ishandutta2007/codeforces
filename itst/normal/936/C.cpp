#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

int N , pot[27];
char s[2007] , tmp[2007] , t[2007] , step[2007][2007];
vector < int > ans;

void shift(int x){
	ans.push_back(x);
	for(int i = x + 1 ; i <= N ; ++i)
		tmp[i] = s[i - x];
	for(int i = 1 ; i <= x ; ++i)
		tmp[i] = s[N - x + i];
	reverse(tmp + 1 , tmp + x + 1);
	memcpy(s , tmp , sizeof(tmp));
}

signed main(){
	scanf("%d %s %s" , &N , s + 1 , t + 1);
	for(int i = 1 ; i <= N ; ++i){
		++pot[s[i] - 'a'];
		--pot[t[i] - 'a'];
	}
	for(int i = 0 ; i < 26 ; ++i)
		if(pot[i]){
			puts("-1");
			return 0;
		}
	memcpy(step[0] , t , sizeof(step[0]));
	for(int j = 1 ; 2 * j <= N ; ++j){
		memcpy(step[j] , step[j - 1] , sizeof(step[j]));
		reverse(step[j] + 2 * j + 1 , step[j] + N + 1);
	}
	if(N & 1)
		for(int k = 1 ; k <= N ; ++k)
			if(s[k] == step[N / 2][N])
				shift(N - k);
	int cur = N + 1 - (N & 1);
	for(int j = N / 2 - (N & 1) ; j >= 0 ; --j){
		for(int k = 1 ; k < cur ; ++k)
			if(s[k] == step[j][cur - 1]){
				shift(N - k);
				shift(1);
				break;
			}
		for(int k = N - cur + 3 ; k <= N ; ++k)
			if(s[k] == step[j][cur - 2]){
				shift(N - k + 1);
				shift(k - (N - cur + 3));
				break;
			}
		cur -= 2;
	}
	cout << ans.size() << endl;
	for(auto t : ans) cout << t << ' ';
	return 0;
}