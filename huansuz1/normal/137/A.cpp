#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

string s;
int z=1,p,m;

int main(){
      	cin>>s;
      	s+='0';
     	for (int i=1; i<s.length(); i++)   {
      		if (s[i]==s[i-1]) z++; else {
      			if (z%5!=0) p++; 
      			p+=z/5;
      			z=1; 
      		} 
        }
        cout<<p;
      return 0;
}