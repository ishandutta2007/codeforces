/*
Wars coming start running
Eyes blinded by the nuclear blast
Hearts beating retreating
All around are bodies burned to ash
Children crying and people dying
No salvation from this holocaust
Bodies burning and now their learning
In war painful death's the bloody cost

Life ends in sin
God cries world dies

And then there were none
The world starts to burn
The world powers learn
The satans work is done

Wheels grinding the glare's blinding
Bullets flying all around your head
Tanks crushing and soldiers rushing
If you live you'll wish that you were dead
Stop praying there's no saving
No salvation from your fiery grave
Brains swelling bodies smelling
And Satan comes to see that no one's saved
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

long long n,ar[200000],m,l,r,veds,bad;

int main(){
//freopen("virtualfriends.in","r",stdin);
//freopen("virtualfriends.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];

l=0;r=100000000000ll;
while (l<r)
{
      m=l+r;
      m/=2;
      veds=0;
      bad=0;
      for (int i=1;i<=n;i++)
      {if (ar[i]>m)bad=1;
       veds+=m-ar[i];
      }
      if (bad)veds=m-1;
      if (veds>=m)r=m;
      else l=m+1;
//      cout<<m<<" "<<veds<<" "<<l<<endl;
}

cout<<l<<endl;
cin.get();cin.get();
return 0;}