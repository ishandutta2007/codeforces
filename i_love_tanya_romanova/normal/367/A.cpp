/*
Where do I take this pain of mine?
I run but it stays right by my side

So tear me open and pour me out
There's things inside that scream and shout
And the pain still hates me
So hold me until it sleeps

Just like the curse, just like a stray
You feed it once and now it stays
Now it stays

So tear me open but beware
There's things inside without a care
And the dirt still stains me
So wash me until I'm clean

It grips you so hold me
It stains you so hold me
It hates you so hold me
It holds you so hold me
Until it sleeps

So tell me why you've chosen me
Don't want your grip
Don't want your greed
Don't want it

I'll tear me open, make you gone
No more can you hurt anyone
And the fear still shakes me
So hold me until it sleeps

It grips you so hold me
It stains you so hold me
It hates you so hold me
It holds you, holds you
Holds you until it sleeps

Until it sleeps
Until it sleeps
Until it sleeps
Until it sleeps

I don't want it
I don't want it, want it, want it
Want it, want it, no

So tear me open but beware
There's things inside without a care
And the dirt still stains me
So wash me 'til I'm clean

I'll tear thee open, make you gone
No longer will you hurt anyone
And the hate still shapes me
So hold me until it sleeps

Until it sleeps
Until it sleeps
Until it sleeps
Until it sleeps
Until it sleeps
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long s[200000][10],n,l,r,mn,mx,m;

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 s[i+1][0]=s[i][0];
 s[i+1][1]=s[i][1];
 s[i+1][2]=s[i][2];
 if (st[i]=='x')s[i+1][0]++;
 if (st[i]=='y')s[i+1][1]++;
 if (st[i]=='z')s[i+1][2]++;   
}

cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>l>>r;
 mx=-1e9;
 mn=1e9;
 for (int j=0;j<3;j++)
 {
     mx=max(mx,s[r][j]-s[l-1][j]);
     mn=min(mn,s[r][j]-s[l-1][j]);
 }
 if (abs(mx-mn)<2||r<=l+1)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
}

cin.get();cin.get();
return 0;}