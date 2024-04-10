#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	string a, b;
	cin >> a>> b;
	reverse(b.begin(), b.end());
	cout << atoi(b.c_str()) + atoi(a.c_str()) << endl;
	
	return 0;
}