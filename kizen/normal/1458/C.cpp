#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)1004;
int T, N, M;
vector<vector<int>> a;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T--){
		cin >> N >> M;
		a.clear(); a.resize(N * N);
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				int in; cin >> in;
				a[i * N + j] = {i, j, in - 1};
			}
		}
		vector<int> plus, rot;
		plus = {0, 0, 0}, rot = {0, 1, 2};
		for(int i = 1; i <= M; ++i){
			char c; cin >> c;
			if(c == 'D'){
				plus[0] = (plus[0] + 1) % N;
			}
			else if(c == 'U'){
				plus[0] = (plus[0] + N - 1) % N;
			}
			else if(c == 'L'){
				plus[1] = (plus[1] + N - 1) % N;
			}
			else if(c == 'R'){
				plus[1] = (plus[1] + 1) % N;
			}
			else if(c == 'I'){
				swap(rot[1], rot[2]);
				swap(plus[1], plus[2]);
			}
			else{
				swap(rot[0], rot[2]);
				swap(plus[0], plus[2]);
			}
		}
		vector<vector<int>> ans(N, vector<int>(N));
		for(int i = 0; i < N * N; ++i){
			ans[(a[i][rot[0]] + plus[0]) % N][(a[i][rot[1]] + plus[1]) % N] = (a[i][rot[2]] + plus[2]) % N;
		}
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				cout << ans[i][j] + 1 << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}