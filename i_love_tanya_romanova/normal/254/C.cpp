/*
In a while now I will feel better
I'll face the weather before me
In a while now I'll race the irony
And buy back each word of my eulogy
All the uninvited tragedies
Step outside
Ask yourself now
Where would you be without
Days like this
When you finally collide
With the moment you can't forget
So do I remind you of
Someone you never met
A lonely silhouette
And do I remind you of
Somewhere you wanna be
So far out of reach
Oh, I wish you'd open up for me
'Cause I wanna know you
Amaryllis
Bloom
Stay a while now
Undress your colors
'Cause they're like no others
I've ever seen
I could get used to your company
Step inside
Ask yourself now
Where would you be without
Days like this
When you finally collide
With emotions you can't resist
So do I remind you of
Someone you never met
A lonely silhouette
And do I remind you of
Somewhere you wanna be
So far out of reach
Oh, I wish you'd open up for me
'Cause I wanna know you
Amaryllis
In a while now
I will feel better
I will be better
So do I remind you of
Someone you never met
A lonely silhouette
And do I remind you of
Somewhere you wanna be
So far out of reach
Oh, I wish you'd open up for me
'Cause I wanna know you
Amaryllis
Bloom
Amaryllis
Bloom
Amaryllis
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
#define bsize 256
 
using namespace std;

string st1,st2;
long n;
long s1[200],s2[200],d[200];
long ans;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>st1;
cin>>st2;
n=st1.size();
for (int i=0;i<n;i++)
{
 s1[st1[i]-'A']++;
 s2[st2[i]-'A']++;
}
for (int i=0;i<26;i++)
 d[i]=s1[i]-s2[i];

for (int i=0;i<n;i++)
{
 if (d[st1[i]-'A']<=0)continue;// cn't change
 long p1,p2;
 p2=st1[i]-'A';
 for (int j=0;j<26;j++)
  if (d[j]<0){p1=j;break;}
 
 if (p1>p2&&d[p2]<s1[p2]){--s1[p2];continue;}// btr stay
 
 d[p2]--;
 d[p1]++;
 st1[i]=char(p1+'A');
 ++ans;
 s1[p2]--;s1[p1]++;  
}

cout<<ans<<endl;
cout<<st1<<endl;

cin.get();cin.get();
return 0;}