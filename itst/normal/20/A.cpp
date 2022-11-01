#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int i = s.size();
	while(s[--i] == '/' && i);
	for(int j = 0 ; j <= i ; j++)
		if(s[j] != '/' || !j || s[j - 1] != '/')
			cout << s[j];
	return 0;
}