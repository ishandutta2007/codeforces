/*
Do you remember a long time ago
Seems to be lightyears away
Thunder and lightning
Cracking the sky
It was a living hell

People were fighting
And kill to survive
Fearing the end of the day
End and the evil came
Taking their souls

Only the strong survive
Killing to see their lives
Wise men could tell no lies
But what's on their hands
The beginning of the end

This is the end of the days
Save your breath
Until the dawn brings you light

It was the silence
Before the storm
Something was there to arise
Earth starts to ramble
The rise in the stark
Lord of the darkness was here

They kept on fighting
No way to survive
Facing the end of the day
And then the evil came
Taking their souls
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n,a,b,q,ans[2000];

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
cin>>n>>a>>b;
for (int i=1;i<=a;i++)
{
 cin>>q;
 ans[q]=1;
}
for (int i=1;i<=b;i++)
{cin>>q;ans[q]=2;}
for (int i=1;i<=n;i++)
{
 if (i-1)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}