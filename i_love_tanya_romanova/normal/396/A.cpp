/*
Who hears the voices calling - who calls to rise above them?
Who rises when they've fallen, taking an oath for the trouble they're causing.
Who reaches out for knowing, who knows when they've been chosen?
Who chooses not to burden the path of the brother with light before him.
Saviour...
Who lives a life of slumber, who sleeps upon the water?
Whos water drowns the others, taking an oath for the trouble they're causing.
Who asks a simple question, who knows when who's forgiven?
Who chooses whose redemption?
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
 
//#define free asdfasdfsdadsg
#define bsize 512
 
using namespace std;

long long ans;
long q,n;
set<long> divs;
set<long>::iterator it;
map<long, long> calc;
long long fact[200000];

long long pw(long long a,long long b)
{
 if (b==0)return 1;
 if (b%2)return a*pw(a,b-1)%bs;
 return pw(a*a%bs,b/2);
}

long long inv(long long x)
{
 return pw(x,bs-2);
}

long long c(long long n,long long m)
{
 long long res=1;
 res=fact[n];
 res*=inv(fact[m]);
 res%=bs;
 res*=inv(fact[n-m]);
 return res%bs;
}

void solve(long x)
{
 for (int i=2;i*i<=x;i++)
 {
  while (x%i==0){divs.insert(i);calc[i]++;x/=i;}
 }
 if (x>1){divs.insert(x);calc[x]++;}
}

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

fact[0]=1;
for (int i=1;i<=30000;i++)
fact[i]=fact[i-1]*i%bs;

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 solve(q);
}
ans=1;
for (it=divs.begin();it!=divs.end();it++)
{
 q=(*it);
 q=calc[q];
 ans=ans*c(n+q-1,n-1)%bs;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}