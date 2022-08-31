/*
Trapped in purgatory
A lifeless object, alive
Awaiting reprisal
Death will be their acquisition

The sky is turning red
Return to power draws near
Fall into me, the sky's crimson tears
Abolish the rules made of stone

Pierced from below, souls of my treacherous past
Betrayed by many, now ornaments dripping above

Awaiting the hour of reprisal
Your time slips away

Raining blood
From a lacerated sky
Bleeding its horror
Creating my structure
Now I shall reign in blood!
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long n,d,a,b,t,q,s;
vector<pair<long long, long long> > v;
vector<long long> ans;

int main(){
//freopen("distance5.in","r",stdin);
//freopen("distance5.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>d;
cin>>a>>b;

for (int i=1;i<=n;i++)
{
    cin>>t>>q;
    s=t*a+b*q;
    v.push_back(make_pair(s,i));
}

sort(v.begin(),v.end());

long q=0;

while (d>0&&q<v.size())
{
      if (q<v.size()&&d>=v[q].first)
      {d-=v[q].first;ans.push_back(v[q].second);}
      ++q;
}

cout<<ans.size()<<endl;

for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}