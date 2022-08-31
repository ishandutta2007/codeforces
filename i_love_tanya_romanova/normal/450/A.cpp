/*
Sell kids for food, weather changes moods
Spring is here again, reproductive glands

He's the one who likes all our pretty songs
And he likes to sing along and he likes to shoot his gun
But he knows not what it means
Knows not what it means and I say

He's the one who likes all our pretty songs
And he likes to sing along and he likes to shoot his gun
But he knows not what it means
Knows not what it means and I say, yeah

We can have some more, Nature is a whore
Bruises on the fruit, tender age in bloom

He's the one who likes all our pretty songs
And he likes to sing along and he likes to shoot his gun
But he knows not what it means
Knows not what it means and I say

He's the one who likes all our pretty songs
And he likes to sing along and he likes to shoot his gun
But he knows not what it means
Knows not what it means and I say yeah

He's the one who likes all our pretty songs
And he likes to sing along and he likes to shoot his gun
But he knows not what it means
Knows not what it means and I say

He's the one who like all our pretty songs
And he likes to sing along and he likes to shoot his gun
But he knows not what it means
Knows not what it means, knows not what it means
Knows not what it means and I say yeah
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long n,m,ar[200000],cur,lst;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}
cur=1;
lst=1;
long iters=0;
for (int iter=1;iter<=100000;iter++)
{
    while (ar[cur]<=0&&iters<=100000){cur++;if(cur>n)cur=1;++iters;}
    if (ar[cur]>0)lst=cur,ar[cur]-=m;
    ++cur;
    if (cur>n)cur=1;
}
cout<<lst<<endl;

cin.get();cin.get();
return 0;}