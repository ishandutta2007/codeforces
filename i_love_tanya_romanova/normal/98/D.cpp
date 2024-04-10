/*
Seize the day or die
Regretting the time you lost
It's empty and cold without you here
Too many people to ache over

I see my vision burn
I feel my memories fade with time
But I'm too young to worry
These streets we travel on
Will undergo our same lost past

I found you here
Now please just stay for a while
I can move on with you around
I hand you my mortal life
But will it be forever?

I'd do anything for a smile
Holding you 'til our time is done
We both know the day will come
But I don't want to leave you

I see my vision burn
I feel my memories fade with time
But I'm too young to worry
A melody, a memory
Or just one picture

Seize the day or die
Regretting the time you lost
It's empty and cold without you here
Too many people to ache over

Newborn life replacing all of us
Changing this fable we live in
No longer needed here
So where do we go?

Will you take a journey tonight
Follow me past the walls of death?
But girl, what if
There is no eternal life?

I see my vision burn
I feel my memories fade with time
But I'm too young to worry
A melody, a memory
Or just one picture

Seize the day or die
Regretting the time you lost
It's empty and cold without you here
Too many people to ache over

Trials in life, questions of us existing here
Don't wanna die alone
Without you here, please tell me
What we have is real

So, what if I never hold you, yeah
Or kiss your lips again?
So I never want to leave you
And the memories of us to see
I beg don't leave me

Seize the day or die
Regretting the time you lost
It's empty and cold without you here
Too many people to ache over

Trials in life, questions of us existing here
Don't wanna die alone
Without you here, please tell me
What we have is real

Silence, you lost me
No chance for one more day
Silence, you lost me
No chance for one more day

Silence, you lost me
No chance for one more day
Silence, you lost me
No chance for one more day

Silence, you lost me
No chance for one more day
Silence, you lost me
No chance for one more day
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

long n,d[200],calc;
vector<long> v;
vector<pair<long, long> > ans;

void add_move(long a,long b)
{
 ans.push_back(make_pair(a+1,b+1));
}

void solve_clear(vector<long> v,long a,long b);

void solve_dirt(vector<long> v,long start,long finish)
{
 if (v.size()==1)
 {
  for (int i=0;i<v[0];i++)
   add_move(start,finish);
   return;
 }
 long temp=v.back();
 v.pop_back();
 solve_dirt(v,start,3^start^finish);
 for (int i=0;i<temp;i++)
  add_move(start,finish);
 solve_dirt(v,3^start^finish,finish);
}

void solve_clear(vector<long> v,long start,long finish)
{
 if (v.size()==1){
                  for (int i=0;i<v[0]-1;i++)add_move(start,3^start^finish);
                  add_move(start,finish);
                  for (int i=0;i<v[0]-1;i++)add_move(3^start^finish,finish);
                  return;
                  }
 if(v[v.size()-1]==1)
 {
  solve_dirt(v,start,finish);
  return;
 }
 long temp=v.back();
 v.pop_back();
 solve_dirt(v,start,finish);
 //cout<<v.size()<<"^^"<<temp<<endl;
 for (int i=0;i<temp;i++)add_move(start,3^start^finish);
 solve_dirt(v,finish,start);
 for (int i=0;i<temp;i++)add_move(3^start^finish,finish);
 solve_clear(v,start,finish);
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for(int i=1;i<=n;i++)
{
 cin>>d[i];
 if (i>1&&d[i]!=d[i-1])
 {
  v.push_back(calc);
  calc=1;
 }
 else++calc;
}

//reverse(v.begin(),v.end());

v.push_back(calc);
reverse(v.begin(),v.end());

solve_clear(v,0,2);

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    cout<<ans[i].first<<" "<<ans[i].second<<"\n";
}

cin.get();cin.get();
return 0;}