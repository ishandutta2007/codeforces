#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;
#define int long long
inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}
const int MAXN = 1e5 + 7;
int N , num , ans;
signed main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		int val = read();
		if(val / 2 >= num){
			ans += num;
			val -= 2 * num;
			ans += val / 3;
			num = val % 3;
		}
		else{
			ans += val / 2;
			num -= val / 2;
			num += val % 2;
		}
	}
	cout << ans;
	return 0;
}