/*
Let us be the ones to put the thorn in thy eye
...let us be the ones

Squalid the weak stumbles
Through all of life's obscurities
Lost in sacriliege
Revere the name
Accept the modesty

Falter through speres of the pain
Exhausted hours... Exhausted hours

Nothing from thy world will remain thine
Except the very priviliege to die
Squalid the weak stumbles...
Orgasmic Mass Hysteria!
You're creeping for a charlatan god
Awake...
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

using namespace std;

long long n,k,a[1<<19],b[1<<19],z,pw[1<<19];
long long ans;
vector<long long> s;
long long temp;
long long pi[1<<19];

int main(){
//freopen("army.in","r",stdin);
//freopen("army.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=0;i<n;i++)
{
 cin>>a[i];
}
for (int i=0;i<k;i++)
{
 cin>>b[i];
}

for (int i=n-1;i;--i)
 a[i]-=a[i-1];
for (int i=k-1;i;--i)
 b[i]-=b[i-1];

a[n]=1e9;
a[n]+=7;

for (int i=1;i<k;i++)
s.push_back(b[i]);
s.push_back(1000000007);
for (int i=1;i<n;i++)
s.push_back(a[i]);

/*for (int i=0;i<s.size();i++)
cout<<s[i]<<" ";
cout<<endl;
*/
for (int i=1;i<s.size();i++)
{
 long j=pi[i-1];
 while (j>0&&s[j]!=s[i])
  j=pi[j-1];
 if(s[i]==s[j])++j;
 pi[i]=j;
}

for (int i=k;i<s.size();i++)
 if(pi[i]==k-1)++ans;

if (k==1)ans=n;

cout<<ans<<endl;
/*
for (int i=0;i<s.size();i++)
cout<<pi[i]<<" ";
cout<<endl;
*/
cin.get();cin.get();
return 0;}