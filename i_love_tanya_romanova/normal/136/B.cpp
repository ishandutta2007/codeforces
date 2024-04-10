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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
using namespace std;
long long a,b,q,answ;
vector <long long> ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>a>>b;
for (int i=1;i<=20;i++)
{q=b%3-a%3;q+=102;q%=3;
 ans.push_back(q);
 b/=3;a/=3;}
 
for (int i=ans.size();i;--i)
{answ=answ*3+ans[i-1];//cout<<ans[i-1];
}
//cout<<endl;
cout<<answ<<endl;

cin.get();cin.get();
return 0;}