#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n;
char buf[3005];

int main(){
	cin >> n >> buf;
	if(count(buf, buf + n, '.') == n){
		cout << n;
		return 0;
	}
	int lst = 0, act = 0, ret = 0;
	for(int i=0; i<n; i++){
		if(buf[i] == 'L'){
			if(act == 2){
				if(i%2 == lst%2) ret++;
			}
			lst = i;
			act = 1;
		}
		if(buf[i] == 'R'){
			if(act == 1) ret += i - lst - 1;
			act = 2;
			lst = i;
		}
	}
	for(int i=0; i<n; i++){
		if(buf[i] != '.'){
			if(buf[i] == 'R') ret += i;
			break;
		}
	}
	reverse(buf, buf + n);
	for(int i=0; i<n; i++){
		if(buf[i] != '.'){
			if(buf[i] == 'L') ret += i;
			break;
		}
	}
	cout << ret;
}