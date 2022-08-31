/*
Round, round 
Circumventing circuses 
lamenting in process 
to visible police 
prescence sponsored fear 
batallions of riot police 
with rubber bullet kisses 
baton courtesy 
service with a smile 
Beyond the staples center you can see america 
with it's tired poor avenging disgrace 
peaceful loving youth against the brutality 
of plastic existence 
pushing little children 
with their fully automatics 
they like to push the weak around 
pushing little children 
with their fully automatics 
they like to push the weak around 
round, round 
A rush of words 
pleading to disperse 
upon your naked walls, alive 
A political call 
the fall guy accord 
we can't afford to be neutral on a moving train 
Beyond the staples center you can see america 
with it's tired poor avenging disgrace 
peaceful loving youth against the brutality 
of plastic existence 
pushing little children 
with their fully automatics 
they like to push the weak around 
pushing little children 
with their fully automatics 
they like to push the weak around 
A deer dance, invitation to peace 
war staring you in the face, dressed in black 
with a helmet, fierce 
trained and appropriate for the malcontents 
for the disproportioned malcontents. 
The little boy smiled, it'll all be well 
The little boy smiled, it'll all be well 
Pushing little children 
with their fully automatics 
they like to push the weak around 
Pushing little children 
with their fully automatics 
they like to push the weak around 
Push the weak around 
Push the weak around 
Push the weak around 
They like to push the weak around.
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

long long s,n,a,b;
long long ans,fact[2000000];

long long pw(long long a,long long b)
{
 if (b==0)return 1;
 if (b%2==0)return pw(a*a%bs,b/2);
 return a*pw(a,b-1)%bs;
}

long long inv(long long a)
{
     return pw(a,1000000005);
}

bool isgood(long n)
{
 long q;
 while (n){q=n%10;n/=10;if (q!=a&&q!=b)return false;}
 return true;
}

long long c(long long a,long long b)
{
     long long r;
     r=fact[a];
     r*=inv(fact[b]);
     r%=bs;
     r*=inv(fact[a-b]);
     return r%bs;
}

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>b>>n;

fact[0]=1;

for (int i=1;i<=1000000;i++)
fact[i]=fact[i-1]*i%bs;

for (int na=0;na<=n;na++)
{
    s=a*na+b*(n-na);
    if (isgood(s))
    ans=ans+c(n,na);
}

cout<<ans%bs<<endl;
cin.get();cin.get();
return 0;}