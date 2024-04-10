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
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
long long i,qw,ans,q,l,r;
vector <long long> luck;
long long solve(long long a)
{
     long long ans=0;
 for (int i=1;i<luck.size();i++)
 {if (a>luck[i-1]){qw=min(a,luck[i])-luck[i-1];
  ans+=luck[i]*qw;}}
 return ans;
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
luck.push_back(4);
luck.push_back(7);

i=0;

while (true)
{if (i>=luck.size())break;
 q=luck[i];
 if (q>1000000000)break;
 luck.push_back(q*10+4);
 luck.push_back(q*10+7);
 ++i;
}
luck.push_back(0);
sort(luck.begin(),luck.end());
cin>>l>>r;
cout<<solve(r)-solve(l-1)<<endl;

 cin.get();cin.get();
return 0;
 }