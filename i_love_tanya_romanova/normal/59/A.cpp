#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
string st1,st2,st;
long n,a;
int main(){
  //  freopen("C:/input.txt","r",stdin);
   // freopen("C:/output.txt","w",stdout);
cin>>st;n=st.length();
for (int i=0;i<n;i++)if (st[i]>='a')a++;else a--;
for (int i=0;i<n;i++)
{if (a>=0&&st[i]<'a')st[i]=st[i]+'a'-'A';
 if (a<0&&st[i]>='a')st[i]=st[i]+'A'-'a';}
 cout<<st<<endl; 
cin.get();cin.get();cin.get();
return 0;
}