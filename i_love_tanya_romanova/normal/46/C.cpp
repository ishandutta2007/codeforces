/*
Nothin' left for me...
I can't live down here no more.
I can't fall from a tree,
I got wings, it ain't my fault.
Understand what's right...
It's so hard to be alone.
It's never tight,
It's been so loose for so long.

Hold on...Hold on...

Understand my fear,
I never been this high before.
I can't fall from cheer alone.
It only takes a breath to believe...

I can't face one more day,
I have tried so many ways.
My life work, all I failed.
I can't waste away on zeal...

Hold on...
A voice tells me hold on...
Somewhere I feel...hold on...
Hold on...
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

string st;
long ans,tans,n,ttl,qpos;

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>st;

for (int i=0;i<st.size();i++)
if (st[i]=='H')++ttl;

ans=1000000;

for (int stp=0;stp<n;stp++)
{
 tans=0;
 qpos=stp;
 for (int i=1;i<=ttl;i++)
 {
     if (st[qpos]=='T')++tans;
     ++qpos;if (qpos==n)qpos=0;
 }
 ans=min(ans,tans);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}