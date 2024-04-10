/*
Freezin', rests his head on a pillow made of concrete, again 
Oh, Feelin' maybe he'll see a little better, set a days, ooh yeah 
Oh, hand out, faces that he sees time again ain't that familiar, oh yeah 
Oh, dark grin, he can't help, when he's happy looks insane, oh yeah 
Even flow, thoughts arrive like butterflies 
Oh, he don't know, so he chases them away 
Someday yet, he'll begin his life again 
Life again, life again... 
Kneelin', looking through the paper though he doesn't know to read, ooh yeah 
Oh, prayin', now to something that has never showed him anything 
Oh, feelin', understands the weather of the winters on it's way 
Oh, ceilings, few and far between all the legal halls of shame, yeah 
Even flow, thoughts arrive like butterflies 
Oh, he don't know, so he chases them away 
Someday yet, he'll begin his life again 
Whispering hands, gently lead him away 
Him away, him away... 
Yeah! 
Woo... ah yeah... fuck it up... 
Even flow, thoughts arrive like butterflies 
Oh, he don't know, so he chases them away 
Someday yet, he'll begin his life again, yeah 
Oh, whispering hands, gently lead him away 
Him away, him away... 
Yeah!
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

long long n,ar[3000],c[2100][2100],hput,cpos;
long long ar1[3000],ar2[3000];
long long fact[5000],ways[5000];

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int i=0;i<=2000;i++)
for (int j=0;j<=2000;j++)
if (j==0||j==i)c[i][j]=1;
else c[i][j]=(c[i-1][j]+c[i-1][j-1])%bs;

for (int i=1;i<=n;i++)
if (ar[i]==-1)ar1[i]=1;

for (int i=1;i<=n;i++)
if (ar[i]>0)ar2[ar[i]]=1;

for (int i=1;i<=n;i++)
if (ar1[i]==1&&ar2[i]==0)
hput++;

//i-e mod Q
// gpq

for (int i=1;i<=n;i++)
if (ar1[i]==1)
cpos++;

//cout<<cpos<<" "<<hput<<endl;

fact[0]=1;
for (int i=1;i<=2500;i++)
fact[i]=fact[i-1]*i%bs;

for (int bad=0;bad<=hput;bad++)
ways[bad]=c[hput][bad]*fact[cpos-bad]%bs;
/*
for (int i=0;i<=hput;i++)
cout<<ways[i]<<" ";
cout<<endl;
*/

// lput, %bs

for (int i=hput-1;i>=0;i--)
for (int j=i+1;j<=hput;j++)
{
    ways[i]=ways[i]-ways[j]*c[j][i]%bs;
    while (ways[i]<0)ways[i]+=bs;
}

/*
for (int i=0;i<=hput;i++)
cout<<ways[i]<<" ";
cout<<endl;
*/

//http://oeis.org/A000166
cout<<ways[0]<<endl;

cin.get();cin.get();
return 0;}