#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define all(a) a.begin(), a.end()

int main()
{ 
	string s1, s2, s3;
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);

	int c1 = count(all(s1), 'u')+count(all(s1), 'a')+count(all(s1), 'o')+count(all(s1), 'e')+count(all(s1), 'i');
	int c2 = count(all(s2), 'u')+count(all(s2), 'a')+count(all(s2), 'o')+count(all(s2), 'e')+count(all(s2), 'i');
	int c3 = count(all(s3), 'u')+count(all(s3), 'a')+count(all(s3), 'o')+count(all(s3), 'e')+count(all(s3), 'i');
	if (c1 == 5 && c2 == 7 && c3 == 5)
		cout << "YES";
	else
		cout << "NO";	

};