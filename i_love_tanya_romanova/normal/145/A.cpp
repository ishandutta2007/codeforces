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
#define EPS 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
string st1,st2;
long q,ans,w,s1,s2;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st1>>st2;

for (int i=0;i<st1.size();i++)
{
    if (st1[i]=='4')s1++;
}


for (int i=0;i<st1.size();i++)
{
    if (st2[i]=='4')s2++;
}

ans=abs(s1-s2);

if (s1<s2)swap(st1,st2);

q=ans;
for (int i=0;i<st1.size();i++)
if (st1[i]!=st2[i])w++;


for (int i=0;i<st1.size();i++)
{if (st1[i]=='4'&&st2[i]=='7'&&q>0){--q;--w;}}

ans+=w/2;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}