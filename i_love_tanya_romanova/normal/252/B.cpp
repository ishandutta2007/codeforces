/*
Endless destruction
Blood falls like rain
The war of the demons
Will give you pain
Inverted crosses
The reaper will rise
The war of the demons
Will make you die
I'll take you down into my grave
I'll rip your flesh and torment your face
Your cry in the night none will hear
It's time to die you're living in fear
Fight with the mortals
Death is their goal
Eating the corpses
And sell all their souls
Obey the commands
Of the black majesty
You know your soul
Will never be free
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long ar[200000],ar1[200000],p1,p2;
long ans1,ans2,n;
long fl1,fl2;
vector<pair<long, long> > v;

int main(){
//freopen("galaxy.in","r",stdin);
//freopen("galaxy.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    if (i==1||ar[i]!=ar[i-1])
    v.push_back(make_pair(ar[i],i));
    if (i>1&&ar[i]==ar[i-1]&&ar[i-1]!=ar[i-2])
    v.push_back(make_pair(ar[i],i));
}

for (int iters=1;iters<=60;iters++)
{
 p1=rand()%v.size();
 p2=rand()%v.size();
 if (p1==p2)continue;
 
 for (int i=1;i<=n;i++)
 ar1[i]=ar[i];
 if (ar1[v[p1].second]==ar1[v[p2].second])continue;
 swap(ar1[v[p1].second],ar1[v[p2].second]);
 fl1=fl2=0;
 for (int i=2;i<=n;i++)
 {
     if (ar1[i]>ar1[i-1])fl1=1;
     if (ar1[i]<ar1[i-1])fl2=1;
 }   
 if (fl1&&fl2)
 {
  ans1=v[p1].second;
  ans2=v[p2].second;
 }
}

if (ans1+ans2==0)cout<<-1<<endl;
else cout<<ans1<<" "<<ans2<<endl;

cin.get();cin.get();
return 0;}