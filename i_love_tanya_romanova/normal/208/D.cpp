/*
Processed, diluted
Virtually unrecognizable
I was lost there, no direction
A scattered void

No more, it's over, I'm onto you
(You're evil game)
The tables have turned
I'm taking back my soul

Tranquilized, scrutinized
Hate injected mind
As if eternal wounds
Wouldn't bleed, wouldn't hurt me

No more, it's over, I'm onto you
(You're evil game)
The tables have turned
I'm taking back my soul

I see through you're lies
Taking back whats mine

No more, it's over, I'm onto you
(You're evil game)
The tables have turned
I'm taking back my soul

No more, it's over, I'm onto you
(You're evil game)
The tables have turned
I'm taking back my soul, my soul
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
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long n,ps[1000],b[1000];
long long s,ans[100];

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ps[i];
for (int i=1;i<=5;i++)
cin>>b[i];

for (int i=1;i<=n;i++)
{
 s+=ps[i];
 for (int j=5;j;j--)   
 {ans[j]+=s/b[j];s%=b[j];}
}

for (int i=1;i<=5;i++)
{if (i>1)cout<<" ";cout<<ans[i];
}
cout<<endl;
cout<<s<<endl;

cin.get();cin.get();
return 0;}