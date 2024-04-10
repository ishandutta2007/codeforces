#include<bits/stdc++.h>
using namespace std;

int N , A[100003];

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	vector < int > pot; for(int i = N ; i ; --i) if(A[i] == 1) pot.push_back(i);
	vector < pair < int , int > > ans; int col = 1 , p;
	for(int i = 1 ; i <= N ; ++i)
		switch(A[i]){
		case 1: if(pot.size() && pot.back() == i){pot.pop_back(); ans.push_back(make_pair(col++ , i));} break;
		case 2:
			if(pot.empty()){cout << -1; return 0;}
			else{int t = pot.back(); pot.pop_back(); ans.push_back(make_pair(col , i)); ans.push_back(make_pair(col++ , t));}
			break;
		case 3:
			p = i + 1; while(p <= N && (!A[p] || A[p] == 1 && (pot.empty() || pot.back() != p))) ++p;
			if(p > N){cout << -1; return 0;}
			ans.push_back(make_pair(col , i)); ans.push_back(make_pair(col++ , p));
		}
	cout << ans.size() << endl; for(auto t : ans) cout << t.first << ' ' << t.second << endl;
	return 0;
}