#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, lint> pi;

lint n, a, b, c;

int main(){
	cin >> n >> a >> b >> c;
	lint ret = 1e18;
	for(int i=0; i<22; i++){
		for(int j=0; j<22; j++){
			for(int k=0; k<22; k++){
				if((n + i + j + j + k + k + k) % 4 == 0){
					ret = min(ret, a * i + b * j + c * k);
				}
			}
		}
	}
	cout << ret;
}