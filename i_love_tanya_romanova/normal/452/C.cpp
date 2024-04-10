/*
I'm gazing upward, a world I can't embrace
There's only thorns and splinters, venom in my veins
It's okay to cry out, when it's driving you insane
But somehow someday, I'll have to face the pain

It's all gone cold
But no one wants the blame
It's all so wrong
But who am I, who am I to say?

I'm begging for forgiveness, everything I've done
If God is listening, He knows I'm not the only one
It's okay to lash out from the rules that I'm enslaved
But somehow someday, I'll have to turn the page

It's all gone cold
And no one wants to change
It's all so wrong
But no one wants the blame

It's all gone cold
There's nothing left to gain
It's all so wrong
But who am I, who am I to say?

My heart's an endless winter filled with rage
I'm looking forward to forgetting yesterday

It's all gone cold
And no one wants to change
It's all so wrong
But no one wants the blame

It's all gone cold
There's nothing left to gain
It's all so wrong
But who am I, who am I to say?
To say

It's all gone cold
But who am I to say?
It's all gone cold
But who am I, who am I to say?

Cold
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

double tways,nways,pth,pwin,ans;
double fact[1200000];
long n,m;

double gc(long n,long m)
{
 if (m>n)return 0;
 double res=1;
 res*=fact[n];
 res/=fact[n-m];
 res/=fact[m];
 return res;
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cout.precision(12);
cin>>n>>m;
fact[0]=1;
for (int i=1;i<=1000000;i++)
 fact[i]=fact[i-1]*i;
/*
tways=gc(n*m,n);

for (int am=1;am<=n;am++)
{
 nways=n*gc(m,am)*gc(n*m-m,n-am);// hp q chs
 pth=nways/tways;// th ev P
 pwin=pth*(am*1.0/n)*am*1.0/n;// nld it, bth t
 //cout<<pth<<" "<<pwin<<endl;
 ans+=pwin;
}

cout<<fixed<<ans<<endl;
*/
ans=1.0/n; // same crd

if (m>1){
ans+=1.0*(m-1)// same clr
*(n-1)/(n*m-1)// 2 b in
*(1.0/n);}

cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}