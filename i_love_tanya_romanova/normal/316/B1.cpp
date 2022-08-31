/*
Livin' after midnight, rockin' to the dawn
Lovin' till the mornin', then I'm gone, I'm gone

I took the city 'bout one a.m.
Loaded, loaded
I'm all geared up to score again
Loaded, loaded

I come alive in the neon light
That's when I make my moves right

Livin' after midnight, rockin' to the dawn
Lovin' till the mornin', then I'm gone, I'm gone

Got gleaming chrome, reflecting steel
Loaded, loaded
Ready to take on every deal
Loaded, loaded

My pulse is racing, I'm hot to take
But this motor's revved up, fit to break

Livin' after midnight, rockin' to the dawn
Lovin' till the mornin', then I'm gone, I'm gone

I'm aiming for ya
I'm gonna floor ya
My body's comin'
All night long

The air's electric, sparkin' power
Loaded, loaded
I'm getting hotter by the hour
Loaded, loaded

I set my sights and then home in
The joint starts flying when I begin

Livin' after midnight, rockin' to the dawn
Lovin' till the mornin', then I'm gone, I'm gone

Livin' after midnight, rockin' to the dawn
Lovin' till the mornin', then I'm gone, I'm gone
Livin' after midnight, rockin' to the dawn
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
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,x,nums,num[10000],qq[10000],deep[10000],q,cn[10000],sz[10000],usd[10000];

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>x;
nums=0;
for (int i=1;i<=n;i++)
{
 cin>>qq[i];
 q=qq[i];
 if (q==0){
 num[i]=nums+1;
 nums++;sz[nums]=1;
 deep[i]=1;}
 if (i==x)
 usd[num[i]]=1;
}
 
for (int iter=1;iter<=1000;iter++)
for (int i=1;i<=n;i++)
if (deep[qq[i]]>0&&deep[i]==0){
     
     q=qq[i];
      num[i]=num[q];
 sz[num[i]]++;
 deep[i]=deep[q]+1;
 
 if (i==x)
 usd[num[i]]=1;
}
/*for (int i=1;i<=n;i++)
cout<<usd[i]<<" "<<sz[i]<<endl;
*/
cn[deep[x]]=1;
for (int i=1;i<=nums;i++)
if (usd[i]==0)
for (int j=1000;j>=0;--j)
if (cn[j])cn[j+sz[i]]=1;

for (int i=1;i<=1000;i++)
if (cn[i])cout<<i<<endl;

cin.get();cin.get();
return 0;}