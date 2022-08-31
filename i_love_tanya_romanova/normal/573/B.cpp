/*
Forging future from the timeless stone
Oh let me know how far I can go
Answering the questions that no one ever asks
Float through the sea of madness and face the everlasting task

So lonely to wander, so sad to be alone
In the mist of the unknown
Trying to fool myself with dreams that never come true
So hard to stand my ground, never again
Never again will I fail, will I fail

Will you tell me not to wait, tell me to live for today
As the flowers wither, I will forget my pain
Since the stars have shone
The devil has shown me the way

Will you tell me not to wait, tell me to live for today
As the flowers wither, I will forget my pain
Since the stars have shone
The devil has shown me the way, the way
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
#define bs 1000000000
#define bsize 512
#define MAG 40

using namespace std;

int n,ar[1<<20],bnd[1<<20];
int ans;

int main(){
//freopen("center.in","r",stdin);
//freopen("center.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
}

for (int i=1;i<=n;i++)
{
    bnd[i]=min(bnd[i-1]+1,ar[i]);
}
/*
for (int i=1;i<=n;i++)
    cout<<bnd[i]<<" ";
cout<<endl;*/

for (int i=n;i;--i)
{
    bnd[i]=min(bnd[i+1]+1,bnd[i]);
}
/*
for (int i=1;i<=n;i++)
    cout<<bnd[i]<<" ";
cout<<endl;
*/
for (int i=1;i<=n;i++)
    ans=max(ans,bnd[i]);

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}