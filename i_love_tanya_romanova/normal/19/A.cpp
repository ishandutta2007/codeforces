/*
Her eyes opened after that terrible night
Would she ever be the same?
A revelation of her own demise
No one left but herself to blame

Her silence only fueled the flame
And now the angels have lost their wings
In daddy's playground, nothing is what it seems
This was the last time that he'd see her
That he'd touch her
That he'd make his little girl scream out loud

I'm gonna pound you into oblivion
I will make you fucking bleed
There is no escaping me
This is your destiny

I'm gonna pound you into oblivion
I will make you fucking bleed
There is no escaping me
This is your destiny

He came to her through the window again
The fan blowing to hide the noise
No hesitation from the devil inside
Everyone he touched was destroyed

His madness only fueled the flame
And now the angels have lost their wings
In daddy's playground, nothing is what it seems
This was the last time that he'd see her
That he'd touch her
That he'd make his little girl scream out loud

I'm gonna pound you into oblivion
I will make you fucking bleed
There is no escaping me
This is your destiny

Time to walk with me
Time to walk with me
Time to die

Let me take you somewhere secluded
Where only the trees can see
If I can't have you, no one will
Didn't you know, it was always me?

Your flame now burned out
You were daddy's little girl
Your flame now burned out
Oh God, what have I done?
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

using namespace std;

string name[2000];
map<string, long> mapp;
string st;
pair<string, string> tp1;
pair<long, long> tp2;
long n;
long a,b,score[2000];
long c,d,g1[2000],g2[2000];
long ps[2000];
vector<string> av;

pair<string, string> parse1(string st)
{
 pair<string, string> res;
 long flag=0;
 for (int i=0;i<st.size();i++)
 {
 if (st[i]=='-')flag=1;
 else if (flag==0)res.first+=st[i];
 else res.second+=st[i];
 }
 return res;
}

pair<long, long> parse2(string st)
{
 pair<long, long> res;
 long flag=0;
 for (int i=0;i<st.size();i++)
 {
  if (st[i]==':')flag=1;
  else if (flag==0)res.first=res.first*10+st[i]-48;
  else res.second=res.second*10+st[i]-48;
 }          
 return res;
}

bool cmp(long a,long b)
{
 if (score[a]>score[b])return true;
 if (score[a]<score[b])return false;
 if (g1[a]-g2[a]>g1[b]-g2[b])return true;
 if (g1[a]-g2[a]<g1[b]-g2[b])return false;
 if (g1[a]>g2[b])return true;
 return false;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>name[i];
 mapp[name[i]]=i;
}

for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
 {
  cin>>st;
  tp1=parse1(st);
  cin>>st;
  tp2=parse2(st);
  a=mapp[tp1.first];
  b=mapp[tp1.second];
  c=tp2.first;
  d=tp2.second;
  
  if (c>d)score[a]+=3;
  if (c<d)score[b]+=3;
  if (c==d)score[a]++,score[b]++;
  g1[a]+=c;
  g1[b]+=d;
  g2[a]+=d;
  g2[b]+=c;
 }
/*
for (int i=1;i<=n;i++)
cout<<score[i]<<" "<<g1[i]<<" "<<g2[i]<<endl;
*/
for (int i=1;i<=n;i++) 
{
    ps[i]=i;
}
sort(ps+1,ps+n+1,cmp);

for (int i=1;i<=n/2;i++)
 av.push_back(name[ps[i]]);

sort(av.begin(),av.end());
for (int i=0;i<av.size();i++)
{
 cout<<av[i]<<endl;
}

cin.get();cin.get();
return 0;}