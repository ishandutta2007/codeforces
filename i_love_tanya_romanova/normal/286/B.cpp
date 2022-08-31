/*
If you're leaving, close the door
I'm not expecting people, anymore
Here me grieving, lying on the floor
Whether I'm drunk or dead, I really ain't too sure

I'm a blind man
I'm a blind man
And my world is pale
When a blind man cries
Lord, you know
There ain't a sadder tale

Had a friend once, in a room
Had a good time, but it ended much too soon
In a cold month, in that room
We found a reason, for the things we had to do

I'm a blind man
I'm a blind man
Now my room is cold
When a blind man cries
Lord, you know
He feels it from his soul
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
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long n,stp,ar[3000000];

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
stp=1;
for (int i=1;i<=n;i++)
ar[i]=i;

for (int i=2;i<=n;i++)
{
    long lp=n/i*i+stp;
    for (int j=lp;j>=stp;j-=i)
    {
        if (j==lp){ar[stp+n]=ar[j];}
        else ar[j+i]=ar[j];
    }
    ++stp;
}

for (int i=stp;i<stp+n;i++)
{
    if (i>stp)cout<<" ";
    cout<<ar[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}