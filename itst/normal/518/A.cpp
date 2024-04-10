#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1 , s2;
	cin >> s1 >> s2;
	if(s1 >= s2)
		cout << "No such string";
	else
	{
		s1[s1.size() - 1]++;
		for(int i = s1.size() - 1 ; s1[i] > 'z' && i ; i--)
		{
			s1[i] -= 26;
			s1[i - 1]++;
		}
		if(s1 == s2)
			cout << "No such string";
		else
			cout << s1;
	}
	return 0;
}