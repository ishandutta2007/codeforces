#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int a,b,k;
	cin >> a >> b >> k;
	int n = a+b;
	
	if(b==1){
		if(k>0){
			cout << "No\n";
		}
		else{
			cout << "Yes\n";
			cout << 1;
			for(int i = 0; i<a; i++){
				cout << 0;
			}
			cout << "\n";
			cout << 1;
			for(int i = 0; i<a; i++){
				cout << 0;
			}
			cout << "\n";
		}
		return 0;
	}
	if(a==0){
		if(k>0){
			cout << "No\n";
		}
		else{
			cout << "Yes\n";
			for(int i = 0; i<b; i++){
				cout << 1;
			}
			cout << "\n";
			for(int i = 0; i<b; i++){
				cout << 1;
			}
			cout << "\n";
		}
		return 0;
	}
	if(n<=k+1){
		cout << "No\n";
		return 0;
	}
	set<int>s;
	for(int i = 1; i<n; i++){
		s.insert(i);
	}
	vector<int>ans(n);
	vector<int>ans2(n);
	ans[0] = 1; ans2[0] = 1;
	ans[1] = 1;
	ans2[k+1] = 1;
	s.erase(1); s.erase(k+1);
	for(int i = 0; i<b-2; i++){
		int v = *s.begin(); s.erase(s.begin());
		ans[v] = 1;
		ans2[v] = 1;
	}
	cout << "Yes\n";
	for(int i = 0; i<n; i++){
		cout << ans[i];
	} 
	cout << "\n";
	for(int i = 0; i<n; i++){
		cout << ans2[i];
	}
	cout << "\n";
	return 0;
}