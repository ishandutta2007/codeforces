/*
Thermal count is rising
In perpetual writhing
The primordial ooze
And the sanity they lose

Awakened in the morning
To more air pollution warnings
Still we sleepwalk off to work
While our nervous systems jerk

Pretending not to notice
How history had forebode us
With the green house in effect
Our environment was wrecked

Now I can only laugh
As I read our epitaph
We end our lives as moles
In the dark of dawn patrol
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

long n,s;

int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

/*
cin>>n;
for (int i=0;i<n;i++)
s+=i;
cout<<s%n<<endl;
*/
cin>>n;
if (n%2==0)cout<<-1<<endl;
else
{
    for (int i=0;i<n;i++)
    {
        if (i)cout<<" ";
        cout<<i;
    }
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        if (i)cout<<" ";
        cout<<i;
    }
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        if (i)cout<<" ";
        cout<<i*2%n;
    }
    cout<<endl;
    
}

cin.get();cin.get();
return 0;}