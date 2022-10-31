#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
int n,a[1234]; 
string s;
int main(){
	cin>>s;
	if (s[0] >= 'a' && s[0] <= 'z') s[0] = s[0] - 'a' + 'A';
	cout<<s;
}