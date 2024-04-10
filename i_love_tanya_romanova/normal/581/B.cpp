/*
Before all else, better get yourself armed, yeah
Watch as they gravitate to your irresistible charm
Yeah, irresistible, irresistible

Who is going to guard the guards themselves
If you always lay down in the name of help?
The paupers learn quick or fall to the side
It's all me, myself and I

Who is going to guard the guards themselves
When all you do is try to survive the pelts?
The paupers learn quick or fall to the side
I live me myself, me, myself and I

Don't look to heaven 'cause you think that
Your due reward, you think you do?
In my hand is a chisel
For the chip on my shoulder, I can't afford no

Spewing energy
You say the sky cries along with me
Passive, aggressive man
Trying to trade in human misery
Let go of better wisdom
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

int n,ar[1<<20],mh[1<<20],mx;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
	cin>>ar[i];
}

for (int i=n;i;--i)
{
	mh[i]=mx;
	mx=max(mx,ar[i]);
}

for (int i=1;i<=n;i++)
{
	int res=mh[i]-ar[i]+1;
	if (res<0)
		res=0;
	if (i>1)
		cout<<" ";
	cout<<res;
}
cout<<endl;

//cin.get();cin.get();
return 0;}