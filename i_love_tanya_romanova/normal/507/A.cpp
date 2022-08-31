/*
Hey, hey, hey
Here I go now, here I go into new days
Hey, hey, hey
Here I go now, here I go into new days

I'm pain, I'm hope, I'm suffer
Yeah, hey, hey, hey, yeah, yeah
Here I go into new days

Hey, hey, hey
Ain't no mercy, ain't no mercy there for me
Hey, hey, hey
Ain't no mercy, ain't no mercy there for me

I'm pain, I'm hope, I'm suffer
Yeah, hey, hey, hey
Ain't no mercy, ain't no mercy there for me

Do you bury me when I'm gone?
Do you teach me while I'm here
Just as soon as I belong
Then it's time I disappear

Hey, hey, hey
And I went, and I went on down that road
Hey, hey, hey
And I went on, and I went on down that road

I'm pain, I'm hope, I'm suffer
Hey, hey, hey
Yeah and went on, and I went on down that road

Do you bury me when I'm gone?
Do you teach me while I'm here?
Just as soon as I belong
Then it's time I disappear

Do you bury me when I'm gone
Do you teach me while I'm here
Just as soon as I belong
Then it's time I disappear

Just like that
I'm gone, I'm gone, I'm gone, oh baby, I'm gone
I'm gone, I'm gone, baby
I'm gone, I'm gone

Do you bury me when I'm gone?
Do you teach me while I'm here?
Just as soon as I belong
Then it's time I disappear

Do you bury me when I'm gone?
Do you teach me while I'm here?
Just as soon as I belong
Then it's time I disappear, yeah
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
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,k,q;
vector<pair<long, long> > v;
vector<long> ans;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
 cin>>q;
 v.push_back(make_pair(q,i));
}
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
 if (v[i].first<=k)
 {
  ans.push_back(v[i].second);
  k-=v[i].first;
 }
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