/*
Lashing out the action, returning the reaction
Weak are ripped and torn away
Hypnotizing power, crushing all that cower
Battery is here to stay

Smashing through the boundaries
Lunacy has found me
Cannot stop the Battery
Pounding out aggression
Turns into obsession
Cannot kill the Battery

Cannot kill the family
Battery is found in me

Battery

Crushing all deceivers, mashing non-believers
Never ending potency
Hungry violence seeker, feeding off the weaker
Breeding on insanity

Smashing through the boundaries
Lunacy has found me
Cannot stop the Battery
Pounding out aggression
Turns into obsession
Cannot kill the Battery

Cannot kill the family
Battery is found in me

Battery

Circle of Destruction, Hammer comes crushing
Powerhouse of energy
Whipping up a fury, Dominating flurry
We create the Battery

Smashing through the boundaries
Lunacy has found me
Cannot stop the Battery
Pounding out aggression
Turns into obsession
Cannot kill the Battery

Cannot kill the family
Battery is found in me

Battery
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

long long n;
vector<long long> v;
long long p,ta,pp,ss,tb,ans;
long long disc,c1,c2,y,squ;
long long ttc;

void check(long long disc,long long a,long long b, long long y)
{
     squ=sqrt(disc*1.0+1e-6);
     if (squ*squ!=disc)return;
     c1=-y-squ;
     if (c1%2==0&&c1/2-a>=b){ttc=c1/2-a;if (a!=b&&b!=ttc)ans+=6;
     else if (a!=b||b!=ttc)ans+=3; else ++ans;}//++ans;
     c2=-y+squ;
     if (c2%2==0&&c2/2-a>=b){ttc=c2/2-a;if (a!=b&&b!=ttc)ans+=6;
     else if (a!=b||b!=ttc)ans+=3; else ++ans;}//++ans;
  //   cout<<a<<" "<<b<<" "<<ttc<<" "<<c1<<" "<<c2<<endl;
}

int main(){
//freopen("sumdist.in","r",stdin);
//freopen("sumdist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
if (n%3){cout<<0<<endl;return 0;}

n/=3;
//n=1000000000ll;
//n*=100000;

for (long long i=1;i*i*i<=n;i++)
if (n%i==0)
{
 v.push_back(i);         
}

//cout<<v.size()<<endl;

for (int div=0;div<v.size();div++)
{
    ss=v[div];
  //if (div%100==0)  cout<<ss<<" "<<ans<<endl;
    for (long long p=1;p<=ss;++p)
    {
        ta=p;
        tb=ss-p;
        if (tb<ta)break;
       // cout<<ta<<" "<<tb<<endl;
        pp=n/(ta+tb);
        if (pp*(ta+tb)!=n)continue;
        if (ta*tb*4>pp)continue;
        
        y=tb-ta;
       disc=y*y+4*pp;
      // cout<<disc<<" "<<ta<<" "<<tb<<endl;
        if (disc<0)continue;
        check(disc,ta,tb,y);
    }
}

cout<<ans<<endl;

//for (int i=1;i<=100;i++)
//for (int j=i;j<=100;j++)
//for (int q=j;q<=100;q++)
//if ((i+j)*(j+q)*(i+q)==n)cout<<i<<"  "<<j<<"   "<<q<<endl;

cin.get();cin.get();
return 0;}