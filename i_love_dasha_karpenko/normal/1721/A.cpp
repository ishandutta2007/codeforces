//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n';

void solve(){
	map<char,int> M;
	for(int i = 0;i<4;i+=1){
		char ch;
		cin>>ch;
		M[ch] += 1;
	}
	cout<<int(M.size())-1<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}