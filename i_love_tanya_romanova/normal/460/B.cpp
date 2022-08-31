/*
Once
I had a mountain of my own
With moss and walls and magic
And a mighty view
A forest of my own
Listening to me
Showing me its secret paths and trails
Green with depths and sleeping sunrises
Thorns that never cut
My feet and face
A pine of my own
Offering a seat in the sunset
Painting windy pictures
Arabesques
Of fortune and forever
Too large to fit
Even in a child's pocket
Now
Arabesques of forgetfulness
Are left to burn holes
In my white tapestry and fungible wallpaper
Once
I had a world of my own
It is still there
Only
I am gone
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
#define right adsgasgadsg

using namespace std;

long long a,b,c,temp;
vector<long long> av;
long long gett(long long x)
{
 long long s=0;
 while (x){s+=x%10;x/=10;}
 return s;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b>>c;
for (int s=1;s<=100;s++)
{
 temp=1;
 for (int i=1;i<=a;i++)
  temp*=s;
  temp*=b;
  temp+=c;
  if (gett(temp)==s&&temp<1000000000&&temp>0)
   av.push_back(temp);
}
sort(av.begin(),av.end());

cout<<av.size()<<endl;
for (int i=0;i<av.size();i++)
{
 if (i)cout<<" ";
 cout<<av[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}