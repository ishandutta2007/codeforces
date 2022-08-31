/*  
Yeah Yeah
Yeah Yeah
Ooooohhhh Yeah

Bad

Yeah
Come clean, 'fess up
Tell all, spill gut
Off the veil, stand revealed
Show the cards
Bring it on
Break the seal

(Ladies and Gentleman, step right up and
see the man who told the truth)

Swing the noose again
Peirce the apple skin
You bit more than you need
Now you're choking
On a bad seed
On a bad seed
Ahhh choking

Let on, load off
Confess, cast off
At the mercy, the cat is out
Drop the disguise
Spit it up,
Spit it out

(And now, what you've all been waiting for,
I give you He Who Suffers The Truth)

Swing the noose again
Peirce the apple skin
Yeah, you bit more than you need
Now you're chokin'
On the bad seed
Chokin' on the bad seed, Yeah

Off the vieil
Stand revealed
Bring it on
Break the Seal
At the mercy
Cat is out
Spit it up
Spit it out
Spit it up
Spit it out
Spit it out NOW

At the mercy

(Swing the noose again, Peirce the apple skin, you bit more than you need, choking on the seed)

Swing the noose again
Peirce the apple skin
Yeah you bit more than you need
Ohhh you're chokin' on a
Chokin', chokin', chokin' on a bad seed
Chokin' on a bad seed, Yeah

Off the vieil
Stand revealed
Bring it on
Break the Seal
At the mercy
Cat is out
Spit it up
Spit it out
Spit it up
Spit it out
Spit it out NOW
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
#define eps 0.001
//#define M_PI 3.141592653589793
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

long long k,n,dp[200][200],bad[200][200];
vector<long long> v,v1;
long long temp,bf;
long long s;
vector<long long> ans;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);


for (int i=0;i<=100;i++)
for (int j=0;j<=100;j++)
{
    if (i==j)dp[i][j]=1;
    else if (j<i)dp[i][j]=0;
    else
    {
        temp=0;
        bf=0;
        for (int p=j-1;p>=j-i;p--)
        {
            if (bad[i][p])bf=1;
            temp+=dp[i][p];
            if (temp>1000000000ll)bf=1;
        }
        if (bf)bad[i][j]=1;
        else dp[i][j]=temp;
    }
}

cin>>s>>k;

if (k>65)k=65;
for (int i=0;i<100;i++)
for (int j=0;j<100;j++)
if (bad[i][j]==0)
if (i==k)
v.push_back(dp[i][j]);

sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
if (i==0||v[i]!=v[i-1])
v1.push_back(v[i]);
/*
cout<<v1.size()<<endl;

for (int i=0;i<v1.size();i++)
cout<<v1[i]<<" ";
cout<<endl;
*/
for (int i=v1.size()-1;i>=0;i--)
{
 if (v1[i]<=s)
 {
  ans.push_back(v1[i]);
  s-=v1[i];
 }   
}

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
//cout<<s<<endl;
cout<<endl;

cin.get();cin.get();
return 0;}