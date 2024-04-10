#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 105;

char buf[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		cin >> buf;
		int z = 0, e = 0, ds = 0;
		for(int i = 0; buf[i]; i++){
			ds += (buf[i] - '0');
			if(buf[i] == '0') z++;
			else if((buf[i] - '0') % 2 == 0) e++;
		}
		if(ds % 3 == 0 && (z >= 2 || z >= 1 && e >= 1)) cout << "red\n";
		else cout << "cyan\n";
	}

}