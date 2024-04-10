#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n >> s;
	for(int i = n / 2 ; i ; i--)
		if(string(s , 0 , i) == string(s , i , i))
		{
			cout << n - i + 1;
			return 0;
		}
	cout << n;
	return 0;
}