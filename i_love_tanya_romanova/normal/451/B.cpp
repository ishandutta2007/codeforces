/*
Red sun rising,
somewhere through the dense fog.
The portrait of the jaded dawn,
who had seen it all before.

This day wept on my shoulders.
Still the same as yesterday.
This path seems endless, body is numb.
The soul has lost its flame.
Walking in familiar traces
to find my way back home.

So there I was.
Within the sobriety of the immortals.
A semblance of supernatural winds passing through.
The garden sighs, flowers die.

The gate was closed that day,
but I was bound to carry on.
She could not see me through the windows.
In dismay, strangest twist upon her lips.
Graven face, she said my name.

Once inside I heard whispers in the parlor.
The gilded faces grin, aware of my final

demise.

demise.

demise.

demise.

And I cried,
I knew she had lied.
Her obsession had died,
it had died.

When can I take you from this place?
When is the word but a sigh?
When is death our lone beholder?
When would we walk the final steps?
When can we scream instead of whisper?
When is the new beginning,
and the end of this sad madrigal.
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
#define N 120000

using namespace std;

long n,ar[200000],spn,f,l;
vector<long> erp;
long er;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
 cin>>ar[i];

for (int i=1;i<n;i++)
 if (ar[i]<ar[i-1])erp.push_back(i);

if (erp.size()==0)// srtd
{
 cout<<"yes"<<endl;
 cout<<1<<" "<<1<<endl;
} 
else
{
 f=erp[0]-1;
 l=erp[erp.size()-1];
 spn=l-f;
 if (spn!=erp.size())
 {
  cout<<"no"<<endl;
 }
 else
 {
  reverse(ar+f,ar+l+1);
  er=0;
  for (int i=1;i<n;i++)
   if (ar[i]<ar[i-1])er=1;
  if (er)cout<<"no"<<endl;
  else {
       cout<<"yes"<<endl;
       cout<<f+1<<" "<<l+1<<endl;
       }
 }
}

cin.get();cin.get();
return 0;}