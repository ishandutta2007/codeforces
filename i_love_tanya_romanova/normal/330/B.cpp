/*  
Daybreak
at the bottom of lake
it's a hundred degrees I can't breathe
And I won't get out
'til I figure it out
Though I'm weak like I can't believe
So you tell me 'trust me' l can trust you
Just let me show you
But I gotta work it out in a shadow of doubt
'cause I don't know if I know you

Doing fine but don't waste my time
Tell me what it is you want to say
You sin, you win, just let me in - hurry
I've been out in the rain all day
So you tell me 'trust me' I can trust you
as far as I can throw you
And I'm trying to get out of a shadow of doubt
'cause I don't know if I know you

Don't tell me you wanted me
Don't tell me you thought of me
I won't, I swear I won't
(Did)
I'll try, I swear I'll try
(Lie)

Mother Mary quite contrary
Kiss the boys and make them wary
Things are getting just a little bit scary
It's a wonder I can still breathe

Never been much of a doubting Thomas
but nothing breaks like a broken promise
You tell me 'bout your two more coming
but once is just enough for me

I had gotten used to being a soul destroyed
She comes in apparently to fill the void
All dogs need a leash and
at least I'll forget it
And she would never hurt me though
she's never said it
But I'm not gonna ask her today
I don't wanna scare her away
Your town, I'm all alone
and I just can't stare at the phone
I wanna talk about lifelong mistakes
and you can tell your stepfather I said so
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
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,m,a,b,d[100000],q;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    d[a]=d[b]=1;
}
q=1;
while (d[q])++q;

cout<<n-1<<endl;
for (int i=1;i<=n;i++)
if (i!=q)cout<<i<<" "<<q<<endl;

cin.get();cin.get();
return 0;}