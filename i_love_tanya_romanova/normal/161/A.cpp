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
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long n,m,a,b,x,y,q;
pair <long long ,long  long> p;
vector <pair <long long , long long> > v1,v2,ans;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>n>>m>>x>>y;
for (long long i=1;i<=n;i++)
{cin>>a;p=make_pair(a,i);
 v1.push_back(p);}
 
for (long long j=1;j<=m;j++)
{cin>>a;p=make_pair(a,j);
 v2.push_back(p);}
 
sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());

q=0;
for (int i=0;i<n;i++)
{
    while (q<m&&v1[i].first>v2[q].first+x)++q;
    
    if (q==m)
    {break;}
    if (v1[i].first<=v2[q].first+x   &&v1[i].first>=v2[q].first-y)
    {p=make_pair(v1[i].second,v2[q].second);ans.push_back(p);++q;}
}
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
cout<<ans[i].first<<" "<<ans[i].second<<endl;

cin.get();cin.get();
return 0;}