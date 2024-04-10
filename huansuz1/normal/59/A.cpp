#include <iostream>
#include <string>

using namespace std;

string s;
int z , zz;

int main(){
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= 'a' && s[i] <= 'z') z++; else zz++;
	if ( z >= zz) { 
		for (int i = 0; i < s.length(); i++)
			if (s[i] >= 'A' && s[i] <= 'Z')  
				s[i] = s[i] - 'A' + 'a';

	} else {
	
		for (int i = 0; i < s.length(); i++)
			if (s[i] >= 'a' && s[i] <= 'z')  
				s[i] = s[i] - 'a' + 'A';
	}

	cout << s;




}