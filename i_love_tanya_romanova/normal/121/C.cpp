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

long long p,q,n,ans,k,fakt[100000];

bool islucky(long long n)
{while (n)
{if (n%10!=4&&n%10!=7)return false;n/=10;}
return true;}

long long notUsed(vector <bool>&used, long long BlockNum)
{
long long  j,pos=0;
for (j=1;j<used.size();j++)
{if (!used[j])pos++;
 if (BlockNum==pos)
 break;
}
return j;
}

vector <long long > pbn(long n,long nm)
{vector <long long > res(n);
 vector <bool> used(n+1,false);
 for (long long  i=0;i<n;i++)
 {long long  BlockNum=(nm-1)/fakt[n-i-1]+1;
 long long  j=notUsed(used,BlockNum);
 res[i]=j;
 used[j]=true;
 nm=(nm-1)%fakt[n-i-1]+1;
 }
 return res;
 }
       
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>n>>k;

fakt[0]=1;
long long dd=20000;

for (int i=1;i<=min(n,dd);i++)
{
 fakt[i]=fakt[i-1]*i;
 if (fakt[i-1]>k)fakt[i]=fakt[i-1];
}

if (fakt[min(dd,n)]<k){cout<<-1<<endl; cin.get();cin.get();return 0;}

p=1;
while (fakt[p]<k)++p;

vector <long long > v=pbn(p,k);

long long tt=n-p;
//------------------------
vector <long long> luck;
long ii;
luck.push_back(4);
luck.push_back(7);

ii=0;

while (true)
{if (ii>=luck.size())break;
 q=luck[ii];
 if (q>1000000000)break;
 luck.push_back(q*10+4);
 luck.push_back(q*10+7);
 ++ii;
}
//luck.push_back(0);
sort(luck.begin(),luck.end());

for (int i=0;i<luck.size();i++)
{if (luck[i]<=tt)ans++;

else 
{if (luck[i]<=n){long p=luck[i]-tt;
 if (islucky(v[p-1]+tt))++ans;
 }}}

cout<<ans<<endl;
//------------------------
/*for (long long  i=0;i<v.size();i++)
cout<<v[i]<<" ";
cout<<endl;
*/

cin.get();cin.get();
return 0;}