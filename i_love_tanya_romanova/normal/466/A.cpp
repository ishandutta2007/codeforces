/*
When...
When is tomorrow?
As the day seems night and the mask still in my hand
Words...
Where was your guidance
In the night, the wounds I bleed for the sins you need

Meet me through the hollow

Remember yesterday
As I'm painted in black
The wounds I bleed for the sins you need

Obsolete

Today I forgive you... But tomorrow no
The pain I'm living now
As I faint in the snow

The pain is haunting me as the wishes come
The name of the Nazarene... obsolete

Meet me through the hollow

Today I forgive you... But tomorrow no
The pain I'm living now
As I faint in the snow

Obsolete
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

long ans,rem,n,m,a,b;

int main(){
//freopen("optimize.in","r",stdin);
//freopen("optimize.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>a>>b;
ans=1e9;
for (int i=0;i<=1000;i++)
{
    rem=n-i*m;
    if (rem<0)rem=0;
    ans=min(ans,rem*a+i*b);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}