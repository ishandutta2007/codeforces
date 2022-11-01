#include<bits/stdc++.h>
using namespace std;
int main(){
	int dir = 0 , i;
	string s , exp = "hello";
	cin >> s;
	for(i = 0 ; i < 5 && dir < s.size() ; dir++)
		if(exp[i] == s[dir])
			i++;
	if(i - 5)	cout << "NO";
	else	cout << "YES";
	return 0;
}