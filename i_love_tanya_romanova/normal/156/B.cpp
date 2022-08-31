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
long n,m,s1,fl,s2,sz1[200000],sz2[200000],q[200000],w[200000];
set <long> ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>q[i];
  //  q[i]=0-q[i];
    if (q[i]<0){s1++;}
    else s2++;
    w[i]=abs(q[i]);
    if (q[i]<0){sz1[w[i]]++;}
    else sz2[w[i]]++;
}

for (int i=1;i<=n;i++)
{
    if (sz1[i]+(s2-sz2[i])==n-m)    ans.insert(i);

//    cout<<sz1[i]+s2-sz2[i]<<endl;
}

if (ans.size()>1)fl=1;
//cout<<ans.size()<<endl;

for (int i=1;i<=n;i++)
{
    if (q[i]>0)
    {if (ans.find(w[i])==ans.end())cout<<"Lie";
    else if (fl)cout<<"Not defined"; else cout<<"Truth";}
    else
    {
        if (ans.find(w[i])==ans.end())cout<<"Truth";
        else if (fl)cout<<"Not defined"; else cout<<"Lie";}
    cout<<endl;
}

cin.get();cin.get();
return 0;}