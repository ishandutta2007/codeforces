/*
Here I'm lying with the dying

This is a song about a crime, we must tell it again and again
The people cry; revolution, but no one dares
From a whisper in the leaves to the breeze off the ocean
Domino effect when the avalanches start to roll

Look inside the magic ball and show me what is wrong
You're a mystery woman; magic man; you're mesmerized

[Chorus:]
Who'll be there when a titan cries?
With tooth and nail they fight
And they're defending the rights; the light
Some blood must be spilled
In the games when a titan cried
You will see the dictator die
Who'll be king of the Reich of blood?
Tears from a titan

To the master we begged for our lives; one more night
No remorse, executions or fire-might
Mess around get him down; biding time in the wolf's lair
What's another mile? Freedom's closer now

No more concentration camps; burn them to the ground
Cast a spell on the devils hands, the evil eye

[Chorus]

Tyranny goes on, father and the son
Prophecies are wrong, no one's here to deliver
Bloody serenade, dying is the aid
Tears from a titan
On and on and on, father and the son
Prophecies are wrong, no one's here to deliver
Bloody serenade, dying is the aid
Tears from a titan
Titan cries; who'll be there when a titan cries?
I will
Titan cries; from the eyes of evil

[Chorus]

Who'll be here when a titan cries?
*/
 
#pragma comment(linker, "/STACK:66777216")
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int tests,pr[1<<24];
int divs[1<<24];
int a,b;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;

pr[1]=1;
for (int i=2;i<=5000000;i++)
{
    if (pr[i]==0)
    {
        divs[i]++;
        for (int j=i*2;j<=5000000;j+=i)
        {
            int q=j;
            while (q%i==0)
            {
                divs[j]++;q/=i;
            }
            pr[j]=1;
        }
    }
}

for (int i=2;i<=5000000;i++)
 divs[i]+=divs[i-1];
/*
for (int i=1;i<=10;i++)
 cout<<i<<"  "<<divs[i]<<endl;
 */
for (;tests;--tests)
{
    scanf("%d",&a);
    scanf("%d",&b);
    printf("%d\n",divs[a]-divs[b]);
}
//cin.get();cin.get();
return 0;}