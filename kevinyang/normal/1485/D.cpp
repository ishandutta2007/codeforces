#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	set<int>s;
	for(int i = 1; i<=40; i++){
		s.insert(i*i*i*i);
	}
	vector<vector<int>>arr(17);
	for(int i = 1; i<=16; i++){
		for(int j = i; j<=(int)1e6; j+=i){
			arr[i].push_back(j);
		}
	}
	vector<int>arr2(17);
	for(int i = 1; i<=16; i++){
		for(int nxt: arr[i]){
			if(s.find(abs(720720-nxt))!=s.end()){
				arr2[i] = nxt;
				break;
			}
		}
	}
	int n,m;
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			int x;
			cin >> x;
			if((i+j)%2==0){
				cout << "720720 ";
			}
			else{
				cout << arr2[x] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}