/*
The hands of the wicked
They lie and they wait for you
Servents remember
The torture you put us through
Living in fear
Thoughts that never knew.
Your day has come and
Time has cought up with you!!!

There's no tomorrow
There's no tomorrow for all of you

You wish forever
The life you have will last
You can not deceive us
Remember your evil past.
We're! gonna get you
Destined for the other side
Nowhere to run.
No place to hide!!!

There's no tomorrow
There's no tomorrow for all of you...
Your life is through...

There's... no tomorrow... beginning or end
No choice of life... it lies in the hands...
Their minds are made... in the end...
No tomorrow... cause you are dead!!!

Then caught alive, your soul set us on fire
You scream for mercy, the flames and they burn you higher
Wished with hope not the truth that you would find
But its hard to live when life is so blind!

There's no tomorrow
There's no tomorrow for all of you...
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
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long temp;
long n,q,bst[100000],bp[10000],bpos[10000];
long pr[600][600];
long tp[600][600];
long t;
vector<pair<long, long> > v;

int main(){
//freopen("deques.in","r",stdin);
//freopen("deques.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=n;j++)
    {cin>>q;pr[i][q]=j;}
}

for (int i=1;i<=n;i++)
{
    bst[i]=100000;
    bpos[i]=0;
}

for (int i=1;i<=n;i++)
{
    cin>>t;
    bp[t]=i;
}

for (int i=1;i<=n;i++)
{
    v.push_back(make_pair(bp[i],i));
    sort(v.begin(),v.end());
    for (int j=1;j<=n;j++)
    {
        if (v[0].second==j)
        {
         if (i==1)continue;
         temp=v[1].second;
         if (pr[j][temp]<bst[j]){bst[j]=pr[j][temp];bpos[j]=i;}
        }
        else
        {
         temp=v[0].second;
         //cout<<i<<" "<<j<<" "<<temp<<"   "<<pr[j][temp]<<endl;
         if (pr[j][temp]<bst[j]){bst[j]=pr[j][temp];bpos[j]=i;}
        }
    }
}

for (int i=1;i<=n;i++)
{if (i>1)cout<<" ";cout<<bpos[i];}
//<<" "<<bst[i]<<endl;
cout<<endl;
cin.get();cin.get();
return 0;}