/*
Oh life, it's bigger
It's bigger than you
And you are not me
The lengths that I will go to
The distance in your eyes
Oh no, I've said too much
I've said enough

That's me in the corner
That's me in the spotlight
Losing my religion
Trying to keep up with you
And I don't know if I can do it
Oh no, I've said too much
I haven't said enough

I thought that I heard you laughing
I thought that I heard you sing
I think I thought I saw you try

Every whisper 
Of every waking hour
I'm choosing my confessions
Trying to keep an eye on you
Like a hurt, lost and blinded fool, fool
Oh no, I've said too much
I've said enough

Consider this
Consider this, the hint of the century
Consider this, the slip
That brought me to my knees, failed
What if all these fantasies come
Flailing around
Now I've said too much

I thought that I heard you laughing
I thought that I heard you sing
I think I thought I saw you try

But that was just a dream
That was just a dream

That's me in the corner
That's me in the spotlight
Losing my religion
Trying to keep up with you
And I don't know if I can do it
Oh no, I've said too much
I haven't said enough

I thought that I heard you laughing
I thought that I heard you sing
I think I thought I saw you try

But that was just a dream
Try, cry, why try
That was just a dream
Just a dream
Just a dream, dream
*/

#pragma comment(linker, "/STACK:16777216")
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

long n,s,bst,q;
vector<long> ans;
long tests;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>s;
for (int i=1;i<=n;i++)
{
 bst=1e9;
 cin>>tests;
 for (;tests;--tests)
 {
  cin>>q;
  bst=min(bst,q);
 }
 if (bst<s)ans.push_back(i);
}
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
 if (i)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}