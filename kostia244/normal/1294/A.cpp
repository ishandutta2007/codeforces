#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
	int t,a,b,c,n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> a >> b >> c >> n;
		int r = a+b+c+n;
		if(r % 3 == 0 && a <= r/3 && b <= r/3 && c <= r/3){
			cout << "YES" << endl;
		}
		
		else{
			cout << "NO" << endl;
		}
	}	
	
	return 0;
}