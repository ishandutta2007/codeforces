/*
Deep inside the house of white
Elected tools decide our plight
If we live or if we die
Controlling minds, robbing blind
Moral crimes

Beware, false prophets, beware

He'll come in the form of a reverend clown
And tell his flock to gather round
He slays with his tongue
And not a sword
A celluloid jesus, a plastic lord
For your dashboard

Beware, false prophets, beware

He wares a flag of red, white, and blue
An ancient actor with a twisted view
His final picture is final part
His slice of history the war he starts
Blown apart!
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
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,ps,mn,mx;
string st;
long ans;
long dif;

long gd(long a,long b)
{
     return abs(a-b);
}

int main(){
//freopen("digits.in","r",stdin);
//freopen("digits.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>ps;
--ps;
cin>>st;

if (ps>n-ps-1)
{
 reverse(st.begin(),st.end());
 ps=n-ps-1;
}

mn=1e9;
mx=-1e9;
for (long i=0;i<n-i-1;i++)
{
    if (st[i]!=st[n-i-1])
    {
     mn=min(mn,i);
     mx=max(mx,i);
     dif=abs(st[i]-st[n-i-1]);
     if (dif>26-dif)dif=26-dif;
     ans+=dif;
    }
}
if (mn<=mx)
{
 ans+=min(gd(ps,mn)+gd(mn,mx),gd(ps,mx)+gd(mx,mn));
}
cout<<ans<<endl;


cin.get();cin.get();
return 0;}