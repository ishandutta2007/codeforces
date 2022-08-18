/*
I've been through all of this a million times before
Seems all my demons got me knocking on hell's door
I know it's too late to regret what I have done
But I still love you like the morning loves the sun

Too far gone to see the light
And I will never ever leave this place alive
Too far gone to see the light
No I will never ever leave this place alive

I guess it's fair to say that this round is on me
Caribbean blue has turned to blackest misery
I've put a velvet cloth on everything we've done
But I still love you like a bullet loves the gun
*/

#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
using namespace std;
long n,ansp,ansl,q,w;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
ansl=10000000;
for (int p=0;p<=n;p++)
{q=p*7;if (q>n)continue;
 w=n-q;
 if (w%4!=0)continue;
 if (p+w/4<ansl){ansl=p+w/4; ansp=p;};}
if (ansl>1000000)cout<<-1<<endl;
else 
{for (int i=n-7*ansp;i;i-=4)printf("%d",4);
 for (int i=1;i<=ansp;i++)printf("%d",7);
     
 cout<<endl;}
cin.get();cin.get();
return 0;
}