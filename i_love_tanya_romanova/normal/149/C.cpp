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
long n,q,s1,s2;
vector <long> v1,v2;
pair <long, long> p;
vector <pair <long, long> > v;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=0;i<n;i++)
{cin>>q;p=make_pair(q,i+1);v.push_back(p);}
sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{if (i%2){v1.push_back(v[i].second);}
else v2.push_back(v[i].second);}

cout<<v1.size()<<endl;
for (int i=0;i<v1.size();i++)
{if (i)cout<<" ";cout<<v1[i];
}
cout<<endl;
cout<<v2.size()<<endl;
for (int i=0;i<v2.size();i++)
{if (i)cout<<" ";cout<<v2[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}