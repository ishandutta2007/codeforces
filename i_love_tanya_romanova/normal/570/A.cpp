/*
There was a friend of mine on murder
And the judge's gavel fell
Jury found him guilty
Gave him sixteen years in hell
He said "I ain't spending my life here
I ain't living alone
Ain't breaking no rocks on the chain gang
I'm breakin' out and headin' home

Gonna make a jailbreak
And I'm lookin' towards the sky
I'm gonna make a jailbreak
Oh, how I wish that I could fly

All in the name of liberty
All in the name of liberty
Got to be free

Jailbreak, let me out of here
Jailbreak, sixteen years
Jailbreak, had more than I can take
Jailbreak, yeah

He said he'd seen his lady being fooled with
By another man
She was down and he was up
He had a gun in his hand
Bullets started flying everywhere
And people started to scream
Big man lying on the ground
With a hole in his body
Where his life had been
But it was -

All in the name of liberty
All in the name of liberty
I got to be free

Jailbreak, jailbreak
I got to break out
Out of here

Heartbeats they were racin'
Freedom he was chasin'
Spotlights, sirens, rifles firing
But he made it out
With a bullet in his back
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
#define bsize 512

using namespace std;

int n,m,bp,ar[200][200],cnt[200];

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    bp=1;
    
    for (int j=1;j<=n;j++)
    {
        cin>>ar[i][j];
        if (ar[i][j]>ar[i][bp])
            bp=j;
    }
    cnt[bp]++;
}

bp=1;
for (int i=1;i<=n;i++)
    if (cnt[i]>cnt[bp])
        bp=i;
    cout<<bp<<endl;
    
//cin.get();cin.get();
return 0;}