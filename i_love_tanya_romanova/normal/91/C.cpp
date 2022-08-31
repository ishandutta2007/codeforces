/*
Here we go
The people show
Victims of tomorrow
The way it goes
It never shows
Emptiness or sorrow
There is nothing left inside
Nothing left to cry for
So I justify my crimes
Things I must die for
So alone
Away it goes
The life that you have wasted
You never know
Where is might go
The sweet success you've tasted
Tasted by a bitter frown
Knowing I must die for
Can't confide, to all the lies
No one to inquire
As I wander, change of seasons
As I realize
That I'll soon be there
I'll let you know
The reapers show
Makes you beg or borrow
He comes to see
The tragedy
His fate he will not follow
Wearing your electric crown
The preacher starts to pray
Shiver as the lights go down
Heed these words I say
As I wander
Change of seasons
I can't ponder
I got my reasons
As I realize
I don't care
All I know is
That I'll soon be there
Now it's gone
The time has come
The people stand in silence
Another dawn
Has come and gone
His fate has been decided
There is no one left inside
A brain without a mind
Traces of a bitter man
Are all you will find
As I wander
Change of seasons
I can't ponder
I got my reasons
As I realize
I don't care
All I know is
That I'll soon be there
That I'll soon be there
That I'll soon be there
That I'll soon be there
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