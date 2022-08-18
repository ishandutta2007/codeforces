/*
The man takes another bullet
He keeps them all within
He must seek, no matter how it hurts
So don't fool again

He thinks the answer is cold and in his hand
He takes his medicine
The man take another bullet
He's been fooled again

*Uncross your arms and take
And throw them to the cure, say...
I do believe
Uncross your arms now
Take 'em to it, say...
I do believe

The lies tempt her and she follows
Again she lets him in
She must believe to fill the hollow
She's been fooled again

[* Repeat]

Betting on the cure
Cause it must get better than this
Betting on the cure
Yeah everyone's got to have the sickness
'Cause everyone seems to need the cure
Precious cure

I do believe

Betting on the cure
Yeah, it must get better than this
Need to feel secure
Yeah, it's gonna get better than this
It must get better than this
Betting on the cure

Yeah, everyone's got to have the sickness
'Cause everyone seems to need the cure

I do believe
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
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long n,ar1[200000],ar2[200000];
long q;
vector<pair<long, long> > ans;

void domove(long a,long b)
{
     if (a==b)return;
     swap(ar2[a-1],ar2[a]);
     ans.push_back(make_pair(a-1,a));
     domove(a-1,b);
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar1[i];
for (int i=1;i<=n;i++)
cin>>ar2[i];

for (int i=1;i<=n;i++)
{
    q=i;
    while (ar2[q]!=ar1[i])++q;
    domove(q,i);
//    cout<<q<<" "<<endl;
  /*  for (int j=1;j<=n;j++)
    cout<<ar2[j]<<" ";
    cout<<endl;*/
}
cout<<ans.size()<<endl;
/*
for (int i=1;i<=n;i++)
cout<<ar1[i]<<" ";
cout<<endl;
for (int i=1;i<=n;i++)
cout<<ar2[i]<<" ";
cout<<endl;
*/
for (int i=0;i<ans.size();i++)
cout<<ans[i].first<<" "<<ans[i].second<<endl;

cin.get();cin.get();
return 0;}