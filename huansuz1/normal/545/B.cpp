#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

 using namespace std;
 string s,l,p;
 int x,y,z=0;
 int main(){
 cin>>s>>l;
 for (int i=0; i<s.length(); i++)
    if (s[i]!=l[i]) z++;
 if (z%2==1) {cout<<"impossible"; return 0;}
 for (int i=0; i<s.length(); i++)    {
    if (s[i]!=l[i] && x<y) {x++; p+=s[i];} else 
        if (s[i]!=l[i]) {y++; p+=l[i];} else
            p+=s[i];
 }
 cout<<p;
 




    return 0;
 }