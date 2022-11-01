#include<bits/stdc++.h>
using namespace std;

#define int long long
int N; vector < int > pot , ans;

signed main(){
	cin >> N; for(int i = 0 ; i < 1 << 13 ; ++i) if(__builtin_popcount(i) == 6) pot.push_back(i);
	for(int p = 0 ; p < 13 ; ++p){
		vector < int > val; for(int q = 1 ; q <= N ; ++q) if(pot[q] >> p & 1) val.push_back(q);
		if(val.size()){
			cout << "? " << val.size() << ' '; for(int i = 0 ; i < val.size() ; ++i) cout << val[i] << ' ';
			cout << endl; int x; cin >> x; ans.push_back(x);
		}else ans.push_back(0);
	}
	cout << "! ";
	for(int i = 1 ; i <= N ; ++i){
		int sum = 0; for(int j = 0 ; j < 13 ; ++j) if(!(pot[i] >> j & 1)) sum |= ans[j];
		cout << sum << ' ';
	}
	return 0;
}