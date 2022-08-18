/*
Hey!
Don't walk away
I'm not done with you, you're not done with me
Stop!
We can't survive
Will you die for me cause I'd die for you?
I'm not insane cut out my heart with this razor blade
Take this sacrifice
You can feed on me
Can I feed on you?

Come take this sacrifice!
Come take this sacrifice!

You don't bring me pleasure
You just bring me pain
Over and over again
You don't bring me pleasure
You just bring me pain
And nothing in between

Hey!
There's no escape
You can't run from me
I can't run from you
Bow
'cause I'm your god
Will you pray for me 'cause I'll pray for you?
Push your sins aside nobody cares your head's fucked inside
Embrace your apathy
I don't care for you
You don't care for me

Embrace your apathy
Embrace your apathy

You don't bring me pleasure
You just bring me pain
Over and over again
You don't bring me pleasure
You just bring me pain
And nothing in between
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long n;long long ar[1200000];
long long c[1200000];
long long res;
vector<long long> vec;
map<long long, long long> calc;
long long temp;
long long gcd(long long a,long long b)
{
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}
map<long long, long long>::iterator it;

long long solve(long long x)
{
 calc.clear();
 vec.clear();
 
 for (int i=1;i<=n;i++)
 {
     temp=gcd(x,ar[i]);
     calc[temp]++;
 }
 
 for (it=calc.begin();it!=calc.end();++it)
 {
  vec.push_back((*it).first);   
 }
 
 for (int i=0;i<vec.size();i++)
 c[i]=0;
 
 for (int i=0;i<vec.size();i++)
  for (int j=0;j<=i;j++)
   if (vec[i]%vec[j]==0)
   {
    c[j]+=calc[vec[i]];
   }
 long long r=0;
 for (int i=vec.size()-1;i+1;i--)
  if (c[i]*2>=n)return vec[i];
/* for (int i=0;i<vec.size();i++)
 cout<<c[i]<<"  "<<vec[i]<<endl;
 cout<<endl;
 */
  return r;
}

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
random_shuffle(ar+1,ar+n+1);

for (int iter=1;iter<=14;iter++)
{
 res=max(res,solve(ar[(1ll*rand()*rand())%n+1]));   
}
cout<<res<<endl;

cin.get();cin.get();
return 0;}