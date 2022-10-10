#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &x: a){
		cin >> x;
	}
	sort(a.begin(), a.end(), greater<int>());
	if(a[0] >= a[1] + a[2]){
		cout << "NO\n";
	}
	else{
		swap(a[0], a[1]);
		cout << "YES\n";
		for(auto x: a){
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}