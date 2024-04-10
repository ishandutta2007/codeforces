#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int qq;
	cin >> qq;
	while(qq --){
		int b, w;
		cin >> b >> w;
		if(b - 1 > 3 * w || w - 1 > 3 * b){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
			int m = min(b, w);
			for(int i = 2; i < 2 * m + 2; i ++){
				cout << "2 " << i << "\n";
			}
			b -= m, w -= m;
			for(int i = 2; b && i < 2 * m + 2; i ++, b --){
				if(i & 1){
					cout << "3 " << i - 1 << "\n";
				}
				else{
					cout << "1 " << i << "\n";
				}
			}
			if(b){
				cout << "2 1\n";
			}
			for(int i = 2; w && i < 2 * m + 2; i ++, w --){
				if(i & 1){
					cout << "3 " << i << "\n";
				}
				else{
					cout << "1 " << i + 1 << "\n";
				}
			}
			if(w){
				cout << "2 " << 2 * m + 2 << "\n";
			}
		}
	}
	return 0;
}