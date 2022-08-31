#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
const int Q = 25, N = 1100;
vector<int> does_not_come[Q];
int ans[N], M[N], res[Q][N];// bitmask of not occuring
int main(){
    vector<bool> valid(10005, 1);
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	if(n <= 20){
		for(int i = 1; i <= n; i++){
			cout << n - 1 << endl;
			for(int j = 1; j <= n; j++) if(j != i) cout << j << " ";
			cout<<endl;	
			fflush(stdout);
			for(int j = 1; j <= n; j++)
				cin >> res[i][j];
			ans[i] = res[i][i];
		}
		cout << -1 << endl;
		for(int i = 1; i <= n; i++) cout << ans[i] << " ";
		return 0;	
	}
	int cnt = 0;
	for(int j = 0; j < (1 << 20) && cnt < n; j++){
		if(__builtin_popcount(j) == 10){
			++cnt;
			M[cnt] = j;
		}
	}
	for(int q = 0; q < 20; q++){
		int size = 0;
		for(int i = 1; i <= n; i++) if(!(M[i] & (1 << q))) size ++;
		if(size == 0){
		    valid[q] =0;
			cout << n << endl;
			for(int i = 1; i <= n; i ++) cout << i << " ";
		}
		else{
			cout << size << endl;
			for(int i = 1; i <= n; i++) if(!(M[i] & (1 << q))) cout << i << " ";
		}
		cout << endl;
		fflush(stdout);
		for(int i = 1; i <= n; i++) cin >> res[q][i];
	}
	cout << -1 << endl;
	for(int i = 1; i <= n; i++){
		ans[i] = 1e9 + 10;
		for(int q = 0; q < 20; q++) if(valid[q] && (M[i] & (1 << q))) ans[i] = min(ans[i], res[q][i]);
		cout << ans[i] << " ";
	}
	return 0;
}