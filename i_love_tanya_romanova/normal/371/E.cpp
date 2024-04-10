/*
Angel - put sad wings around me now
Protect me from this world of sin
So that we can rise again

Oh angel - we can find our way somehow
Escaping from the world we're in
To a place where we began

And I know we'll find
A better place and peace of mind
Just tell me that it's all you want - for you and me
Angel won't you set me free

Angel remember how we'd chase the sun
Then reaching for the stars at night
As our lives had just begun

When I close my eyes I hear your velvet wings and cry
I'm waiting here with open arms - oh can't you see
Angel shine your light on me

Oh angel we'll meet once more - I'll pray
When all my sins are washed away
Hold me inside your wings and stay
Oh! angel take me far away

Put sad wings around me now
Angel take me far away
Put sad wings around me now
So that we can rise again
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-4
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000
#define double long double

using namespace std;

long long n,t,k,tdist,ans,ap;
vector<pair<long long, long long> > v;
long long summ;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>t;
 v.push_back(make_pair(t,i));
}

sort(v.begin(),v.end());
cin>>k;

for (int i=0;i<k;i++)
{
 tdist+=1ll*i*v[i].first-summ;
 summ+=v[i].first;   
}

ans=tdist;
ap=0;

//cout<<tdist<<endl;

for (int i=k;i<v.size();i++)
{
 summ-=v[i-k].first; // del 1
 tdist-=(summ-v[i-k].first*(k-1)); // x - 1
 tdist+=1ll*(k-1)*v[i].first-summ; // add 2
 summ+=v[i].first;
 if (tdist<ans)
 {
  ans=tdist;ap=i-k+1;
 }
// cout<<tdist<<endl;
}  

for (int i=ap;i<ap+k;i++)
{
    if (i-ap)cout<<" ";
    cout<<v[i].second;
}
cout<<endl;

cin.get();cin.get();
return 0;}