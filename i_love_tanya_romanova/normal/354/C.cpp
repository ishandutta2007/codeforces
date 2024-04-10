/*
Struggle with emotion
Feel the pain burn deep
Within our nerves
The mourning of lost life
Commands our actions night and day

The foul realism is unleashed
Upon the earth we'll bleed

Banish all fond memories
As the lord beckons us to judgement
Degeneration is close at hand
The mortality coil is weaker
The pain is close to heart
Now leave the ruined world to your god

The kindness of deaths grasp
Relieves us from the pain
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

using namespace std;

long n,k,s[4000000],ar[4000000];
long ans;
long fl;

int main(){
//freopen("deny.in","r",stdin);
//freopen("deny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;

for (int i=1;i<=n;i++)
cin>>ar[i];

for (int i=1;i<=n;i++)
{
 s[ar[i]]++;   
}

for (int i=1;i<=3000000;i++)
s[i]+=s[i-1];

for (long i=1;i<=1000000;i++)
{
    if (s[i-1]>0)continue;
    if (i<=k){ans=i;continue;}
    fl=0;
    for (int p=i;p<=1000000;p+=i)
    {
        if (s[p+k]<s[p+i-1]){fl=1;break;}
    }
    if (fl==0)ans=max(ans,i);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}