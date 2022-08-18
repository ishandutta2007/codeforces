/*
Trapped in a nightmare prisoners of warfare
Days gone become years of suffering
Fight on but what's to gain
Misfortune leads to pain

Fearless they won't die
Caged in they ask why
Cry out but don't cry
With agony

Live on but what's to gain
Die slowly everyday
Misfortune leads to pain
Will they ever be saved
From agony, agony, agony

In silent suffering
It's never ending
They pray to end their
Misery

Fight on but what's to gain
Die slowly everyday
Misfortune leads to pain
Will they ever be saved
From agony, agony, agony

Missing in action
Never forgotten
America the mighty
Set them free

Fight on but what's to gain
Die slowly everyday
Misfortune leads to pain
Will they ever be saved
From agony, agony, agony

With agony
Don't go stray
Agony
Good sensation
Agony
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000

using namespace std;

long long k,b,n,t,ans,cur;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>k>>b>>n>>t;
ans=n;
cur=k+b;
while(cur<=t){cur=cur*k+b;--ans;}
if (ans<0)ans=0;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}