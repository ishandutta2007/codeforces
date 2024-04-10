#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main() {
	// your code goes here
	string s,l;
	cin>>s;
	int k=2;
	l = s ;
    if (s.size() == 1 || s.size() == 2)
    {
        cout << s << endl;
        return 0;
    }
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e')
            s[i] = '*';
		if (i >= k && (s[i-2] != s[i-1] || s[i-1] != s[i]) 
				   && (s[i] != '*' && s[i-1] != '*' && s[i-2] != '*')) {
					k = i+2;
					cout<<" ";
				   	
				   	
				   }
					cout<<l[i];
		
	}
	return 0;
}