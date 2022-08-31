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
 string st1,st2,z;
 long s,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st1>>st2;
for (int i=1;i<=2000;i++)z+="*";
st1=z+st1+z;

ans=st2.size();

for (int i=0;i<=st1.size()-st2.size();i++)
{
    s=0;
    for (int j=0;j<st2.size();j++)
    if (st1[i+j]!=st2[j])s++;
    ans=min(ans,s);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}