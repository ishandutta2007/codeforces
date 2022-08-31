/*
The blinding white so far behind I am
And running over idle ground
This evening I kept my word, did you?
I'm turning around wait for your sound
So far according to who departer
The journey of our lives
I'm so slow compared to you departer
It's the month of July
Brother in your eyes I was the stronger
So how am I to cover you now
Without shadowing your path
This time I watch from the sidelines
Your ghost in the limelight
Face your fears and pierce the night
I'm so close if only you knew defender
The story of our lives
I'm so rash compared to you
Surrender it's the path of our lives
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
#include <ctime>
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long n,s,x[2000],y[2000],c[2000],ts;
long ans;
vector<pair<long, long> > v;

int main(){
//freopen("trading.in","r",stdin);
//freopen("trading.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>s;
for (int i=1;i<=n;i++)
{
 cin>>x[i]>>y[i]>>c[i];
 ts+=c[i];
 v.push_back(make_pair(x[i]*x[i]+y[i]*y[i],c[i]));
}
if (ts+s<1000000){cout<<-1<<endl;return 0;}
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
 s+=v[i].second;
 ans=v[i].first;
 if (s>=1000000)break;
}
cout.precision(12);
cout<<fixed<<sqrt(ans*1.0)<<endl;

cin.get();cin.get();
return 0;}