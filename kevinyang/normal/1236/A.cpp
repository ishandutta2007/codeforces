#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		int total = 0;
		total+=3*(min(b,c/2));
		b-=total/3;
		total+=3*min(a,b/2);
		cout << total << "\n";
	}
	return 0;
}