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
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
	string s;
	int n;
	cin >> s >> n;
	if ((s=="front" && n==1)||(s=="back" && n==2)) cout << 'L';
	else cout << 'R';
	return 0;
}