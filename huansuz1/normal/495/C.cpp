//mukh1t dauirkhan
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include<string>


using namespace std;


string s;
int x,y,z,p,k,q,z1,z2;


int main() {
cin>>s;
for (int i=0; i<s.length(); i++){
	if (s[i]=='(') 
		x++; 
	else {
		if (s[i]==')') 
			y++; 
		else {z++; q=i;}
	}
	if (x<y+z) {
		cout<<-1; exit(0);
	}
	}
	for (int i=s.length()-1; i>q; i--){
	if (s[i]==')')  z1++; else z2++;                 
	
	if (z2>z1) {
		cout<<-1; 
		exit(0);
	}
	}
	
	
	int k=x-y;
	for (int i=0; i<z; i++)
	{
	if (i!=z-1) cout<<1<<endl; else cout<<k-p;
	p++;
	}
	
	
		
return 0;
}