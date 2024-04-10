#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;
string s,l;

int z=0,k=0,x,y=-1,xx,ss;

int main()
{
cin>>s>>l;                        
for (int i=0; i<l.length(); i++){
	if (s[z]==l[i]) z++;
	if (z==s.length()) { y=i; break; }
}
int z=s.length()-1;
for (int i=l.length()-1; i>=0; i--){
	if (s[z]==l[i] && z==0) {x=i; break;}
	if (s[z]==l[i]) z--;
}


//cout<<x<<" "<<y<<endl;
if (y==-1 || y>x) { cout<<0; exit(0);}

	cout<<x-y;
	
	return 0;
}