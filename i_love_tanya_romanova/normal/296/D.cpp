/*
I write the lines you want me to, with the words.
I dare to use of all the ones that you have taught me, along the years.

You cast a perfect shadow on the paper.
Fade away with sunlight, I fear the way you know me, love can leave a stain...

You steal my only hope and make me stay awake another night.
I wish you bear with me, stay near me.
When the autumn leaves have fallen. Solitude, my pain, the last thing left of me...

If you fall I'll catch, if you love I'll love, and so it goes, my dear, don't be scared,
you'll be safe, this I swear.
If you only love me back.

Seven lonely lies written on Deadwinter's night,
open the only book with the only poem I can read...
In blood I sign my name and seal the midnight with a tear.
Burn the paper, every line for them I cried...

If you fall I'll catch, if you love I'll love, and so it goes, my dear, don't be scared,
you'll be safe, this I swear.
If you only love me back.

I am the Playwrite and you are my Crown, make me cry for your love,
like you've done many times, so I know.
I can't write these storylines without you, lady pain, make me strong,
can't we be together without them forever...

The words I write can only hurt you, sorry for the rain.
Thank you, my only one, you gave me this pain...I leave you gently on the floor,
take one step towards the door.
Where's the letter never written, good night now...

If you fall I'll catch, if you love I'll love, and so it goes, my dear, don't be scared,
you'll be safe, this I swear.
If you only love me back.

If you fall I'll catch, if you love I'll love, and so it goes, my dear, don't be scared,
you'll be safe, this I swear.
If you only love me back.
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

long long n,ar[600][600],bd[600],ans[600],usd[600];
int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
cin>>ar[i][j];

for (int i=1;i<=n;i++)
cin>>bd[n-i+1];

for (int k=1;k<=n;k++)
{


for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
{
 if (ar[i][bd[k]]+ar[bd[k]][j]<ar[i][j])ar[i][j]=ar[i][bd[k]]+ar[bd[k]][j];
}

usd[bd[k]]=1;
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
if (usd[i]==1&&usd[j]==1)ans[k]+=ar[i][j];
}

for( int i=1;i<=n;i++)
{if (i>1)cout<<" ";cout<<ans[n-i+1];//<<" ";
}
cout<<endl;

cin.get();cin.get();
return 0;}