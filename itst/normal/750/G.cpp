#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std;

#define int long long
int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

int poww2[51];
unordered_map < int , int > ans[51][51];

int dfs(int l1 , int l2 , int val){
	if(val < 0) return 0;
	if(l1 <= 0 && l2 <= 0) return val == 0;
	if(poww2[l1 + 1] - l1 - 2 + poww2[l2 + 1] - l2 - 2 < val) return 0;
	if(l1 < l2) l1 ^= l2 ^= l1 ^= l2;
	if(ans[l1][l2].find(val) != ans[l1][l2].end()) return ans[l1][l2][val];
	return ans[l1][l2][val] = dfs(l1 - 1 , l2 , val) + dfs(l1 - 1 , l2 , val - poww2[l1] + 1);
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	poww2[0] = 1;
	for(int i = 1 ; i <= 50 ; ++i)
		poww2[i] = poww2[i - 1] << 1;
	int sum = 0 , val = read();
	for(int i = 0 ; i < 50 ; ++i)
		for(int j = 0 ; j < 50 ; ++j)
			if(poww2[i + 1] + 3 * poww2[j] - 4 <= val){
				int pos = (val - poww2[j] + 1) / (poww2[i + 1] + poww2[j + 1] - 3);
				sum += dfs(i - 1 , j - 1 , val - poww2[j] + 1 - pos * (poww2[i + 1] + poww2[j + 1] - 3));
			}
	printf("%lld\n" , sum);
	return 0;
}