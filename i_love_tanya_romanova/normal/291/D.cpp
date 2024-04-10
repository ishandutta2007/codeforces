/*
When the world has turned its back
When the days have turned pitch black
When the fear abducts your tongue
When the fire's dead and gone

So what now?
Where go I?

When you think it's all said and done
When you are the ostracized
Selfish ridden dead goodbyes
Twisting of the tourniquet
When the pieces never fit

So what now?
Where go I?

When you think it's all said and done

Bow down
Sell your soul to me
I will set you free
Pacify your demons

Bow down
Surrender unto me
Submit infectiously
Sanctify your demons

Into abyss
You don't exist
Cannot resist
The Judas kiss

When the storm has blacked your sky
Intuition crucify
When the ego strips your reign
Assassinate the living flame

So what now?
Where go I?

When you think it's all said and done
Venom of a life insane
Bites into your fragile veins
Internalize and decimate
Patronize and complicate

So what now?
Where go I?

When you think it's all said and done

Bow down
Sell your soul to me
I will set you free
Pacify your demons

Bow down
Surrender unto me
Submit infectiously
Sanctify your demons

Into abyss
You don't exist
Cannot resist
The Judas kiss

Judas lives recite this vow
I've become your new god now

Follow you from dawn of time
Whisper thoughts into your mind
Watched your towers hit the ground
Lured the children never found
Helped your kings abuse their crown

In the heart of evil man
Plant the seeds of my own plan
Strong and powerful will fall
Find a piece of me in all
Inside you all

So bow down
Sell your soul to me
I will set you free
Pacify your demons

Bow down
Surrender unto me
Submit infectiously
Sanctify your demons

Into abyss
You don't exist
Cannot resist
The Judas kiss
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
 
#define  INF 100000000
#define eps 1e-5
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

long n,k,cur[100000],move[25][100000];
long d,iter;

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;

for (int i=1;i<n;i++)cur[i]=1;

for (int iter=1;iter<=k;iter++)
{
    for (int i=1;i<=n;i++)
    {
     if (cur[i]*2<=(n-i))
     {
      move[iter][i]=i;cur[i]*=2;
     }        
     else
     {
         d=n-i-cur[i];
         move[iter][i]=n-d;
         cur[i]=n-i;
     }
    }
}

for (int i=1;i<=k;i++)
{
    for (int j=1;j<=n;j++){if (j>1)cout<<" ";
    cout<<move[i][j];}
    cout<<endl;
}
cin.get();cin.get();
return 0;}