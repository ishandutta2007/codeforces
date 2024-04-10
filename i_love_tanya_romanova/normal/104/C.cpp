/*
Life as we know,
Is full of gloom
Oppress the masses
We'll lead to our doom
We want the right
To live or die
Can't take away
What we feel inside

Like empty shadows,
Afflict our brains
Envision dreams
Just to ease the pain
There's more to life
That to satisfy
I ask myself
For the reason why.

If it were my way
I'd deliver us from this hell
If it were my way.

If ever there comes a day
Renovations blown away
Realize what we've thrown away

Is there no end
To this endless war
The fear of man
In now what's in store.
We look at life as a memory
Long live the dreams
That they took from me.

If it were my way
I'd deliver us from this hell
If it were my way.
*/

#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define y1 aasdfasdfasdf
using namespace std;
long ar[200][200],n,m,q,w,f,arp[2000];
void dfs(long nn)
{arp[nn]=1;
for (int i=1;i<=n;i++){if (arp[i]==0&&ar[nn][i]==1)dfs(i);}
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=m;i++){cin>>q>>w;ar[q][w]=ar[w][q]=1;}
dfs(1);
for (int i=1;i<=n;i++)if (arp[i]==0)f=1;
if (f==0&&m==n)cout<<"FHTAGN!"<<endl; else cout<<"NO"<<endl;

cin.get();cin.get();cin.get();
return 0;
}