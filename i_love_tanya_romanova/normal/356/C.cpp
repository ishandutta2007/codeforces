/*
There in the subway station, they shot him dead
He had broken the secrecy - Omerta
That's what they all will get,
They've got a job to do
The business is too important to take a risk and so
Please don't get me wrong, if you'd ever say a word
You'll have missed my friend, this is what you'll get

Execution guaranteed

We are an old family, controlling the trade
Gun running for the white house. The CIA works
hand in hand with us. We must feed the flame of
hate and war in the third world, cause if they
kill themselves We deliver all they need for the
fall (it's big money) The all order and this is
what they get

Execution guaranteed

We choose, you loose
You - jeah, I've got a mission for you
Look - here, a list of men to execute
Shoot - you must shoot them, no one will find out
Truth - truth is a daughter of time

Execution guaranteed
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

long n,ar[2000000],s[2000000],oh[2000000],need[2000000];
long ans,fst,sp,snd;

int main(){
//freopen("deny.in","r",stdin);
//freopen("deny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
sort(ar+1,ar+n+1);

for (int i=1;i<=n;i++)
s[i]=s[i-1]+ar[i];

for (int i=1;i<=n;i++)
{
 oh[i]=oh[i-1];
 if (ar[i]==4)++oh[i]; 
 need[i]=need[i-1];
 if (ar[i]<3)need[i]+=3-ar[i];  
}

ans=1000000000;

for (int cp=0;cp<=n;cp++)
{
    fst=s[cp];
    sp=4*(n-cp)-s[n]+s[cp];
    if (fst>sp)continue;
    snd=need[n]-need[cp];
    if (fst>=snd)ans=min(ans,fst);
    if (fst<snd)
    {
     if (oh[n]-oh[cp]+fst>=snd)ans=min(ans,snd);
    }
//    cout<<ans<<""<<fst<<" "<<snd<<endl;
    
}

if (ans>100000000)ans=-1;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}