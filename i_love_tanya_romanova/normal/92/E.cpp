/*
Life in the world untold, question the unknown
This prison captures me, my cell is all I know
I thought I knew it all, stubborn in my ways
My sentence has begun, my future's what I waste

Next chapter of my life is filled with violent scenes
I stay awake at night hiding from my dreams
The voices haunting me, driving me insane
Can't seem to get away, they're calling out my name
I feel that I am slipping
Are they out to get me
My life is upside down
More than meets the eye

For now I am in control, choosing my own fate
And now I sleep at night because I'm not afraid
My demons haunting me, I chased them all away
I've conquered all my fears, my destiny awaits
I'm no longer slipping
I'm not slipping away
No one's out to get me
No one will get in my way
No longer upside down
I've turned my life around
More than meets the eye

More than
More than meets the eye
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long n,m,ans,w[300000],d[300000],a,b;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    w[i]=i;
    d[i]=1;
}

ans=1;
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    while (a!=w[a])a=w[a];
    while (b!=w[b])b=w[b];
    if (a!=b)
    {if (d[a]>d[b]){w[b]=a;}
    else {w[a]=b;if (d[a]==d[b])d[b]++;}}
    else ans=ans*2%bs;
    cout<<(ans+bs-1)%bs<<endl;
}

cin.get();cin.get();
return 0;}