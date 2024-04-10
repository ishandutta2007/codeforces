#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
   
int main(){
	int n,x=-1,z=1;
	string s;
	cin>>s;
	s+='a';
	for (int i=0; i<s.length()-1; i++)                                      
		if (s[i]==s[i+1]) z++; else  {
		if (z>=x) x=z;             z=1;   }
	//  100001000000110101100000
	if (x >= 7) cout<<"YES"; else cout<<"NO";
	return 0;          
}