#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

int T , N , val[53][53] , rk[53][53] , fr[103];
vector < int > peo[53]; int pos[53];

void go(bool flg){
	queue < int > q;
	for(int i = 1 ; i <= N ; ++i){
		peo[i].clear(); for(int j = 1 ; j <= N ; ++j) peo[i].push_back(j);
		sort(peo[i].begin() , peo[i].end() , [&](int p , int q){return (val[i][p] < val[i][q]) ^ flg;});
		q.push(i); pos[i] = fr[i] = fr[i + N] = 0;
	}
	for(int i = 1 ; i <= N ; ++i){
		vector < int > tmp; for(int j = 1 ; j <= N ; ++j) tmp.push_back(j);
		sort(tmp.begin() , tmp.end() , [&](int p , int q){return (val[p][i] > val[q][i]) ^ flg;});
		for(int j = 0 ; j < tmp.size() ; ++j) rk[i][tmp[j]] = j + 1;
	}
	while(!q.empty()){
		int t = q.front(); q.pop();
		while(!fr[t]){
			int tar = peo[t][pos[t]++];
			if(!fr[tar + N] || rk[tar][fr[tar + N]] > rk[tar][t]){
				fr[fr[tar + N]] = 0; if(fr[tar + N]) q.push(fr[tar + N]);
				fr[tar + N] = t; fr[t] = tar + N;
			}
		}
	}
}

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= N ; ++j) cin >> val[i][j];
		cout << "B" << endl; char c; cin >> c;
		if(c == 'D') for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= N ; ++j) val[i][j] = -val[i][j];
		int p; cin >> p; go(p > N); while(p != -1){cout << fr[p] << endl; cin >> p;}
	}
	return 0;
}