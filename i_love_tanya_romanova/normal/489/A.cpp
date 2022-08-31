/*
The lies!
Oh, the lies have shattered us all.

I speak from my perspective.
The lonely fears he bore have inspired me.
These writings can only say so much.
But it's still your fault.

I have seen disaster.
It all came down, and I have witnessed tragedy.
To lose it all, to lose it all.
And I can't take it anymore.

I bear no comfort, and give no peace.
What is it that he saw?
Brought him to sacrifice.

I forfeit all apprehension for you.
To escape affliction from your existence.

The lies!
Oh, how the lies have shattered us all.

Fabrication of the truth from the widow's mouth.
Just to justify of being bereft of fucking life.

Is there anything left in life that's worth dying for?!

To die for...
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,ar[1<<15],bst,bp;
vector<pair<long, long> > ans;

int main(){
//freopen("billing.in","r",stdin);
//freopen("billing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>ar[i];
}

for (int iter=0;iter<n;iter++)
{
 bst=1e9;
 bp=-1;
 for (int j=iter+1;j<n;j++)
  if (ar[j]<bst)
  {
   bst=ar[j];
   bp=j;
  }
  if (bp>iter&&bst<ar[iter])
  {
   ans.push_back(make_pair(iter,bp));
   swap(ar[iter],ar[bp]);
  }
}
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
 
cin.get();cin.get();
return 0;}