#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
string s,l="hello";
int n=0;
int main(){
	cin>>s;
	for (int i=0; i<s.length(); i++) {
		if (s[i]==l[n]) n++;         
		if (n==5) break;
		}
	if (n==5)  cout<<"YES"; else cout<<"NO";

     
     
     }