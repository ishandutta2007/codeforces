#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n;
	cin >> s >> n;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if(s[i] - 'a' - n < 0)
			s[i] -= 32;
	}
	cout << s;
	return 0;
}