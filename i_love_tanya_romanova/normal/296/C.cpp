/*
I was raised from a broken seed, I grew up to be an unwanted weed.
Ever faster the time exceeds me, little harder again to remember...you.

Held a torch for you, when lightning struck me, once again, hope I died for the last time.
Only one I have a thing greater than you, little light on the sky every night.

Morning dew on the field, where I met you.
I was frozen a year, couldn't get through.
Got a sign, not a scar, on my shoulder, I am not quite the man you take me for...

Fell in love with the weakness within me.
Tried to force me the Ring and own me.
Guess you found what you'd think would oblige me, little version of me to consume you...
I'd give my everything to you, follow you through the garden of oblivion.
If only I could tell you everything, the little things you'll never dare to ask me...

Do you really know me? I might be a God.
Show me that you care and have a cry.
How do you see me?... as the one?
Can you see my blood when I'm bleeding.
How can you love this exile, and how could I desire you.
When my pain is my pain and yours is too...

On this deadwinter's night. Darkness becomes this child.
Bless this night with a tear. For I have none I fear...

Seven lives of a man, passed before me.
Seven graves, one for every love I've had.
Only once I have broken my so called heart.
Only one made me see why they cry.

Will I learn how to be one of you someday?
Will I still feel the eyes that behold me.
Will I hear what you think, when you see me?
Will it tear me apart if you feel for me...

I 'd give my everything to you, follow you through the garden of oblivion.
If only I could tell you everything, the little things you'll never dare to ask me...

Do you really know me? I might be a God.
Show me that you care and have a cry.
How do you see me?... as the one?
Can you see my blood when I'm bleeding.
How can you love this exile, and how could I desire you.
When my pain is my pain and your is too...

On this deadwinter's night. Darkness becomes this child.
Bless this night with a tear. For I have none I fear...

Little broken , always been, a part of you belongs to me.
You were never mine to love, but this all has made it easy for me...

Burning feathers, not an angel, Heaven's closed , Hell's sold out.
So I walk on the earth, behind the curtains, hidden from everyone,
until I find a new life to ruin again

On this deadwinter's night. Darkness becomes this child.
Bless this night with a tear. For I have none I fear...

On this deadwinter's night. Darkness becomes this child.
Bless this night with a tear. For I have none I fear...
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

long long temp,num[200000],
n,m,k,ar[200000],l[200000],r[200000],d[200000];
long long a,b,op[200000],op1[200000];

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
cin>>ar[i];

for (int i=1;i<=m;i++)
cin>>l[i]>>r[i]>>d[i];

for (int i=1;i<=k;i++)
{
    cin>>a>>b;
    op[a]++;
    op[b+1]--;
}

for (int i=1;i<=m;i++)
{
    temp+=op[i];
    num[i]=temp;
}

for (int i=1;i<=m;i++)
{
    op1[l[i]]+=d[i]*num[i];
    op1[r[i]+1]-=d[i]*num[i];
}

temp=0;

for (int i=1;i<=n;i++)
{
    temp+=op1[i];
    ar[i]+=temp;
}

for (int i=1;i<=n;i++)
{if (i>1)cout<<" ";
cout<<ar[i];}
cout<<endl;

cin.get();cin.get();
return 0;}