#include<bits/stdc++.h>
using namespace std;

const int _ = 1003 , MOD = 998244353;
int N , K , arr[_] , num[_][_] , ans;
int add(int a , int b){return a + b >= MOD ? a + b - MOD : a + b;}

int main(){
	cin >> N >> K; for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
	sort(arr + 1 , arr + N + 1);
	for(int i = 1 ; i <= 1e5 / (K - 1) ; ++i){
		int pos = 0;
		for(int j = 1 ; j <= N ; ++j){
			memset(num[j] , 0 , sizeof(int) * (K + 1)); num[j][1] = j;
			while(arr[j] - arr[pos + 1] >= i) ++pos;
			for(int k = 2 ; k <= K ; ++k) num[j][k] = add(num[pos][k - 1] , num[j - 1][k]);
		}
		ans = add(ans , num[N][K]);
	}
	cout << ans; return 0;
}