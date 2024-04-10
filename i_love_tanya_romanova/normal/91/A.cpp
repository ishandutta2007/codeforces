#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
string st1,st2;
long l,nx[200000][30],ls[100],ps,ans;
int main(){
    cin>>st1;getline(cin,st2);
    getline(cin,st2);
    l=st1.length();
    
    for (int i=1;i<=26;i++)
  {  nx[l][i]=1000000;ls[i]=1000000;}
    for (int i=l;i;--i)
    {
    for (int j=1;j<=26;j++)
     nx[i][j]=ls[j];
      ls[st1[i-1]-'a'+1]=i;
    }
   
   for (int i=1;i<=26;i++)
   nx[0][i]=ls[i];
      
ps=0;ans=0;l=st2.length();
/*for (int i=1;i<=26;i++)
cout<<nx[0][i]<<endl;
*/
for (int i=1;i<=l;i++)if (nx[0][st2[i-1]-'a'+1]>100000){cout<<-1<<endl; return 0;}
ans=1;
for (int i=1;i<=l;i++)
{if (ps>100000){ps=0;ans++;}
 if (ps==0){ps=nx[ps][st2[i-1]-'a'+1];}
 if (i<l){ps=nx[ps][st2[i]-'a'+1];}
;}
 cout<<ans<<endl;
 
cin.get();cin.get();
return 0;
}