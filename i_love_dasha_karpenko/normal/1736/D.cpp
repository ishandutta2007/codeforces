#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
void solve(){
	int n;
	cin>>n;
	n*=2;
	int last = 0;
	vector<int> shift;
	int start = 0;
	for(int i = 1;i<=n;i+=2){
		char _a;
		char _b;
		cin>>_a>>_b;
		int a = _a-'0';
		int b = _b-'0';
		if (a==b){
			continue;
		}
		if (last==a){
			shift.push_back(i+1);
			last = b;
		}
		else{
			shift.push_back(i);
			last = a;
		}
	}
	if (start!=last){
		cout<<"-1\n";
		return;
	}
	cout<<shift.size()<<' ';
	for(int to:shift){
		cout<<to<<' ';
	}
	cout<<endl;
	for(int i = 1;i<=n;i+=2){
		cout<<i<<' ';
	}
	cout<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}