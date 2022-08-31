#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
using namespace std;
string st;
long s,ans,p;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;
if (st.size()==1)cout<<0<<endl;
else {
for (int i=0;i<st.size();i++)s+=st[i]-48;
     ans=1;
while (s>9)
{p=0;while (s){p+=s%10;s/=10;}
 s=p;ans++;}
cout<<ans<<endl;
     }
cin.get();cin.get();
return 0;
}