#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
bool came[N];
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	a %= b;
	int cnt= 1;
	while(1){
		int d = (10 * a) / b;
		if(d == c){
			cout << cnt<<endl;
			return 0;
		}
		if(came[a]){
			cout << -1;
			return 0;
		}
		came[a] = 1;
		a = (10 * a) % b;
		cnt++;
	}
}