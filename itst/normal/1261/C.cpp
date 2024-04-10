#include<bits/stdc++.h>
using namespace std;

const int _ = 1e6 + 7; string pot[_];
vector < int > sum[_]; int N , M;
vector < int > cover[_]; string ans[_];
int qry(int x2 , int y2 , int x1 , int y1){
	return sum[x2][y2] - (x1 ? sum[x1 - 1][y2] : 0) - (y1 ? sum[x2][y1 - 1] : 0) + (x1 && y1 ? sum[x1 - 1][y1 - 1] : 0);
}

bool check(int mid){
	for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < M ; ++j)
			cover[i][j] = 0;
	for(int i = N - 1 ; i >= 2 * mid ; --i)
		for(int j = M - 1 ; j >= 2 * mid ; --j)
			if(qry(i , j , i - 2 * mid , j - 2 * mid) == (2 * mid + 1) * (2 * mid + 1)){
				++cover[i][j]; if(i - 2 * mid) --cover[i - 2 * mid - 1][j];
				if(j - 2 * mid) --cover[i][j - 2 * mid - 1];
				if(i - 2 * mid && j - 2 * mid) ++cover[i - 1 - 2 * mid][j - 1 - 2 * mid];
			}
	for(int i = N - 1 ; ~i ; --i)
		for(int j = M - 2 ; ~j ; --j)
			cover[i][j] += cover[i][j + 1];
	for(int i = N - 2 ; ~i ; --i)
		for(int j = M - 1 ; ~j ; --j)
			cover[i][j] += cover[i + 1][j];
	for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < M ; ++j)
			if(qry(i , j , i , j) && !cover[i][j]) return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M;
	for(int i = 0 ; i < N ; ++i){cin >> pot[i]; sum[i].resize(M); for(int j = 0 ; j < M ; ++j) sum[i][j] = pot[i][j] == 'X';}
	for(int i = 0 ; i < N ; ++i) for(int j = 1 ; j < M ; ++j) sum[i][j] += sum[i][j - 1];
	for(int i = 1 ; i < N ; ++i) for(int j = 0 ; j < M ; ++j) sum[i][j] += sum[i - 1][j];
	
	int L = 0 , R = (min(N , M) - 1) / 2;
	for(int i = 0 ; i < N ; ++i) cover[i].resize(M);
	while(L < R){int mid = (L + R + 1) >> 1; check(mid) ? L = mid : R = mid - 1;}
	cout << L << endl; int mid = L; 
	for(int i = 0 ; i < N ; ++i) ans[i] = string(M , '.');
	for(int i = N - 1 ; i >= 2 * mid ; --i)
		for(int j = M - 1 ; j >= 2 * mid ; --j)
			if(qry(i , j , i - 2 * mid , j - 2 * mid) == (2 * mid + 1) * (2 * mid + 1))
				ans[i - mid][j - mid] = 'X';
	for(int i = 0 ; i < N ; ++i) cout << ans[i] << '\n';
	return 0;
}