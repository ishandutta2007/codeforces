/*
My sex-change operation got botched
My Guardian angel fell asleep on the watch
Now all I got is a Barbie doll crotch
I got an angry inch

Six inches forward and five inches back
I got a, I got an angry inch
Six inches forward and five inches back
I got a, I got an angry inch

I'm from the land where you still hear the cries
I had to get out to sever all ties
I changed my name and assumed a disguise
I got an angry inch

Six inches forward and five inches back
I got a, I got an angry inch
Six inches forward and five inches back
I got a, I got an angry inch

Six inches forward and five inches back
The train is coming and I'm tied to the track
I try to get up but I can't get no slack
I got an angry inch, angry inch, angry inch

My mother made my tits out of clay
My boyfriend told me that he'd take me away
They dragged me to the doctor one day
I've got an angry inch

Six inches forward and five inches back
I got a, I got an angry inch
Six inches forward and five inches back
I got a, I got an angry inch

Long story short
When I woke up from the operation, I was bleeding down there
I was bleeding from the gash between my legs
My first day as a woman and already it's that time of the month
But two days later, the hole closed up and the wound healed
And I was left with a one inch mound of flesh
Where my penis used to be, where my vagina never was
A one inch mound of flesh with a scar running down it
Like a sideways grimace on an eyeless face
It was just a little bulge, it was an angry inch

Six inches forward and five inches back
The train is coming and I'm tied to the track
I try to get up but I can't get no slack
I got an angry inch, angry inch, angry inch

Six inches forward and five inches back
Stay under cover till the night turns to black
I got my inch and I'm set to attack
I got an angry inch, angry inch, angry inch

Six inches forward and five inches back
The train is coming and I'm tied to the track
I try to get up but I can't get no slack
I got an angry inch, angry inch, angry inch

Six inches forward and five inches back
Stay under cover till the night turns to black
I got my inch and I'm set to attack
I got an angry inch, angry inch, angry inch
Angry inch, angry inch, angry inch
Angry inch, angry inch, angry inch
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
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define time asdfasdfasfd

using namespace std;

int n,k,ar[1<<20];
long long dp[5005][5005];
int C;
int cnt[5050];
int c1,c2;
int done;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=0;i<n;i++)
{
    cin>>ar[i];
    cnt[i%k]++;
}
sort(ar,ar+n);

C=1e9;

for (int i=0;i<k;i++)
{
    if (cnt[i]<C)
        C=cnt[i];
}
for (int i=0;i<k;i++)
    if (cnt[i]==C)
        c1++;
    else
        c2++;

for (int i=0;i<=c1;i++)
    for (int j=0;j<=c2;j++)
        dp[i][j]=1e18;

dp[0][0]=0;
for (int i=0;i<=c1;i++)
    for (int j=0;j<=c2;j++)
    {
        done=i*C+j*(C+1);
        if (i<c1&&C>0)
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+abs(ar[done+C-1]-ar[done]));
        if (j<c2)
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+abs(ar[done+C]-ar[done]));
    }

cout<<dp[c1][c2]<<endl;
    

//cin.get();cin.get();
return 0;}