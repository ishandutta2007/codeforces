/*  
Spoken sideways and indirect
Without a single word left unchecked
And by your own admission
no one is ever above suspicion
Defenses never to be let down
The lies readily abound,
gaping jaw tightly wound.
In your desolation
Still searching for nowhere
Desolation
Youre living in nowhere.
Smoking gun, cause and effect
Paradise lost, a beautiful wreck
And to you I solemnly swear
All I ever wanted was away from here
All that for nothing,
what a fucking waste of time
I only took what was rightfully mine
Seek and you shall find.
The dying man might take you with him
Until then Ill split the difference
All that for nothing,
what a fucking waste of time.
Im gonna take what is rightfully mine.
All that for nothing,
what a fucking waste of time
The dying man might take you with him
I swear to you Ill split the difference
All that for nothing
what a fucking waste of time.
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