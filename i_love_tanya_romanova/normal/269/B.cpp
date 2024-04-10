/*
Separate me from the dead all around
Smashed into the ground
Ecstasy of killing blinded my eyes
I cannot remember the day it has begun,
Nor do I know why
Once I learned to kill and fight
For a battle that was in sight
When I'm dreaming,
I still hear them marching on
In the darkness,
Innocence got ripped
Out of my heart
I washed my hands in the blood of
The man that just have been killed
The beast in me had risen again,
Gave death into my hands
Oh, ripping, shooting, burning
That's the way, that I got drilled
Menmachine of no remorse.
The killer is deep in me
When I'm dreaming
I still hear them marching on
In the darkness. I start to pray:
Let me live, let me love again
Let me drop my head - into your lap
Let me live - let me love again
Ease my pain - when I'm home again
Wondering 'bout what a man is able to take
Wondering why I'm still alive
Exodus of humanity, already, it hast begun
Skulls and bones around me
A bloodbath full of lies
Insignia of imperfection branded in every face
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,tp[200000];
double dou;
long ans[20000];
long answ;

int main(){
//freopen("test.in","r",stdin);
//freopen("test.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>tp[i]>>dou;

for (int i=1;i<=n;i++)
{
    ans[i]=-1000000;
}
for (int i=1;i<=n;i++)
{
    ans[i]=max(ans[i],n-n+1);
    for (int j=i+1;j<=n;j++)
    if (tp[j]>=tp[i])ans[j]=max(ans[j],ans[i]+1);
}
answ=0;
for (int i=1;i<=n;i++)
answ=max(answ,ans[i]);
cout<<n-answ<<endl;

cin.get();cin.get();
return 0;}