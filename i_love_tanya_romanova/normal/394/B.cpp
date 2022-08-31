/*
Do you think Im faking
when Im lying next to you?
Do you think that I am blind
nothing left for me to lose?
Must be something on your mind
something lost and left behind 
Do you know Im faking now?

Do you know Im faking 
when Im lying next to you?
Do you know that I am blind to everything you ever do?
Must be something on your mind
something lost for me to find
Do you know Im faking?

Then she told me she had a gun
it sounded like shed used it once before on him 
Then she told me she had a gun
it sounded like shed used it once before, oh man

I guess you know Im faking
when I tell you I love you
I guess you know that I am blind 
to everything you say and do 
Must be something on my mind
theres nothing left for me to hide
Do you know Im faking?

Then she told me she had a gun
it sounded like shed used it once before on him 
Then she told me she had a gun
it sounded like shed used it once before, oh man

We have to succumb to the feelings we can never face
I need you. I breathe you.
I cant go through this all again. 
We have to succumb to 
the feelings we can never face I need you. 
I breathe you. I cant go through this

Then she told me she had a gun
it sounded like shed used it once before

Then she told me she had a gun
it sounded like shed used it once before on him
Then she told me she had a gun
it sounded like shed used it once before, oh man 
Then she told me she had a gun
she says she wants to use it on me now
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define bsize 256

using namespace std;

long p,x,ans;
long ar[1200000],n,rem;

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>p>>x;

ans=-1;

for (int dig=1;dig<=9;dig++)
{
 ar[p]=dig;
 rem=0;
 for (int i=p-1;i;--i)
 {
  ar[i]=ar[i+1]*x+rem;
  rem=ar[i]/10;
  ar[i]%=10;
 }
 if (ar[1]*x+rem!=dig||ar[1]==0)continue;
 ans=dig;
 break;
}

if (ans==-1)
cout<<"Impossible"<<endl;
else 
{
for (int i=1;i<=p;i++)
cout<<ar[i];cout<<endl;
}

cin.get();cin.get();
return 0;}