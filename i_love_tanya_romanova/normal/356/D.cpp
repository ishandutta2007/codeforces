/*
Catch the rainbow if you can
It will alwawys be ahead of you

Years passing swifter than you ever thought
Today will soon be behind you
And the future remains out of reach

Hunting the sun, setting at the horison
When shadows threat to swallow your weak soul
The key of light, the solution of all
I saw it clearly behind the veil of reality
And as I dreamed the lilies white
In the shade of a birch
They withered in the frost of awakening

Fiery the angels fell from the spires of my fortress of youth
Silent explosions in my universe of pain

Appease my hunger, defeat my solitude
And let me follow where daydreams go
When ambitions fall

Watch the sky, there is proof of your transcience
The stars that saw the birth ofour ancestors
Shall watch our descendants last steps on earth
So, unnoticed we will pass away,
Like a flickering in the perpetual chaos

The timebird rose from it's nest of bones
And thrust it's beak in my eye
With the beat of charging wings
My transcience was confirmed

Time perhaps for a salutary sleep
I still long for that silent land of dreams
Where the flames expire, where the spark fades
And hunger is born again
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,s,ar[200000],mx,mp,freach[200000];
long dp[3][20000],sh1,sh2,ovb,temp;
vector<pair<long, long> > ans;
long anss[200000];
vector<long> answ[200000];
long nu[200000];

int main(){
//freopen("teams.in","r",stdin);
//freopen("teams.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>s;
for (int i=1;i<=n;i++)
{cin>>ar[i];if (ar[i]>mx){mx=ar[i];mp=i;}}


for (int i=0;i<=70000;i++)
freach[i]=10000000;
freach[0]=0;

if (s<mx){cout<<-1<<endl;return 0;}

dp[0][0]=1;

for (int i=1;i<=n;i++)
{
    for (int j=0;j<=5000;j++)
     dp[i%2][j]=0;
    for (int j=0;j<=5000;j++)
     dp[i%2][j]|=dp[1-i%2][j];
    if (i==mp)continue;
    
    sh1=ar[i]/16;
    sh2=ar[i]%16;
    for (int j=0;j<=5000;j++)
    {
        ovb=j-sh1;
        if (ovb<0)continue;
        dp[i%2][j]|=(dp[1-i%2][ovb]<<sh2);
        --ovb;
        if (ovb<0)continue;
        dp[i%2][j]|=(dp[1-i%2][ovb]>>(16-sh2));
    }
    
    for (int j=0;j<=5000;j++)
    dp[i%2][j]&=((1<<16)-1);
    
    for (int j=0;j<=5000;j++)
    {
        temp=dp[i%2][j];
        temp^=dp[1-i%2][j];
        if (temp==0)continue;
        for (int ob=0;ob<16;ob++)
        if (temp&(1<<ob))freach[j*16+ob]=i;
    }
    
/*    for (int q=0;q<=16;q++)
    cout<<((dp[i%2][0]&(1<<q))>0)<<" ";
    cout<<endl;
    */
}

//cout<<freach[s-mx]<<endl;
if (freach[s-mx]>n+5){cout<<-1<<endl;return 0;}

s-=mx;
nu[mp]=1;//ans.push_back(make_pair(mx,mp));
while (s>0)
{
// ans.push_back(make_pair(ar[freach[s]],freach[s]));
 nu[freach[s]]=1;
 s-=ar[freach[s]];     
}

for (int i=1;i<=n;i++)
if (nu[i]==0)ans.push_back(make_pair(ar[i],i));

sort(ans.begin(),ans.end());
reverse(ans.begin(),ans.end());

for (int i=1;i<=n;i++)
anss[i]=ar[i];

if (ans.size())anss[mp]-=ans[0].first;

for (int i=0;i+1<ans.size();i++)
anss[ans[i].second]=ans[i].first-ans[i+1].first;

//for (int i=0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<"    ";
//cout<<endl;

if(ans.size())answ[mp].push_back(ans[0].second);

for (int i=0;i+1<ans.size();i++)
answ[ans[i].second].push_back(ans[i+1].second);

for (int i=1;i<=n;i++)
{
    cout<<anss[i]<<" ";
    cout<<answ[i].size();
    for (int j=0;j<answ[i].size();j++)
    cout<<" "<<answ[i][j];
    cout<<endl;
}

cin.get();cin.get();
return 0;}