/*
Oh, oh, oh
Oh, oh, oh

Control the urge to spit up the vile worms, its soul
Monsters seduced by her attention
Try draining the infection
Whoa, go, go, oh, oh, oh

Locked in a world of bile-soaked skin, it's heaven
Monsters seduced by her attention
She's draining the infection

Carol Anne, the beast is calling
Carol Anne, Carol Anne, she can hear souls singing
Carol Anne, the beast it needs you
Here it comes, here it comes
Reaching out somewhere from inside your TV
Whoa, go, go

Control the urge to spit up smile worms, its soul
Monsters seduced by her attention
Try draining the infection
Whoa, oh

Carol Anne, the beast is calling
Carol Anne, Carol Anne, she can hear souls singing
Carol Anne, the beast it needs you
Here it comes, here it comes
Reaching out somewhere from inside your TV
Yeah

Carol Anne, the beast is calling
Carol Anne, Carol Anne, she can hear souls singing
Carol Anne, the beast it needs you
Here it comes, here it comes
Reaching out somewhere from inside your TV
Yeah, oh
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

const int N = 1000005;

using namespace std;

int k,reach[N],sg[N];
int n;
set<int> know;
map<int, int> memo;

int get(int x)
{
	if (know.find(x)!=know.end())
		return memo[x];
	int R[4];
	for (int i=0;i<4;i++)
		R[i]=0;
	
	if (x%2==1)
	{
		know.insert(x);
		memo[x]=0;
		return 0;
	}
	
	if (x%2==0)
	{
		int val=get(x/2);
		if (k%2==0)	
			val=0;
		R[val]=1;
		R[0]=1;
	}
	
	int val=0;
	while (R[val])
		++val;
	know.insert(x);
	memo[x]=val;
	return val;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	sg[0]=0;
	
	cin>>n>>k;
	
	for (int i=1;i<=200;i++)
	{
		for (int j=0;j<=i;j++)
			reach[j]=0;
		reach[sg[i-1]]=1;
		if (i%2==0)
		{
			int val;
			if (k%2)
				val=sg[i/2];
			else
				val=0;
			reach[val]=1;
		}
		while (reach[sg[i]])
			++sg[i];
	//	cout<<i<<" "<<sg[i]<<endl;
		know.insert(i);
		memo[i]=sg[i];
	}
	
	int res=0;
	
	for (int i=1;i<=n;i++)
	{
		int val;
		cin>>val;
		res^=get(val);
	}
	if (res==0)
		cout<<"Nicky"<<endl;
	else
		cout<<"Kevin"<<endl;
		
	return 0;
}