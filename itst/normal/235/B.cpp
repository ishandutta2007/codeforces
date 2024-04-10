#include<bits/stdc++.h>
#define ld long double
//This code is written by Itst
using namespace std;

const int MAXN = 1e5 + 10;
ld p[MAXN] , e[MAXN] , ans;
int N;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	cin >> N;
	for(int i = 1 ; i <= N ; ++i)
		cin >> p[i];
	for(int i = 1 ; i <= N ; ++i){
		e[i] = p[i] * (e[i - 1] + 1);
		ans += p[i] * (2 * e[i - 1] + 1);
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}