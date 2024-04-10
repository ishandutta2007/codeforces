#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long a[12],z;
string s;

int main(){
    cin >> a[1] >> a[2] >> a[3] >> a[4] >> s;
    for (int i = 0; i < s.length(); i++)
   		z += a[s[i]-'0']; 	
   	cout<<z;

	return 0;
}