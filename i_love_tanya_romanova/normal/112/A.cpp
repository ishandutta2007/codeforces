#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-9
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
long n,p,q,ar[20000];
string st1,st2;
long pr(string st1,string st2)
{for (int i=0;i<st1.size();i++)
{if (st1[i]<st2[i])return -1;
 if (st1[i]>st2[i])return 1;}
 return 0;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st1>>st2;
for (int i=0;i<st1.size();i++)
{if (st1[i]>='A'&&st1[i]<='Z')st1[i]=st1[i]-'A'+'a';}
for (int i=0;i<st2.size();i++)
{if (st2[i]>='A'&&st2[i]<='Z')st2[i]=st2[i]-'A'+'a';}
cout<<pr(st1,st2)<<endl;

cin.get();cin.get();
return 0;
}