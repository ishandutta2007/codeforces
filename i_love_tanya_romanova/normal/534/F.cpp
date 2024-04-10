/*
Oh yeah
Uh back in the wood
Where it's good
And the days are yellow
Well I saw me a child
She was wild
Like a lady going all out

Dark as the night
She was ripe
For a little conversation
So I pulled her right in
And she said
She had some imagination

Black swampy water
That's where I caught her
Black swampy water
Black swampy water

We didn't speak
For a week
Got tangled up in her hair
So we lay in the grass
What a gas
You can't know that you were there

So then I let it all go
And the show
Was like blowing up a freight train
And round the world I would go
Like jumping on a jet plane

Black swampy water
That's where I caught her
Black swampy water
Uh, what I taught her, yeah

Oh, back in the wood
Where it's good
And the days are yellow
Gotta saw me a child
She was wild
Like a lady going all out

I've been
Black swampy water
All right
That's where I caught her, oh
Black swampy water
Oh all the things that I taught her
Yes, again

Black swampy water, my my
Where I saw here, oh
Black swampy water
What I did when I caught her, oh yeah yeah
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,m,ans[100][100],ar[100][100];
long found;
long have[100],in_row[100],in_col[100];

set<long long> did;

void backtrack(long col)
{
 
 if (found)return;
 
 for (int i=1;i<=n;i++)
  if (have[i]>in_row[i])
   return ;
 for (int i=1;i<=n;i++)
  if (have[i]+(m-col+2)/2<in_row[i])
   return ;
   
 long long hash=0;
 for (int i=1;i<=n;i++)
  hash=hash*173+ar[i][col-1];
 for (int i=1;i<=n;i++)
  hash=hash*173+have[i];
 
 hash=hash*173+col;
 
 if (did.find(hash)!=did.end())
  return;
 did.insert(hash); 
 /*
 for (int i=1;i<=n;i++)
 {
     for (int j=1;j<=m;j++)
      cout<<ar[i][j];
      cout<<endl;
 }
 for (int i=1;i<=m;i++)
 {
     cout<<have[i]<<" ";
 }
 cout<<endl;
 
 cout<<endl;
 cin.get();
 */
 if (col==m+1)
 {
  int er=0;
  for (int i=1;i<=n;i++)
   if (have[i]!=in_row[i])
    er=1;
  if (er==0)
  {
   if (found)return;
   found=1;
   for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
     ans[i][j]=ar[i][j];
  }
  return;
 }
 
 for (int mask=0;mask<(1<<n);mask++)
 {
  for (int j=0;j<n;j++)
   if (mask&(1<<j))
    ar[j+1][col]=1;
    else 
    ar[j+1][col]=0;
  long in_this=0;
  for (int j=1;j<=n;j++)
   if (ar[j][col]==1&&ar[j-1][col]==0)
    in_this++;
  if (in_this!=in_col[col])continue;
  
  vector<int> inv;
  
  for (int j=1;j<=n;j++)
   if (ar[j][col]==1&&ar[j][col-1]==0)
    inv.push_back(j);
  
  for (int j=0;j<inv.size();j++)
   have[inv[j]]++;
  backtrack(col+1);
  for (int j=0;j<inv.size();j++)
   have[inv[j]]--;
 }
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
 cin>>in_row[i];
for (int i=1;i<=m;i++)
 cin>>in_col[i];

backtrack(1);

for (int i=1;i<=n;i++)
{
    for (int j=1;j<=m;j++)
     if (ans[i][j])cout<<"*";
    else cout<<".";
    cout<<endl;
}

cin.get();cin.get();
return 0;}