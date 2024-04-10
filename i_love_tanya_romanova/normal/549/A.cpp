/*
Passing through the void
The darkest grand illusion
Chaos is riding on the wind

Destroyed in agony
They create a maddened lair
Summon all to heed their cry

Innocence fading away
- the dying eyes of prey

[Chorus:]
Desperate cries, hail of fire deciding
All our fate in the night
Tempt in sin, shadows then begin to
Gather the souls they hold within

Victims of desire
Pestilence of their invasion
Forms then take on evil waves

Paralyze, victimize
The shadows fall and enter fast
from the sky - (from the sky)
Summon all to heed their cry

Innocence fading away
- the dying eyes of the prey

[Chorus]

I've betrayed - slowly fade
I repent my inner plea
I've denied - sanctified
Cannot hide form this
monstrosity

I'm immersed in a curse
Of this jaded imagery
Realize that your cries
Only jeopardize this legacy

[Chorus x2]
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
#define bsize 256

using namespace std;

int n,m,ans;
string st;
int cnt[1000];
char board[1000][1000];

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>st;
    for (int j=1;j<=m;j++)
     board[i][j]=st[j-1];
}
ans=0;
for (int i=1;i<n;i++)
 for (int j=1;j<m;j++)
 {
    cnt['f']=cnt['a']=cnt['c']=cnt['e']=0;
    cnt[board[i][j]]++;
    cnt[board[i+1][j]]++;
    cnt[board[i][j+1]]++;
    cnt[board[i+1][j+1]]++;
    if (cnt['f']==1&&cnt['a']==1&&cnt['c']==1&&cnt['e']==1)++ans;
 }

cout<<ans<<endl;
//cin.get();cin.get();
return 0;}