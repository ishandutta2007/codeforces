/*
Here we are
In a world of corruption
Human nature is
Of violent Breed
Who cares if there's no tomorrow
When I die for my future's
Laid out for me
Can't you see?
Rise above the lies
Morals on a backwards globe
A sin to you
For me it's hope.

It's my life and provision
Black or white
Some pay to pray
You question why they
Act this way
It's their fucking decision

No more judgement day
Only tranquility
Peace signs, protest lines
Mean nothing to me

Honesty born in me
Heresy

I know what's right or wrong
And my belief is stronger
Than your advice
People, they go to war
Because religion gives them
Reason to fight
Sacrifice, die for pride
A group that caters
No one's fees
Or synthetic deities
Is where I belong
My stand is the human race
Without a label or a face
So they can lick my sack

No more judgement day
Only tranquility
Peace signs, protest lines
Mean nothing to me

Honesty born in me
Heresy
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
#define clone agsdahfaassdg

using namespace std;

long n,p,temp,ans;
vector<long> vec[100],ovr;
vector<long> av;

long gdeg(long x)
{long r=0;
while (x){r++;x/=2;}
return r-1;
}

long ar[200000];

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
}

ans=-1;

for (int i=30;i+1;--i)
{
    temp=(1ll<<31)-1;
    for (int ii=1;ii<=n;ii++)
    if (ar[ii]&(1<<i))temp&=ar[ii];
    
    if (temp%(1<<i)==0&&ans==-1){ans=max(ans,i+ans-ans);av.clear();
    for (int ii=1;ii<=n;ii++)
    if (ar[ii]&(1<<i))av.push_back(ar[ii]);}
    
}

if (ans>=0)
{
 cout<<av.size()<<endl;
 for (int i=0;i<av.size();i++)
 {
     if (i)cout<<" ";
     cout<<av[i];
 }
 cout<<endl;
}
else
{
    cout<<n<<endl;
    for (int i=0;i<ovr.size();i++)
    {if (i)cout<<" ";cout<<ovr[i];}
    cout<<endl;
}
cin.get();cin.get();
return 0;}