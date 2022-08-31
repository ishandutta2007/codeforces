/*
I'm everything you've wanted
I am the one who's haunting you
I am the eyes inside of you
Stare back at you

There's nothing left to lose
There's nothing left to prove
Surrender your love
It's all you can do, yeah

What you got, what you want, what you need, gonna be your savior
Everything's gonna crash and break but I know, yeah, I know
What you got, what you want, what you need, gonna be your savior
Everything's gonna crash and break, your savior

It's time to redefine
Your deophobic mind
Don't hesitate, no escape
From secrets on the inside

There's nothing left to lose
There's nothing left to prove
Surrender your love
It's all you can do, yeah

What you got, what you want, what you need, gonna be your savior
Everything's gonna crash and break but I know, yeah, I know
What you got, what you want, what you need, gonna be your savior
Everything's gonna crash and break, your savior

I am the eyes inside
Staring back at you
I am the eyes inside
Staring back at you
You need, you need me, yeah

What you got, what you need
Everything's gonna crash and break
What you got, what you need
Everything's gonna crash and break

What you got, what you want, what you need, gonna be your savior
Everything's gonna crash and break but I know, yeah, I know
What you got, what you want, what you need, gonna be your savior
Everything's gonna crash and break, your savior

I'm watching you
'Cause you need me
Yeah, yeah, 'cause you need me
I'm watching you
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

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
#define bsize 256

using namespace std;

long long a,b,ans,tans,apos,p,q;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>a>>b;

if (b==0)
{
 cout<<a*a<<endl;
 for (int i=0;i<a;i++)cout<<"o";
 cout<<endl;
 return 0;
}

if (a==0)
{
 cout<<-b*b<<endl;
 for (int i=0;i<b;i++)cout<<"x";
 cout<<endl;
 return 0;
}
ans=-1e18;

swap(a,b);

for (int blocks=1;blocks<=b;blocks++)
{
 p=a/(blocks+1);
 q=a%(blocks+1);
 tans=-(p+1)*(p+1)*q-p*p*(blocks+1-q);
 tans+=(b-blocks+1)*(b-blocks+1)+blocks-1;
 if (tans>ans){ans=tans;apos=blocks;}
}

cout<<ans<<endl;//" "<<apos<<endl;

long blocks=apos;

 p=a/(blocks+1);
 q=a%(blocks+1);
 for (int i=0;i<blocks;i++)
 {for (int j=0;j<p;j++)cout<<"x";
 if (i<q)cout<<"x";
  if (i==0)for (int j=0;j<b-blocks+1;j++)
  cout<<"o";else cout<<"o";
 }
 for (int j=0;j<p;j++)
 cout<<"x";
 cout<<endl;
 
cin.get();cin.get();
return 0;}