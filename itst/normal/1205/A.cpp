#include<bits/stdc++.h>
using namespace std;

int ans[200003];

int main(){
	int N; cin >> N;
	if(N % 2 == 0){puts("NO"); return 0;}
	else{
		for(int i = 1 ; i <= N ; ++i){
			ans[i] = (i & 1) ? 2 * i - 1 : 2 * i;
			ans[i + N] = (i & 1) ? 2 * i : 2 * i - 1;
		}
		cout << "YES\n";
		for(int i = 1 ; i <= 2 * N ; ++i) cout << ans[i] << ' ';
	}
	return 0;
}