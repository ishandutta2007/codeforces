/*
I'm in conniptions for the final act you came here for
The one derivative you manage is the one I abhor 
I need a minute to elaborate for everyone the 
Everyday bullshit things that you have done 

Your impossible ego fuck is like a 
Megalomaniacal tab on my tongue 
You fuckin' touch me I will rip you apart 
I'll reach in and take a bite out of that 
Shit you call a heart... 

I don't mind being ogled, ridiculed 
Made to feel miniscule 
If you consider the source, it's kinda pitiful 
The only thing you really know about me is... 
...that's all you'll ever know 

I know why you blame me (yourself) 
I know why you plague me (yourself) 

I'm turning it around like a knife in the shell 
I wanna understand why, but I'm hurting myself
I haven't seen a lotta reasons to stop it 
I can't just drop it 
I'm just a bastard, but at least I admit it 
At least I admit it 

I know why you blame me (yourself) 
I know why you plague me (yourself) 

Kill you - fuck you - i will never be you 
Kill you - fuck you - i will never be you 
I can't fuckin' take it anymore 
A snap of the synapse 
And now it's fuckin' war 
Kill you - fuck you - i will never be you
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
#define bsize 256

using namespace std;

long n,ans;
long t;
vector<long> g[200000];

int main(){
//freopen("cylinders.in","r",stdin);
//freopen("cylinders.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
if (i*(i-1)/2<=n)ans=i;

cout<<ans<<endl;
for (int i=1;i<=ans;i++)
for (int j=i+1;j<=ans;j++)
{
    ++t;
    g[i].push_back(t);
    g[j].push_back(t);
}

for (int i=1;i<=ans;i++)
{
 for (int j=0;j<g[i].size();j++)
 {if (j)cout<<" ";cout<<g[i][j];}
 cout<<endl;
}

cin.get();cin.get();
return 0;}