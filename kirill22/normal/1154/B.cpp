#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	if (n == 1){
		cout << 0;
		return 0;
	}
	if (n == 2){
		if ((a[1] - a[0]) % 2 == 0){
			cout << (a[1] - a[0]) / 2;
		}
		else{
			cout << a[1] - a[0];
		}
		return 0;
	}
	int co = 1;
	for(int i=1;i<n;i++){
		if (a[i] !=a[i-1]){
			co++;
		}
	}
	if (co == 1){
		cout << 0;
		return 0;
	}
	if (co == 2){
		if ((a[n - 1] - a[0]) % 2 == 0){
			cout << (a[n - 1] - a[0]) / 2;
		}
		else{
			cout << a[n  - 1] - a[0];
		}
		return 0;
	}

	int ans = -1;
	for(int i=0;i<n;i++){
		int tmp = a[i];
		int ansi = 0;
		for(int u=0;u<n;u++){
			if(a[u]==tmp){
				continue;
				
			}
			else{
				if (ansi == 0){
					ansi =abs(a[u]-tmp);
				}
				else if (abs(a[u]-tmp)!= ansi){
					ansi = -1;
					break;
				}
			}
		}
		if (ansi !=-1){
			if(ans == -1){
				ans = ansi;
			}
			else{
				ans=min(ans,ansi);
			}
		}
	}
	cout << ans;
}