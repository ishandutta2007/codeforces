#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

//char c[9]=('6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A');
string c="6789TJQKA";
bool max(char a, char b)
{
	int o1,o2;
	for (int i=0; i<9; i++) 
		if (c[i]==a) o1=i;
	for (int i=0; i<9; i++) 
		if (c[i]==b) o2=i;
	return o1>o2;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	char c;
	string s,s2;
	cin >> c;
	cin >> s; cin >> s2;
	if (((s[1]==c) && (s2[1]!=c))) cout << "YES";
	else if ((s[1]==s2[1] && max(s[0],s2[0]))) cout << "YES";
	else cout << "NO";
	return 0;
}