#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define F first
#define S second
string ans(int n){
	for(int i = 0; 3 * i <= n; i++){
		for(int j= 0; 7 * j <= n; j++){
			if(3 * i + 7 * j == n){
				return "YES";
			}
		}
	}
	return "NO";
}
int main(){
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x ;
		cout << ans(x) << endl;
	}
}