/*
Sometimes things get in the way
My thoughts I cannot convey
It's all pointing straight at you
We hate loving everyday
Our lives twirled in every way
I give it all back to you

I can't help this going down

I can't take this
All my life is wreckless
All our lives our dangerous
But we fake our way through
That's what we do

Sometimes things don't go away
In turn you just run away
It's all coming back for you
Betrayed, life is in decay
Your thoughts you cannot obey
Right now, what cha gonna do?

I can't help this going down

I can't take this
All my life is wreckless
All our lives our dangerous
But we fake our way through
That's what we do

We do, we do, we do, we do,
We do, we do, we do, we do, we do

I hear the calling of the helpless stranger
He's all alone and no one hears his anger
I feel his pain every time I'm here with you
With you
All the heartache and the fucked up insults
I find you begging on your knees, I figured
This is how it's supposed to be with you
With you

I can't wait for your life to be broken down
I gave you hate

Ah!

I can't take this
All my life is wreckless
All our lives our dangerous
But we fake our way through
That's what we do
I can't take this
All my life is wreckless
All our lives our dangerous
But we fake our way through

That's what we do
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

using namespace std;

string st;
long pre[600][600],dp[600][600],par[600][600],bst,bp;
long k;
long temp;
vector<string> vec;

string solve(long l,long r)
{
 string rr="";
 for (int i=l;i<=r;i++)
  rr+=st[i];
 for (int i=0;i<rr.size();i++)
  if (rr[i]!=rr[rr.size()-i-1])
   rr[i]=rr[rr.size()-i-1];
 return rr;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st>>k;
long n=st.size();

for (int span=1;span<st.size();span++)
{
 for (int l=0;l+span<st.size();l++)
 {
  pre[l][l+span]=pre[l+1][l+span-1];
  if (st[l]!=st[l+span])++pre[l][l+span];
 }
}

for (int i=0;i<=st.size();i++)
 for (int j=0;j<=k;j++)
  dp[i][j]=1e9;

dp[0][0]=0;
for (int i=0;i<st.size();i++)
 for (int j=0;j<k;j++)
  for (int nw=i+1;nw<=st.size();nw++)
  {
   long temp=dp[i][j];
   temp+=pre[i][nw-1];
   if (temp<dp[nw][j+1])
   {
    dp[nw][j+1]=temp;
    par[nw][j+1]=i;
   }
  }

bst=1e9;
bp=0;
for (int i=1;i<=k;i++)
{
 if (dp[n][i]<bst)
 {
  bst=dp[n][i];
  bp=i;
 }
} 

cout<<bst<<endl;//<<" "<<bp<<endl;

for (int i=bp;i;--i)
{
 temp=par[n][i];
 vec.push_back(solve(temp,n-1));
 n=temp;
}

reverse(vec.begin(),vec.end());
for (int i=0;i<vec.size();i++)
{
 if (i)cout<<"+";
 cout<<vec[i];
}

cout<<endl;

cin.get();cin.get();
return 0;}