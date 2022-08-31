/*
Sitting in the dark, I can't forget.
Even now, I realize the time I'll never get.
Another story of the Bitter Pills of Fate.
I can't go back again. I can't go back again...
But you asked me to love you and I did.
Traded my emotions for a contract to commit

And when I got away, I only got so far. The Other Me Is Dead.
I hear his voice inside my head...
We were never alive, and we won't be born again.
But I'll never survive with Dead Memories in my heart.
You told me to love you and I did. Tied my soul into a knot and got me to submit.

So when I got away, I only kept my scars. The Other Me Is Gone.
Now I don't know where I belong...
We were never alive, and we won't be born again.
But I'll never survive with Dead Memories in my heart.
Dead Visions in your Name.
Dead Fingers in my Veins.
Dead Memories in my Heart
*/

#include <math.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#pragma comment(linker, "/STACK:20000000")
#define M_PI        3.14159265358979323846
using namespace std;
long n,i;double m,p1,p2,maxx,minn,r,l; long ar[1000000];
int main(){
   // freopen("C:/input.txt","r",stdin);freopen("C:/output.txt","w",stdout);

cin>>n;cout.precision(6);
for (i=0;i<n;i++){cin>>ar[i];}
sort(ar,ar+n);//for (i=0;i<n;++i)cout<<ar[i]<<" ";cout<<endl;
l=0;r=2000000000;
while (r-l>0.01){
      m=(l+r)/2;p1=ar[0]+2*m;
      p2=ar[n-1]-2*m;
      minn=1100000000;maxx=-1100000000;
      for (i=0;i<n;i++){if (ar[i]>p1&&ar[i]<p2){if (ar[i]<minn)minn=ar[i];if (ar[i]>maxx)maxx=ar[i];};}
      if (maxx-minn>2100000000||maxx-minn<2*m){r=m;} else l=m;;//cout<<p1<<" "<<p2<<" "<<maxx<<" "<<minn<<" "<<m<<endl;
      }
      long lq=m*2+0.1;
      m=lq*0.5;
  cout<<fixed<<m<<endl<<ar[0]+m;
  minn=1100000000;
  for (i=0;i<n;i++)if (ar[i]>ar[0]+2*m+0.00000001&&ar[i]<minn)minn=ar[i];if (minn>1000000000)minn=ar[0];
  cout<<" "<<minn+m<<" "<<ar[n-1]-m<<endl;
  
cin.get();cin.get();cin.get();
return 0;}