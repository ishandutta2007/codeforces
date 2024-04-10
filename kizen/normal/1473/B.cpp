#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		string a, b;
		cin >> a >> b;
		string x = a, y = b;
		while((int)x.size() != (int)y.size()){
			if((int)x.size() < (int)y.size()){
				x += a;
			}
			else{
				y += b;
			}
		}
		if(x == y){
			cout << x << '\n';
		}
		else{
			cout << "-1\n";
		}
	}
	return 0;
}