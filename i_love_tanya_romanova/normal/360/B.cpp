/*
Throw up
I need my medicine, God
Where have I been

The doorbell
I can tell
That sound from miles away

She calls me
Reminding me
It's time to shine

I'm deeper down
Deeper down the scar
I'm closer now
Closer to the stars

The night is gone, the day has come
No more rats, they've fled the sun
Rest your breath, reload your gun
Tonight we'll go again
Dawn has reached the battefield
The war is lost lay down your shield
Rest your breath and fill your glas
Tonight we'll go again

Get up
We'll rule the mountaintops, Suck
Too late to stop
No memory of yesterday
Prepare the night's return
I'm here for you
We'll get you
I'll make you burn
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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,k,l,r,bst[20000],m,t;
long long ar[10000];

int main(){
//freopen("supper.in","r",stdin);
//freopen("supper.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
cin>>ar[i];

l=0;
r=2000000000;
while (l<r)
{
      m=(0ll+l+r)/2;
//      cout<<m<<endl;
      for (int i=1;i<=n;i++)
      bst[i]=1;
      for (int i=1;i<=n;i++)
       for (int j=i+1;j<=n;j++)
       {
           if (abs(ar[j]-ar[i])<=m*(j-i))
           bst[j]=max(bst[j],bst[i]+1);
       }
      t=0;
      for (int i=1;i<=n;i++)
      t=max(t,bst[i]);
      if (t+k>=n)//ok
      r=m;
      else l=m+1;
}
cout<<l<<endl;

cin.get();cin.get();
return 0;}