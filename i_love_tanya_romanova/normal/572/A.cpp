/*
A silver plated numbing gum
And Jesus resting on my thumb
A hard to reach malaria
Ive got the mood that seems to scare ya.
Im paranoid, self destroyed.
Believe me lord Im sorry
Ive got the mood that seems to bury ya
Ive got the nightmare called
Schizophrenia

[Chorus:]
I cry. I cry and I dont know why.
The fever becomes my home.
I cry. I cry and I dont know why.
The fever becomes my home.
Becomes my home.

I love it when youre holding me.
You have a gentle way of calming.
I havent felt that way since 1993,
When my mother held me.
I bet youre waiting for a long sob story
Of how I was mistreated again.
No, I wasnt built that way.
I was strong but desperately brave,
And I didnt mean to scare ya
Schizophrenia.

[Chorus]
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

int n,m,A,B,ar1[1<<20],ar2[1<<20];

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
cin>>A>>B;
for (int i=0;i<n;i++)
    cin>>ar1[i];
sort(ar1,ar1+n);
for (int i=0;i<m;i++)
    cin>>ar2[i];
sort(ar2,ar2+m);
if (ar1[A-1]<ar2[m-B])
    cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;
//cin.get();cin.get();
return 0;}