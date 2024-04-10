#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
string st1,st2,st;
int main(){
  //  freopen("C:/input.txt","r",stdin);
   // freopen("C:/output.txt","w",stdout);
   cin>>st1;
   cin>>st2;
   for (int i=0;i<st1.length();i++)
   {st+=(st1[i]-48)^(st2[i]-48)+48;}
   cout<<st<<endl;
cin.get();cin.get();cin.get();
return 0;
}