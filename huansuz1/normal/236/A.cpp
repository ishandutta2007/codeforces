#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
int n=1,a[1234]; 
string s;
int main(){
	cin>>s;
	sort(s.begin() , s.end());
	for (int i=1; i<s.length(); i++)
		if (s[i] != s[i-1]) n++;
	if (n%2==0) cout<<"CHAT WITH HER!"; else cout<<"IGNORE HIM!";
}