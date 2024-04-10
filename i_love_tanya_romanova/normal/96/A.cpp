#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define y1 aasdfasdfasdf
using namespace std;
string st;
long n,s,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;
s=1;
for (int i=1;i<st.length();i++)
{if (st[i]==st[i-1])s++; else s=1;if (s>6)ans++;}
if (ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
cin.get();cin.get();cin.get();
return 0;
}