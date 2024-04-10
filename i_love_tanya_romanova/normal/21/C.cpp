/*
She lays in bed at night and that is when I make my call.
But when she stares at me, she can't see nothing at all,
Because, you see, I can't take no shape or form.
It's been three long years since I've been gone.

I can't get used to purgatory, you know it really makes me cry.
I'll never know the reason why I had to go.
Oh, oh, I'm crying,
Oh, oh, oh, deep inside of me.
Oh, oh, oh, can't you see me?
Ah can't you see me?

I'm looking forward to her spirit coming over to me.
I feel tempted to bring her over to see just what it's
Like to be hanging on the other side.
I feel so lonely, it's a long time since I died.

I try to show her that she's never gonna be alone,
Because my spirit is imprisoned in the twilight zone.
Oh, oh, I'm crying,
Oh, oh, oh, deep inside of me.
Oh, oh, oh, can't you hear me?
Ah can't you see me?
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

long long n,ar[200000],s,qs,ans,gs1,gs2;
map<long long, long long> calc;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    s+=ar[i];
}
if (s%3)cout<<0<<endl;
else
{
 gs1=s/3;gs2=gs1*2;
 qs=0;
 for (int i=1;i<n;i++)
 {
     qs+=ar[i];
     if (qs==gs2)ans+=calc[gs1];
     calc[qs]++;
 }
 cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}