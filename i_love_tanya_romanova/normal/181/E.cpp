/*
No more love to purchase
I've invested in myself
You know nothing about me
Keep opinions to yourself
No more complications
Everything's just swell
No more obligations
There's nothing more to tell

Oo, oo, oo
I just want to be alone
When I get weak or I'm tired and afraid
When I sleep all my dreams turn out the same
When I bleed I relieve you of your pain
I can't believe you won't let me do the same
Oh

Please give me a reason
So I can shut you out
Though your heart is bleeding
You left me with no doubt
Give me segregation
Give me back my health
Take your observations
And turn them on yourself

Oo, oo, oo
I just want to be alone
When I get weak or I'm tired and afraid
When I sleep all my dreams turn out the same
When I bleed I relieve you of your pain
I can't believe you won't let me go
Let me live my life alone
Let me live my life alone
Let me live my life alone

When I'm running scared that's when I need to know
That you'll let me go
When I get weak or I'm tired and afraid
When I sleep all my dreams turn out the same
When I bleed I relieve you of your pain
I can't believe you won't let me go
Let me live my life alone
Let me live my life alone
Let me live my life alone
*/

//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-12
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,m,x1,y1,x2,y2,dx,dy;
long solve(long a,long b)
{
     if (a>4||b>4)return 0;
     if (a>b)swap(a,b);
     if (a>2&&b==4)return 0;
     return 1;
     }
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>n>>m>>x1>>y1>>x2>>y2;
dx=abs(x1-x2);
dy=abs(y1-y2);
if (solve(dx,dy))
cout<<"First"<<endl;
else cout<<"Second"<<endl;

cin.get();cin.get();
return 0;}