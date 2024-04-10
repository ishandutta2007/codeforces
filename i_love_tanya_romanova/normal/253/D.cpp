/*
We swear it on the bible
If wanted on the Koran
It's always good for trouble
To have a holy ghost

We have made the decision
There is forgiveness, if you need
But this is not in this world
You have to wait and wait

There is no - no other way
You can't just believe what you want
No other way - no no
You can read it in the book, what's good or bad

Heaven is there where hell is
And hell is down on earth, oh yes it is
Heaven is there where hell is
And hell is down on earth, oh yeah

You shouldn't kill your brother
Except if he doesn't know what's right
If he can't love your heaven
Ah, it's a mercy for him to die

And that it's so much better
Than to live without redemption
This is easy to do so
And you can read how it works

All you need - is the holy ghost
Oh, he will comfort you
No other way - no no
That's how they're cheating you
And make believe what's good or bad

Heaven is there where hell is
And hell is down on earth, is it heaven or hell
Heaven is there where hell is
And hell is down on earth

Down on earth, oh yes it is
Is it heaven or hell

I'm sure we all know them
Those perverts, they're everywhere
Mmh, we're talking straight about facts
You know deep inside what's right or wrong
And the world stinks, and the paradise is now a sewer
And they sell shit for gold
And you have to take what you've got

Heaven is never in heaven - and hell is down on earth
Heaven is there where hell is - and hell is down on earth
Hahaha, heaven is never in heaven - and hell is down on earth
Heaven is there where hell is - and hell is down on earth
Heaven is never in heaven - and hell is down on earth
Heaven is there where hell is - and hell is down on earth
Hahahaha

Heaven is there where hell is
And hell is down on earth, oh yes it is
Heaven is there where hell is
And hell is down on earth
Oh, don't you think that heaven is there where hell is
And hell is down on earth, tell me is it heaven or hell
Heaven is there where hell is
And heaven is down on earth, hahaha
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
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long n,m,k,s[1000][1000];
char c;
char mas[1000][1000];
long long pos,ans;
vector<long> vec[200];

long gs(long x1,long y1,long x2,long y2)
{
     return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
}

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
 cin>>c;
 s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
 if (c=='a')++s[i][j]; 
 mas[i][j]=c;  
}

for (int urow=1;urow<=n;urow++)
for (int drow=urow+1;drow<=n;drow++)
{
 
 for (int chr='a';chr<='z';chr++)
 vec[chr].clear();
 
 for (int i=1;i<=m;i++)
 {
  if (mas[urow][i]==mas[drow][i])
  {
   vec[mas[urow][i]].push_back(i);
  }
 }
 
 for (int c='a';c<='z';c++)
 {
     pos=0;
     for (int j=0;j<vec[c].size();j++)
     {
      while (pos<=j)++pos;
      while (pos<vec[c].size()&&gs(urow,vec[c][j],drow,vec[c][pos])<=k)++pos;   
      ans+=pos-j-1;
     }
 }   
// cout<<urow<<" "<<drow<<" "<<ans<<endl;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}