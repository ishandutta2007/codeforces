#include<bits/stdc++.h>
using namespace std;

//SAM
const int _ = 2003; int trs[_][10] , fa[_] , len[_] , cnt = 1 , lst = 1; int tolen[_][10];
void append(int x , int c){
	int p = lst , t = ++cnt; len[t] = x; lst = t; while(!trs[p][c]){trs[p][c] = t; p = fa[p];} if(!p){fa[t] = 1; return;}
	int q = trs[p][c]; if(len[q] == len[p] + 1){fa[t] = q; return;}
	int k = ++cnt; len[k] = len[p] + 1; memcpy(trs[k] , trs[q] , sizeof(trs[k]));
	fa[k] = fa[q]; fa[q] = fa[t] = k; while(trs[p][c] == q){trs[p][c] = k; p = fa[p];}
}

void build(){
	vector < int > ch[_]; for(int i = 2 ; i <= cnt ; ++i) ch[fa[i]].push_back(i);
	queue < int > q; for(int i = 0 ; i < 10 ; ++i) if(!trs[1][i]){trs[1][i] = 1; tolen[1][i] = 0;} else tolen[1][i] = 1;
	for(auto t : ch[1]) q.push(t);
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int i = 0 ; i < 10 ; ++i)
			if(trs[t][i]){tolen[t][i] = len[t] + 1;}
			else{tolen[t][i] = tolen[fa[t]][i]; trs[t][i] = trs[fa[t]][i];}
		for(auto x : ch[t]) q.push(x);
	}
}

const int P = 1e9 + 7; string S , X , Y; int N , D , dp[53][28][_][2];
void inc(int &a , int b){a = a + b >= P ? a + b - P : a + b;}
int solve(string num){
	memset(dp , 0 , sizeof(dp)); reverse(num.begin() , num.end());
	for(int i = 1 ; i <= cnt ; ++i) dp[0][D / 2][i][1] = 1;
	for(int i = 1 ; i <= D ; ++i)
		for(int j = 0 ; j <= D / 2 ; ++j)
			for(int k = 1 ; k <= cnt ; ++k)
				for(int t = 0 ; t < 10 ; ++t){
					int nj = j == D / 2 ? j : min(j + 1 , tolen[k][t]) , nk = trs[k][t];
					if(t == num[i - 1] - '0'){inc(dp[i][j][k][0] , dp[i - 1][nj][nk][0]); inc(dp[i][j][k][1] , dp[i - 1][nj][nk][1]);}
					else{inc(dp[i][j][k][t < num[i - 1] - '0'] , dp[i - 1][nj][nk][0]); inc(dp[i][j][k][t < num[i - 1] - '0'] , dp[i - 1][nj][nk][1]);}
				}
	return dp[D][0][1][1];
}

int main(){
	cin >> S >> X >> Y; N = S.size(); D = X.size(); for(int i = 0 ; i < S.size() ; ++i) append(i + 1 , S[i] - '0');
	build(); int pos = D - 1; while(X[pos] == '0'){X[pos--] = '9';} --X[pos]; cout << (solve(Y) - solve(X) + P) % P; return 0;
}