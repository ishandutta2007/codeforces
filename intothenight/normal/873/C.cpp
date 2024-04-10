#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> M(n, vector<int>(m));
	for(auto &x: M){
		for(auto &y: x){
			cin >> y;
		}
	}
	int score = 0, rep = 0;
	for(int j = 0; j < m; j ++){
		int cnt = 0;
		deque<int> q;
		for(int i = 0; i < k; i ++){
			q.push_back(M[i][j]);
			cnt += M[i][j];
		}
		int c_score = cnt, c_rep = 0, up_cnt = 0;
		for(int i = 0; i < n - k; i ++){
			up_cnt += M[i][j];
			cnt += M[i + k][j] - M[i][j];
			if(c_score < cnt){
				c_score = cnt;
				c_rep = up_cnt;
			}
		}
		score += c_score, rep += c_rep;
	}
	cout << score << " " << rep;
	return 0;
}