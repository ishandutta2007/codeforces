/*
I'm so tired of being here
Suppressed by all my childish fears
And if you have to leave
I wish that you would just leave
'Cause your presence still lingers here
And it won't leave me alone

These wounds won't seem to heal
This pain is just too real
There's just too much that time cannot erase

[Chorus:]
When you cried I'd wipe away all of your tears
When you'd scream I'd fight away all of your fears
And I held your hand through all of these years
But you still have
All of me

You used to captivate me by your resonating light
Now I'm bound by the life you left behind
Your face  it haunts my once pleasant dreams
Your voice  it chased away all the sanity in me

These wounds won't seem to heal
This pain is just too real
There's just too much that time cannot erase

[Chorus]

I've tried so hard to tell myself that you're gone
But though you're still with me
I've been alone all along

[Chorus]

...me, me, me.
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

long bonus[500][500];
long k;
long temp;
string st1,st2,st;
long cost;
long dp[101][101][40];
long answ;

int main(){
//freopen("revolutions.in","r",stdin);
//freopen("revolutions.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st>>k;
cin>>temp;
for(int i=0;i<temp;i++)
{cin>>st1>>st2>>cost;
 bonus[st1[0]][st2[0]]=cost;
}

for (int i=0;i<=st.size();i++)
for (int j=0;j<=k;j++)
for (int p=0;p<=26;p++)
dp[i][j][p]=-100000000;
dp[0][0][0]=0;

for (int i=0;i<st.size();i++)
{
    for (int j=0;j<=k;j++)
    {
     for (int oldchar='a';oldchar<='z';oldchar++)
     for (int nchar='a';nchar<='z';nchar++)
     {long nk,nscore;
         if (nchar==st[i])nk=j;else nk=j+1;
         nscore=dp[i][j][oldchar-'a'];
         if (i>0)nscore+=bonus[oldchar][nchar];
         dp[i+1][nk][nchar-'a']=max(dp[i+1][nk][nchar-'a'],nscore);
     }   
    }
}

answ=-1000000000;

for (int i=0;i<=k;i++)
for (int q=0;q<=26;q++)
answ=max(answ,dp[st.size()][i][q]);
cout<<answ<<endl;

cin.get();cin.get();
return 0;}