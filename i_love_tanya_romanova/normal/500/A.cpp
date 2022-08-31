/*
Do you think I'm faking
When I'm lying next to you?
Do you think that I am blind?
There's nothing left for me to lose
Must be something on your mind
Something lost for me to find
Do you know I'm faking now?

Do you know I'm faking
When I'm lying next to you?
Do you know that I am blind
To everything you ever do?
Must be something on your mind
Something lost for me to find
Do you know I'm faking?

'Cos then she told me she had a gun
It sounded like she'd used it
Once before on him
Then she told me she had a gun
It sounded like she'd used it
Once before, oh, man

I guess you know I'm faking
When I tell you I love you
I guess you know that I am blind
To everything you say and do
Must be something on my mind
There's nothing left for me to hide
Do you know I'm faking?

'Cos then she told me she had a gun
It sounded like she'd used it
Once before on him
Then she told me she had a gun
It sounded like she'd used it
Once before, oh, man

We have to succumb to
The feelings we can never face
I need you, I breathe you
I can't go through this all again

We have to succumb to
The feelings we can never face
I need you, I breathe you
I can't go through this

'Cos then she told me she had a gun
It sounded like she'd used it
Once before

'Cos then she told me she had a gun
It sounded like she'd used it
Once before on him
Then she told me she had a gun
It sounded like she'd used it
Once before, oh, man

Then she told me she had a gun
She says she wants to use it
On me now
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
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,t,a[1<<20];
long reach[1<<20];

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>t;
for (int i=1;i<n;i++)
{
 cin>>a[i];
}
reach[1]=1;
for (int i=1;i<n;i++)
{
 if (reach[i]==0)continue;
 reach[i+a[i]]=1;
}
if (reach[t])cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}