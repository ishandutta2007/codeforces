
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
#define eps 1e-10
#define M_PI 3.141592653589793

//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back

using namespace std;
long n,cr;
double l,v1,v2,x[200000],prob[200000];
pair <double, long> p;
vector <pair <double, long> > ev;

int main(){
//freopen("C:/aver.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>n>>l>>v1>>v2;

for (int i=0;i<n;i++)
{cin>>x[i];
 if (x[i]<l-v1*l/(v1+v2))cr++;
 p=make_pair(2*l-x[i],1);
 ev.push_back(p);
 if (x[i]<l-v1*l/(v1+v2))
 {p=make_pair(l-v1*l/(v1+v2)-x[i],-1);
  ev.push_back(p);
  }
 else
 {
     p=make_pair(2*l+l-v1*l/(v1+v2)-x[i],-1);
     ev.push_back(p);
 } 
}

p=make_pair(2*l,0);
ev.push_back(p);

p=make_pair(0,0);
ev.push_back(p);
//cout<<cr<<endl;

sort(ev.begin(),ev.end());
//for (int i=0;i<ev.size();i++)
//cout<<ev[i].first<<" "<<ev[i].second<<endl;

for (int i=1;i<ev.size();i++)
{
    prob[cr]+=(ev[i].first-ev[i-1].first)/2/l;
    cr+=ev[i].second;
}
cout.precision(12);
for (int i=0;i<=n;i++)
cout<<fixed<<prob[i]<<endl;

cin.get();cin.get();
return 0;}