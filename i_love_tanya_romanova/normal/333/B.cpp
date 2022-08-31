/*  
Hear me now
Bearing down upon a path we choose
Chosen from the start living different rules
Existence something to cherish true
Will not succumb to doubts that I hold onto
Release the fear of my pain
In so much pain
Give me the will to fight
Every obstacle that I have inside
Release the fear and

Hear me now
Words I vow
No fucking regrets

Fuck these chains
No god damn slave
I will be different

I'll stand here defiantly
My middle finger raised
Fuck your prejudice

All my life
Always I've felt alone
Conditioned to believe that I'm always wrong
Only truth will help to set me free
My every weakness I must turn into strength
Every rage, every tear
Hate in so much hate
Never that pain will bind me
Ask of myself if I've the will to unwind
Every rage and tear

Hear me now
Words I vow
No fucking regrets

Fuck these chains
No god damn slave
I will be different

I'll stand here defiantly
My middle finger raised
Fuck your prejudice

Carved upon my stone
I will go on
Patience, belief
Love will ascend

Just listen to it
Voice so true inside calling
To pick you up and march you on
Keep from falling
Let go your sorrow
Sun will shine, this I promise
Rising tommorow
Rising

Hear me now
I'm taking back the control
Of my
Life from society's hold
I vow
No more will I be a slave
Rise to
Challenge the whole human race

My spirit you cannot break

When we won't los
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
#define eps 1e-9
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,m,bi[2000],bj[2000],mput,a,b,dp[2000];

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    bi[a]=1;
    bj[b]=1;
}

for (int i=2;i<n;i++)
{
 mput=2;
 if (bi[i]==1)mput--;
 if (bj[i]==1)mput--;
 if (i*2-1==n&&mput==2)
 mput=1;
 dp[i+1]=dp[i]+mput;
}

cout<<dp[n]<<endl;

cin.get();cin.get();
return 0;}