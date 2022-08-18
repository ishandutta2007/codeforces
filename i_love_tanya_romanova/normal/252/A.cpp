/*
Hey, hey, hey
Here I go now, here I go into new days
Hey, hey, hey
Here I go now, here I go into new days

I'm pain, I'm hope, I'm suffer
Yeah, hey, hey, hey, yeah, yeah
Here I go into new days

Hey, hey, hey
Ain't no mercy, ain't no mercy there for me
Hey, hey, hey
Ain't no mercy, ain't no mercy there for me

I'm pain, I'm hope, I'm suffer
Yeah, hey, hey, hey
Ain't no mercy, ain't no mercy there for me

Do you bury me when I'm gone?
Do you teach me while I'm here
Just as soon as I belong
Then it's time I disappear

Hey, hey, hey
And I went, and I went on down that road
Hey, hey, hey
And I went on, and I went on down that road

I'm pain, I'm hope, I'm suffer
Hey, hey, hey
Yeah and went on, and I went on down that road

Do you bury me when I'm gone?
Do you teach me while I'm here?
Just as soon as I belong
Then it's time I disappear

Do you bury me when I'm gone
Do you teach me while I'm here
Just as soon as I belong
Then it's time I disappear

Just like that
I'm gone, I'm gone, I'm gone, oh baby, I'm gone
I'm gone, I'm gone, baby
I'm gone, I'm gone

Do you bury me when I'm gone?
Do you teach me while I'm here?
Just as soon as I belong
Then it's time I disappear

Do you bury me when I'm gone?
Do you teach me while I'm here?
Just as soon as I belong
Then it's time I disappear, yeah
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,l,r[1000],ans,q;

int main(){
//freopen("galaxy.in","r",stdin);
//freopen("galaxy.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>q;
r[i]=r[i-1]^q;}

for (int l=0;l<=n;l++)
for (int rr=l;rr<=n;rr++)
ans=max(ans,r[rr]^r[l]);
cout<<ans<<endl;

cin.get();cin.get();
return 0;}