#include<bits/stdc++.h>
using namespace std;

vector < int > pot; int N;

int solve(vector < int > pot , int fl){
	if(pot.size() <= 1) return pot.size();
	vector < int > pl , pr; for(auto t : pot) (t >> fl & 1 ? pl : pr).push_back(t);
	int vl = solve(pl , fl - 1) , vr = solve(pr , fl - 1);
	return max(vl + !!pr.size() , vr + !!pl.size());
}

signed main(){
	ios::sync_with_stdio(0);
	cin >> N; for(int i = 1 ; i <= N ; ++i){int A; cin >> A; pot.push_back(A);}
	cout << N - solve(pot , 30); return 0;
	
}