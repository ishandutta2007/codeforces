/*
Help me write these words down
I'll write a great song to die to
'Cause my days are numbered
And it's certain that I'm gonna drag you

I don't plan on going alone
I need a friend like a typhoid, Mary
We'll walk with a goose step
With vigor and might that's scary

There I go
(Down)
And I'm lovin' it

Dig way deep in
Bid farewell to a world I can't live in
I scratched the surface
And found pride was paper thin

I tried evil
I wish it had more of and impact
'Cause faith ain't helping
To rid the apes on my back

After me come the flood
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int n,k;
long long ans;
int cnt[100];

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
	int v;
	cin>>v;
	int rem=v%10;
	ans+=v/10;
	if (rem>0)
	{
		int b=10-rem;
		cnt[b]++;
		v=v+b;
	}
	int oh=10-v/10;
	cnt[10]+=oh;
}
/*
for (int i=1;i<=10;i++)
	cout<<cnt[i]<<" ";
cout<<endl;
*/
for (int i=1;i<=10;i++)
{
	int cantake=min(cnt[i],k/i);
	ans+=cantake;
	k-=cantake*i;
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}