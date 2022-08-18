/*
Destruction
Has ruined your world
Flags of death
Have been unleashed
You've survived
And now you will die

Crawl through Hall
That once was your home
Search for help
Through despair that has grown
You've not long
To live on this earth
You will die
Radiation shall kill

Shelter deep
Run and hide
There's no help
You will die
Shelter deep
Run and hide
There's no help
You will die

Fading fast
Your flesh shall rot
Life of pain
Is all you've got
There's no one left
To bury the dead
People hide
Behind walls of lead

Shelter deep
Run and hide
There's no help
You will die
Shelter deep
Run and hide
There's no help
You will die

Die, slow, death
Die, slow, death
Die, slow, death
Die, slow, death
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
double a[200000],b[200000],ans,ev;
vector<pair< pair<double,double> ,long> > v;

bool cmp(pair<pair<double, double> ,long> a,pair<pair<double, double> ,long> b)
{
 return a.first.first*a.first.second*(1.0-b.first.second)<
 b.first.first*b.first.second*(1.0-a.first.second);
}

int main(){
//freopen("scanner.in","r",stdin);
//freopen("scanner.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>a[i]>>b[i];b[i]*=0.01;
 ans+=a[i];
v.push_back(make_pair(make_pair(a[i],b[i]),i));}

sort(v.begin(),v.end(),cmp);
reverse(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
 ans+=ev*(1.0-b[v[i].second]);
 ev+=a[v[i].second]*b[v[i].second];
}
cout.precision(10);
cout<<fixed<<ans<<endl;
cin.get();cin.get();
return 0;}