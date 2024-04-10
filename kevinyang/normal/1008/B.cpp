#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	bool s = true;
	int a,b;
	cin >> a >> b;
	int start = max(a,b);
	for(int i = 0; i<n-1; i++){
		int c,d;
		cin >> c >> d;
		
		int e = min(c,d); int f = max(c,d);
		//cout << "num" << start << " " << e << " " << f << "\n";
		if(start>=f){
			start = f;
		}
		else if(start>=e){
			start = e;
		}
		else{
			s = false;
			break;
		}
	}
	if(s){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}