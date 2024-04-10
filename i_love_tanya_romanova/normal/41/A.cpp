#include <iostream>
#include <math.h>
#include <vector> 
#include <string> 
#include <stdio.h>
#include <algorithm>
#define M_PI 3.14159265358979323846
using namespace std;
string st1,st2;
long i;
int main()
{
//  freopen("input.txt","r",stdin);
 // freopen("output.txt","w",stdout);
cin>>st1>>st2;
if (st1.length()!=st2.length()){cout<<"NO"<<endl; return 0;}
for (i=0;i<st1.length();i++){if (st1[i]!=st2[st2.length()-i-1]){cout<<"NO"<<endl; return 0;};}
cout<<"YES"<<endl;
cin.get();cin.get();cin.get();
return 0;}