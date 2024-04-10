/*
When you are old enough to read these words
Their meaning will unfold
These words are all that's left
And though we've never met, my only son
I hope you know
That I would have been there to watch you grow
But my call was heard and I did go
Now your mission lies ahead of you
As it did my so long ago
To help the helpless ones who all look up to you
And to defend them to the end

Defender

Ride like the wind
Fight proud, my son
You're the defender
God has sent

Father,father,father
I look up to you and heed thy call

This letter ends my search
I'll live your dream now passed on to me
And I now wait to shake the hand of fate
Like the dusk awaiting dawn
So wizards cast your spell
With no heart to do me well
So it is written, it shall be

Defender

Ride like the wind
Fight proud, my son
You're the defender
God has sent
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
//#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,w[2000],hh[2000],c[2000],a[2000],b[2000],h[2000],need,ans,bst;

int main(){
//freopen("gnu.in","r",stdin);
//freopen("gnu.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>a[i]>>b[i]>>h[i];
}
long m;cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>hh[i]>>w[i]>>c[i];
}

for (int i=1;i<=n;i++)
{
 bst=1000000000;
 for (int j=1;j<=m;j++)
 {
     need=a[i]+b[i];
     need*=2;
     need=need/w[j]+(need%w[j]>0);
     if (hh[j]>=h[i])
     {need=need/(hh[j]/h[i])+(need%(hh[j]/h[i])>0);//+(h[i]/hh[i]>0));
     need*=c[j];
     bst=min(bst,need);
 }   }
 ans+=bst;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}