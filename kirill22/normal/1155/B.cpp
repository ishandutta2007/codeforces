#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int tmp = 0;
	for(int i = 0;i < n - 10;i++){
		if(s[i] == '8'){
			tmp++;
		}
	}
	int x = n - 10;
	if (tmp > x / 2){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	
	return 0;
}