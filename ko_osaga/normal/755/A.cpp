#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

int isp(int x){
	for(int i=2; i*i<=x; i++){
		if(x%i == 0) return 0;
	}
	return 1;
}

int main(){
	int n;
	cin >> n;
	for(int i=1; i<=1000; i++){
		if(!isp(i * n + 1)){
			cout << i << endl;
			return 0;
		}
	}
}