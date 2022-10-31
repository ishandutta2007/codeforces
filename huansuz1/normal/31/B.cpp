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
string s,l[12345];
int k,p,z;

int main() {

    cin>>s;
    for (int i=0; i<s.length(); i++) {
    	if (s[i]=='@') k++;
    	if (s[i]=='@' && (s[i+2]=='@' | s[i+1]=='@' || i==0 || i==s.length()-1) ) {cout<<"No solution"; exit(0);} 
    }
    if (k==0) {cout<<"No solution"; exit(0);}
    z=1;
    for (int i=0; i<s.length(); i++) {
    	l[z]+=s[i];
    	if (s[i-1]=='@' && z<k) z++;
    }
    if (z==1) {cout<<l[1]; exit(0);}
    for (int i=1; i<z; i++)
    	cout<<l[i]<<",";
    	cout<<l[z];

return 0;
}