#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, m;
	cin >> n >> m;
	char a[n][m];
	int kol = 0;
	bool f = false;
	for(int i = 0;i < n;i++){
		for(int u = 0;u < m;u++){
			cin >> a[i][u];
			if(a[i][u] == '*'){
				kol++;
			}
		}
	}
	for(int i = 1;i < n - 1;i++){
		for(int u = 1;u < m - 1;u++){
			if(a[i][u] == '*' && a[i - 1][u] == '*' && a[i + 1][u] == '*' && a[i][u - 1] == '*' && a[i][u + 1] == '*'){
				int tmp = 1;
				int ii = i - 1,uu = u;
				while(ii >= 0 && a[ii][uu] == '*'){
					tmp++;
					ii--;
				}
				ii = i + 1,uu = u;
				while(ii < n  && a[ii][uu] == '*'){
					tmp++;
					ii++;
				}
				ii = i ,uu = u + 1;
				while(uu < m  && a[ii][uu] == '*'){
					tmp++;
					uu++;
				}
				ii = i ,uu = u - 1;
				while(uu >= 0  && a[ii][uu] == '*'){
					tmp++;
					uu--;
				}
				if(tmp == kol){
					f = true;
				}
			}
		}
	}
	if(f){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	
}