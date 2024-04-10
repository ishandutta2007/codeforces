#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , k;
	cin >> n >> k;
	if(n < k || (k == 1 && n != 1)){
		cout << -1;
		return 0;
	}
	else	if(n == 1){
		cout << 'a';
		return 0;
	}
	for(int i = 0 ; i < n - k + 2 >> 1 ; i++)
		cout << "ab";
	if(n - k & 1)	 cout << 'a';
	for(int i = 3 ; i <= k ; i++)
		cout << (char)('a' - 1 + i);
	return 0;
}