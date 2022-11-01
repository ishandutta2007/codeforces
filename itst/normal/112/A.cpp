#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s1 , s2;
	cin >> s1 >> s2;
	for(int i = 0 ; i < s1.size() ; i++)
	{
		if(s1[i] >= 'A' && s1[i] <= 'Z')	s1[i] += 'a' - 'A';
		if(s2[i] >= 'A' && s2[i] <= 'Z')	s2[i] += 'a' - 'A';
	}
	cout << s1.compare(s2);
	return 0;
}