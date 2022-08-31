/*
Bypassed the day I can hear them coming
They walk round my door and speak of their coming
My trial awaits got nowhere to run
My only words how soon you have come

And I think about what you told me
When I was about to join in

Defy only if you have a way to resist the lies
Decline only if you have the intention of taking this advice
Apply only if you're not afraid to see your spirit die
Retreat only if you dare not hear yourself say goodbye

Who brought me here this place is familiar
Where houses are black under the sun
Strangers pass on streets with strange names
All I can think is how soon they have come

Look at me now they have cut my hair
It's a long way back
They kicked me down and I could not rise
I will never arrive
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

long n,sz,q,has[200][200];
long fl,ok;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>sz;
 for (int j=1;j<=sz;j++)
 {cin>>q;
  has[i][q]=1;
 }   
}

for (int i=1;i<=n;i++)
{
    ok=1;
    for (int j=1;j<=n;j++)
    {
     if (j==i)continue;
     fl=0;
     for (int q=1;q<=100;q++)
     if (has[j][q]==1&&has[i][q]==0)fl=1;// bt hm
     if (fl==0)ok=0;// pwnd
    }
    if (ok)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

cin.get();cin.get();
return 0;}