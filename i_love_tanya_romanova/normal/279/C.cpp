/*  
Fortune, fame
Mirror vain
Gone insane
But the memory remains

Heavy rings on fingers wave
Another star denies the grave
See the nowhere crowd, cry the nowhere tears of honor

Like twisted vines that grow
That hide and swallow mansions whole
And dim the light of an already faded prima donna

Fortune, fame
Mirror vain
Gone insane...
Fortune, fame
Mirror vain
Gone insane...
But the memory remains

Heavy rings hold cigarettes
Up to lips that time forgets
While the Hollywood sun sets behind your back

And can't the band play on?
Just listen, they play my song
Ash to ash
Dust to dust
Fade to black

Fortune, fame
Mirror vain
Gone insane...
Fortune, fame
Mirror vain
Gone insane...
Dance little tin goddess

Drift away
Fade away
Little tin goddess

Ash to ash
Dust to dust
Fade to black

Fortune, fame
Mirror vain
Gone insane...
Fortune, fame
Mirror vain
Gone insane...
But the memory remains

Ash to ash
Dust to dust
Fade to black...
But the memory remains

Yeah
Faded prima donna yeah, yeah

Dance little tin goddess dance
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

long n,m,ar[200000],l,r,up[200000],down[200000];

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 if (i==1){up[i]=down[i]=1;continue;}
 if (ar[i]>=ar[i-1]){up[i]=up[i-1];}else up[i]=i;
 if (ar[i]<=ar[i-1]){down[i]=down[i-1];}else down[i]=i;   
}

for (int i=1;i<=m;i++)
{
    cin>>l>>r;
    r=down[r];
    r=up[r];
    if (r<=l)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

cin.get();cin.get();
return 0;}