/*
New blood joins this earth
And quickly he's subdued
Through constant pain disgrace
The young boy learns their rules
With time the child draws in
This whipping boy done wrong
Deprived of all his thoughts
The young man struggles on and on he's known
A vow unto his own
That never from this day
His will they'll take away

What I've felt
What I've known
Never shined through in what I've shown
Never be
Never see
Won't see what might have been
What I've felt
What I've known
Never shined through in what I've shown
Never free
Never me
So I dub thee unforgiven

They dedicate their lives
To running all of his
He tries to please them all
This bitter man he is
Throughout his life the same
He's battled constantly
This fight he cannot win
A tired man they see no longer cares
The old man then prepares
To die regretfully
That old man here is me

What I've felt
What I've known
Never shined through in what I've shown
Never be
Never see
Won't see what might have been
What I've felt
What I've known
Never shined through in what I've shown
Never free
Never me
So I dub thee unforgiven

What I've felt
What I've known
Never shined through in what I've shown
Never be
Never see
Won't see what might have been
What I've felt
What I've known
Never shined through in what I've shown
Never free
Never me
So I dub thee unforgiven

Never free
Never me
So I dub thee unforgiven

You labeled me
I labeled you
So I dub thee unforgiven

Never free
Never me
So I dub thee unforgiven

You labeled me
I labeled you
So I dub thee unforgiven

Never free
Never me
So I dub thee unforgiven
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,q,bad[1<<20];
vector<int> ans;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
 {
    cin>>q;
    if (q>0&&q%2==1)
     bad[i]=1;
 }

for (int i=1;i<=n;i++)
if (bad[i]==0)
 ans.push_back(i);

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}