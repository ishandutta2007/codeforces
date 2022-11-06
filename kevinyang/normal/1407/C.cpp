#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	set<int>s;
	set<int>rem;
	for(int i = 1; i<=n; i++){
		s.insert(i);
		rem.insert(i);
	}
	vector<int>ans(n+1);
	while(s.size()>1){
		int a = *s.begin();
		s.erase(a);
		int b = *s.begin();
		s.erase(b);
		cout << "? " << a << " " << b << endl;
		int c;
		cin >> c;
		cout << "? " << b << " " << a << endl;
		int d;
		cin >> d;
		if(c<d){
			ans[b] = d;
			s.insert(a);
			rem.erase(d);
		}
		else{
			ans[a] = c;
			s.insert(b);
			rem.erase(c);
		}
	}
	ans[*s.begin()] = *rem.begin();
	cout << "! ";
	for(int i = 1; i<=n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}