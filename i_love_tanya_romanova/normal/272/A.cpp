/*
There's no time for us,
There's no place for us,
What is this thing that builds our dreams, yet slips away from us.

Who wants to live forever,
Who wants to live forever.....?
There's no chance for us,
It's all decided for us,
This world has only one sweet moment set aside for us.

Who wants to live forever,
Who dares to love forever,
When love must die.

But touch my tears with your lips,
Touch my world with your fingertips,
And we can have forever,
And we can love forever,
Forever is our today,
Who wants to live forever,
Who wants to live forever,
Forever is our today,
Who waits forever anyway?
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

long long n,s,q,ans;

int main(){
//freopen("bees.in","r",stdin);
//freopen("bees.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>q;s+=q;}

for (int i=1;i<=5;i++)
{
    if ((s+i)%(n+1)!=1)++ans;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}