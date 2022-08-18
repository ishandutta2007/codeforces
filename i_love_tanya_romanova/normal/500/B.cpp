/*
"Son," she said, "Have I got a little story for you
What you thought was your Daddy was nothin' but a
While you were sittin' home alone at age thirteen
Your real Daddy was dyin', sorry you didn't see him but I'm glad we talked"

Oh I, oh, I'm still alive
Hey, I, oh, I'm still alive
Hey I, oh, I'm still alive
Hey, oh

Oh, she walks slowly, across a young man's room
She said, "I'm ready for you"
"I can't remember anything to this very day 'cept the look, the look
Oh, you know where, now I can't see, I just stare"

I'm still alive
Hey I, but, I'm still alive
Hey I, boy, I'm still alive
Hey I, I, I'm still alive, yeah
Ooh yeah, yeah, yeah, yeah, ooh

"Is something wrong?", she said
Well of course there is, "you're still alive," she said
Oh, and do I deserve to be?
Is that the question? And if so, if so, who answers, who answers?

I, oh, I'm still alive
Hey I, oh, I'm still alive
Hey I, oh I'm still alive
Hey I, oh I'm still alive
Hey, hey, hey, hey, hey, hey
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

string st;
long n,p[1<<10];
long ar[666][666];
long bst,bp;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++) 
 cin>>p[i];

for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=0;j<st.size();j++)
 {
  if (st[j]=='0')
   ar[i][j+1]=0;
  else ar[i][j+1]=1;
 }
}

for (int k=1;k<=n;k++)
 for (int i=1;i<=n;i++)
  for (int j=1;j<=n;j++)
   if (ar[i][k]==1&&ar[k][j]==1)
    ar[i][j]=1;

for (int i=1;i<=n;i++)
{
 bst=p[i];
 bp=i;
 for (int j=i+1;j<=n;j++)
  if (p[j]<bst&&ar[i][j]==1)
  {
   bst=p[j];
   bp=j;
  }
 swap(p[i],p[bp]);
}

for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<p[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}