#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1 , s2;
	cin >> s1 >> s2;
	cout << s1[0];
	for(int i = 1 ; i < s1.size() && s1[i] < s2[0] ; i++)
		cout << s1[i];
	cout << s2[0];
	return 0;
}