/*
Getting in the heat
Coming with a beat
And I love what I feel
Hard and heavy

And I'm moving on and on
'cause my life is on the run
Now I feel the need to try
Oh yeah, - I'm aiming high

Longing all my life
Waiting for a friend
Who is fighting like I do
Likes to do it hard and heavy

It's a man's man's world
Filled with love and pain
And he never gets enough
And that keeps him very tough

Aiming high aiming high
And I'm waiting for relieve
To the best of my believe
Aiming high aiming high
What I fight to get it right
For a minute of delight

Falling in the deep
Dreaming in my sleep
How it burns to be cruel
Hard and heavy

I feel lower more and more
'cause I won't do it any more
And I feel the need to cry
Oh yeah, - I'm aiming high

Aiming high aiming high
And I'm waiting for relieve
To the best of my believe
Aiming high aiming high
What I fight to get it right
For a minute of delight

Aiming high indeed
Seeking for my need
That is my sense of touch
Hard and heavy way too much

Aiming high aiming high
And I'm waiting for relieve
To the best of my believe
Aiming high aiming high
What I fight to get it right
For a minute of delight

Aiming high
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

struct pt{
       long long x,y;
       };

vector<pt> v;
long long a,b,ans;
long long n;

long gett(pt a,pt b)
{
 return max(abs(a.x-b.x),abs(a.y-b.y));
}

bool cmp(pt a,pt b)
{
 return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

bool cw(pt a,pt b,pt c)
{
 return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<0;
}
bool ccw(pt a,pt b,pt c)
{
 return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)>0;
}

void convex_hull(vector<pt> &a)
{
 if (a.size()==1)return;
 sort(a.begin(),a.end(),&cmp);
 pt p1=a[0];
 pt p2=a.back();
 vector<pt> up,down;
 up.push_back(p1);
 down.push_back(p1);
 for (int i=1;i<a.size();i++)
 {
  if (i==a.size()-1||cw(p1,a[i],p2))
  {
   while (up.size()>=2&&!cw(up[up.size()-2],up[up.size()-1],a[i]))
    up.pop_back();
   up.push_back(a[i]);
  }
  if (i==a.size()-1||ccw(p1,a[i],p2))
  {
   while (down.size()>=2&&!ccw(down[down.size()-2],down[down.size()-1],a[i]))
    down.pop_back();
   down.push_back(a[i]);
  }
 }
 a.clear();
 for (int i=0;i<up.size();i++)
  a.push_back(up[i]);
 if (down.size()>1)
  for (int i=down.size()-2;i>0;--i)
   a.push_back(down[i]);
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>a>>b;
 pt temp;
 temp.x=a;
 temp.y=b;
 v.push_back(temp);
}
convex_hull(v);
for (int i=0;i+1<v.size();i++)
 ans+=gett(v[i],v[i+1]);
ans+=gett(v[0],v.back());

cout<<ans+4<<endl;

cin.get();cin.get();
return 0;}