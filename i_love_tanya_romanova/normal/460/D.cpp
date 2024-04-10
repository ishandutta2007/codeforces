/*
For as long as I can remember I have wanted to
Silence every beating heart; every sound of breathing
Now there is something inside of me that aches as I hear you
Breathing here when you sleep between these morning sheets

I am the tears in your mouth
I am the weight on your shoulder
I am the scream that wants out
And my heart just couldn't grow colder
Now this rusty heart is my gift
This fallen love is my gift

Morning arrives on an Earth I've never seen before
Revealing a life that I never really understood
Strange, the way beauty can hurt the unopened eye
Much more than all of the filth and pain
That we're soaked in ever could

I am the tears in your mouth
I am the weight on your shoulder
I am the scream that wants out
And my heart just couldn't grow colder

Hear this voice, see this man standing before you
I'm just a child trapped inside the body of a man

"An acquaintance so oddly old - bred not to love
Suffers the beaten grounds of Idioglossia
We talk but we do not speak
Together only in our incapability to leave this fallen playground
We rule this Empire merely with these few crippled toys
Rust in our faces
This is what we can share - this is all we can lose
Still
Furiously we will linger to it with our lives
Cling to its rust and pains
Barefoot and torn
Bred not but born to love"

Hear this voice, see this man standing before you
I'm just a child trapped inside this fallen man
See this child
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

long long l,r,k,bst,bmask,span,val;
vector<long long> bvec;
long long a,b,c,hs;

long gett(long x)
{
 long s=0;
 for (int i=0;i<=20;i++)
  if (x&(1<<i))++s;
 return s;
}

vector<long long> solve(long long l,long long mask)
{
 vector<long long> res;
 for (int i=0;i<=20;i++)
 if (mask&(1<<i))res.push_back(l+i);
 return res;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>l>>r>>k;
if (r<=l+10)
{
 bst=l;
 bmask=1;
 span=r-l+1;
 bvec.push_back(l);
 for (int mask=1;mask<(1<<span);mask++)
 {
  if (gett(mask)>k)continue;
  val=0;
  for (int i=0;i<span;i++)
   if (mask&(1<<i))val^=l+i;
  if (val<bst){bst=val;bvec=solve(l,mask);}
 }
}

else
{
 if (k==1)
 {
  bst=l;
  bvec.push_back(l);
 }
 if (k==2)
 {
  bst=l/2;
  bst=bst*2+2;
  bvec.push_back(bst);
  bvec.push_back(bst+1);
  bst^=bst+1;
 }
 if (k>3)
 {
  bst=l/4+1;
  for (long long i=bst*4;i<bst*4+4;i++)
   bvec.push_back(i);
  bst=0;
 }
 if (k==3)
 {
  hs=0;
  for (int i=0;i<=40;i++)
  {
   a=(1ll<<i)*3;
   b=a-1;
   c=(1ll<<i)*2-1;
   if (a>=l&&a<=r&&b>=l&&b<=r&&c>=l&&c<=r)
   {
    hs=1;
    bvec.push_back(a);
    bvec.push_back(b);
    bvec.push_back(c);
    bst=0;
    break;
   }
  }
 if (hs==0){bvec.push_back(l+l%2);bvec.push_back(l+l%2+1);bst=1;}
 }
}

cout<<bst<<endl;
cout<<bvec.size()<<endl;
for (int i=0;i<bvec.size();i++)
{
 if (i)cout<<" ";
 cout<<bvec[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}