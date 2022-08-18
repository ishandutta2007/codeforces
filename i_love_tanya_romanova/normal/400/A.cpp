/*
Hey hey yea yea let it out

Dont have to bite your own tongue
Shouldnt keep your mind closed
Gotta let them all know
What youre capable of

Dont second guess your own heart
Go with what feels right
Gotta let them all know
What you locked up inside

Shouldnt hold on to the things
That wont let you move on
Shouldnt hold yourself back
Let yourself go

Let it out say what you have to say
Cause its not worth the wait let it out
And dont back down dont turn away
No its not worth the wait and its not worth the pain (so let it out)

Dont wanna look back and think
You could have made things alright
With just one simple line
You chose to keep in your mind

You wanna look back and say
I did the best that I could
Maybe my best wasnt enough
But its the thought that counts

Shouldnt hold on to the things
That wont let you move on
Shouldnt hold yourself back
Let yourself go and

Let it out say what you have to say
Cause its not worth the wait let it out
And dont back down dont turn away
No its not worth the wait and its not worth the pain (let it out)

You wanna look back and say
You wanna look back and feel
I did the best that I could
I did the best that I could

You wanna look back and say
You wanna look back and feel
I am proud of all that I have done

Shouldnt hold on to the things
That wont let you move on
Shouldnt hold yourself back
Let yourself go

Let it out say what you have to say
Cause its not worth the wait let it out
And dont back down dont turn away
No its not worth the wait and its not worth the pain (let it out)
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
#define eps 1e-17
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long tests;
char ar[200][200];
long anss,er,a,b;
vector<pair<long,long> > av;

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
   
cin>>tests;
for (;tests;--tests)
{
 cin>>st;
 av.clear();
 for (int i=1;i<=12;i++)
 if (12%i==0)
 {
  a=i;
  b=12/i;
  for (int j=0;j<st.size();j++)
  ar[j/b][j%b]=st[j];
  anss=0;
  for (int j=0;j<b;j++)
  {
   er=0;
   for (int q=0;q<a;q++)
   if (ar[q][j]!='X')er=1;
   if (er==0)
   anss=1;
  }
  if (anss)av.push_back(make_pair(a,b));
 }
 cout<<av.size();
 for (int i=0;i<av.size();i++)
 cout<<" "<<av[i].first<<"x"<<av[i].second;
 cout<<endl;
}

cin.get();cin.get();
return 0;}