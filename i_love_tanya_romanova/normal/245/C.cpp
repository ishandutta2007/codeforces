/*
New blood joins this earth,
And quickly he's subdued.
Through constant pained disgrace
The young boy learns their rules.

With time the child draws in.
This whipping boy done wrong.
Deprived of all his thoughts
The young man struggles on and on.

He's known a vow unto his own,
That never from this day
His will they'll take away.

What I've felt,
What I've known
Never shined through in what I've shown.
Never be.
Never see.
Won't see what might have been.

What I've felt,
What I've known
Never shined through in what I've shown.
Never free.
Never me.
So I dub thee unforgiven.

They dedicate their lives
To running all of his.
He tries to please them all 
This bitter man he is.

Throughout his life the same 
He's battled constantly.
This fight he cannot win 
A tired man they see no longer cares.

The old man then prepares
To die regretfully 
That old man here is me.

What I've felt,
What I've known
Never shined through in what I've shown.
Never be.
Never see.
Won't see what might have been.

What I've felt,
What I've known
Never shined through in what I've shown.
Never free.
Never me.
So I dub thee unforgiven.

What I've felt,
What I've known
Never shined through in what I've shown.
Never be.
Never see.
Won't see what might have been.

What I've felt,
What I've known
Never shined through in what I've shown.
Never free.
Never me.
So I dub thee unforgiven.

Never free.
Never me.
So I dub thee unforgiven.

You labelled me,
I'll label you.
So I dub thee unforgiven.

Never free.
Never me.
So I dub thee unforgiven.

You labelled me,
I'll label you.
So I dub thee unforgiven.

Never free.
Never me.
So I dub thee unforgiven.
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,ar[2000],ffpos,ans;

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
if (n<3||n%2==0)cout<<-1<<endl;
else
{
    for (int i=1;i<=n;i++)cin>>ar[i];
   
          for (int i=n/2;i;--i)
          {
              if (i*2>=n)continue;
              ffpos=0;
              ffpos=max(ffpos,ar[i*2]);
              ffpos=max(ffpos,ar[i*2+1]);
              if (i==1)ffpos=max(ffpos,ar[i]);
              ans+=ffpos;
              ar[i*2]-=ffpos;
              ar[i]-=ffpos;
              ar[i*2+1]-=ffpos;
          }  
     
    cout<<ans<<endl;
    
}
cin.get();cin.get();
return 0;}