#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7; 
int upd(int x){return x + (x >> 31 & P);}
void inc(int &a , int b){a = upd(a + b - P);}
bool vis[53][53]; vector < int > route[53][53]; int N , M;

int dp[2][53][103]; vector < int > trans[2][2][53][53];

bool extend(deque < int > &que , deque < int > :: iterator it , int dir){
	bool flg = 1;
	if(dir == -1)
		while(it != que.begin() && que.size() <= 2 * N){
			auto it1 = it - 1; flg &= vis[*it1][*it];
			que.insert(que.begin() , route[*it1][*it].begin() , route[*it1][*it].end()); --it;
		}
	else
		while(it + 1 != que.end() && que.size() <= 2 * N){
			auto it1 = it + 1; flg &= vis[*it][*it1];
			que.insert(que.end() , route[*it][*it1].begin() , route[*it][*it1].end()); ++it;
		}
	return flg & (que.size() <= 2 * N);
}

void prepare_trans_00(){
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j)
			if(route[i][j].size() && route[i][j].back() == i){
				deque < int > seq(route[i][j].begin() , route[i][j].end());
				if(extend(seq , --seq.end() , -1)) trans[0][0][seq.front()][j].push_back(seq.size());
			}
}

void prepare_trans_01(){
	bool output = 1;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j){
			auto p = find(route[i][j].begin() , route[i][j].end() , i);
			while(p != route[i][j].end() && p + 1 != route[i][j].end() && *(p + 1) != j)
				p = find(p + 1 , route[i][j].end() , i);
			if(p == route[i][j].end() || p + 1 == route[i][j].end()) continue;
			
			deque < int > seq(route[i][j].begin() , route[i][j].end());
			auto p1 = seq.begin() + (p - route[i][j].begin());
			if(extend(seq , p1 , -1) && extend(seq , p1 + 1 , 1)){
				if(!output){
					cout << seq.size() << endl; for(auto t : seq) cout << t << ' ';
					cout << endl; output = 1;
				}
				trans[0][1][seq.front()][seq.back()].push_back(seq.size() - 1);
			}
		}
	if(!output) cout << 0 << endl << endl;
}

void prepare_trans_10(){
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j)
			if(vis[i][j] && route[i][j].empty())
				trans[1][0][i][j].push_back(1);
}

void prepare_trans_11(){
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j)
			if(route[i][j].size() && route[i][j][0] == j){
				deque < int > seq(route[i][j].begin() , route[i][j].end());
				if(extend(seq , seq.begin() , 1)) trans[1][1][i][seq.back()].push_back(seq.size());
			}
}

int main(){
	cin >> N >> M;
	for(int i = 1 ; i <= M ; ++i){
		int A , B , K; cin >> A >> B >> K;
		vis[A][B] = 1; while(K--){int x; cin >> x; route[A][B].push_back(x);}
	}
	
	prepare_trans_00(); prepare_trans_01(); prepare_trans_10(); prepare_trans_11();
	for(int i = 1 ; i <= N ; ++i) dp[0][i][0] = 1;
	
	for(int len = 0 ; len < 2 * N ; ++len)
		for(int i = 0 ; i < 2 ; ++i)
			for(int j = 1 ; j <= N ; ++j)
				if(dp[i][j][len])
					for(int p = 0 ; p < 2 ; ++p)
						for(int q = 1 ; q <= N ; ++q)
							for(auto t : trans[i][p][j][q])
								if(t + len <= 2 * N) inc(dp[p][q][t + len] , dp[i][j][len]);
	
	for(int len = 1 ; len <= 2 * N ; ++len){
		int sum = 0; for(int j = 1 ; j <= N ; ++j) inc(sum , dp[1][j][len]);
		cout << sum << endl;
	}
	return 0;
}