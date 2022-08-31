/*
Reverend reverend is this some conspiracy?
Crucified for no sins
An image beneath me
Whats within our plans for life
It all seems so unreal
I'm a man cut in half in this world
Left in my misery...

The reverend he turned to me
Without a tear in his eyes
It's nothing new for him to see
I didn't ask him why
I will remember
The love our souls had
Sworn to make
Now I watch the falling rain
All my mind can see
Now is your (face)

Well I guess
You took my youth
I gave it all away
Like the birth of a
New-found joy
This love would end in rage
And when she died
I couldn't cry
The pride within my soul
You left me incomplete
All alone as the
Memories now unfold.

Believe the word
I will unlock my door
And pass the
Cemetery gates

Sometimes when I'm alone
I wonder aloud
If you're watching over me
Some place far abound
I must reverse my life
I can't live in the past
Then set my soul free
Belong to me at last

Through all those
Complex years
I thought I was alone
I didn't care to look around
And make this world my own
And when she died
I should've cried and spared myself some pain...
Left me incomplete
All alone as the memories still remain

The way we were
The chance to save my soul
And my concern is now in vain
Believe the word
I will unlock my door
And pass the cemetery gates
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,x,pw[200000],spw,mpw;
long long mp;
map<long long, long long> calc;

long long pwr(long long a,long long b)
{
 if (b==0)return 1%bs;
 if (b%2)return a*pwr(a,b-1)%bs;
 return pwr(a*a%bs,b/2);
}

int main(){
//freopen("elect.in","r",stdin);
//freopen("elect.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>x;
for (int i=1;i<=n;i++)
{cin>>pw[i];spw+=pw[i];}

for (int i=1;i<=n;i++)
{pw[i]=spw-pw[i];}

mpw=1e16;

for (int i=1;i<=n;i++)
mpw=min(mpw,pw[i]);

for (int i=1;i<=n;i++)
pw[i]-=mpw;

spw-=mpw;

//res=pwr(x,mpw);

mp=pw[1];

for (int i=1;i<=n;i++)
{//cout<<pw[i]<<" ";
calc[pw[i]]++;
mp=min(mp,pw[i]);}
//cout<<endl;


for (int i=0;i<=500000;i++)
{
 if (calc[i]>=x){calc[i+1]+=calc[i]/x;
 calc[i]-=calc[i]/x*x;if (calc[i]==0&&mp==i)++mp;}
}
//cout<<mp<<endl;

mpw+=min(mp,spw);

cout<<pwr(x,mpw)<<endl;

cin.get();cin.get();
return 0;}