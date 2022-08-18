/*
Inclination of direction, walk the turned and twisted rift
With the children of creation futuristic dreams we sift
Clutching violently we whisper with a liquefying cry
Any deadly final answers that are surely doomed to die
Won't you help me Mr. Jesus, won't you tell me if you can?
When you see this world we live in, do you still believe in Man?
If my songs become my freedom, and my freedom turns to gold
When I ask the final question, is the answer bought and sold?
Well, that's my story and I'm sticking to it
'Cause I've got no reason to lie, yeah
Forget your problems that don't even exist
And I'll show you a way to get high, oh yeah
Oh yeah!
So come along, you know you matter to me
Remember freedom is not hard to find, yeah
Time to stop all your messing around
Don't you think that I know my own mind, oh yeah
Oh yeah!
Why can't you believe, it's not here to perceive
Do you always have to be told, yeah
For you have been taught that if your mind has been bought
Life's entire answer was sold, oh yeah
Oh yeah!
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
#define bs 1000000009
#define bsize 128

const int N = 2500;

using namespace std;

int n,m;
int sz[N];
int ar[55][5505];
long long best_pref[N],best_suf[N],best_inside[N];
long long block_sum[N];
long long ans,cur_suf;

int main(){
//	freopen("path2.in","r",stdin);
//	freopen("path2.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>sz[i];
		for (int j=1;j<=sz[i];j++)
		{
			cin>>ar[i][j];
		}
		
		best_pref[i]=-1e18;
		
		long long s=0;
		for (int j=1;j<=sz[i];j++)
		{
			s+=ar[i][j];
			best_pref[i]=max(best_pref[i],s);
		}
		
		s=0;
		best_suf[i]=-1e18;
		
		for (int j=sz[i];j;--j)
		{
			s+=ar[i][j];
			best_suf[i]=max(best_suf[i],s);
		}
		
		long long smallest_pref=0;
		best_inside[i]=-1e18;
		s=0;
		
		for (int j=1;j<=sz[i];j++)
		{
			s+=ar[i][j];
			best_inside[i]=max(best_inside[i],s-smallest_pref);
			smallest_pref=min(smallest_pref,s);
		}
		
		block_sum[i]=s;
		
	}
	/*
	for (int i=1;i<=n;i++)
		cout<<block_sum[i]<<" "<<best_pref[i]<<" "<<best_inside[i]<<" "<<best_suf[i]<<endl;
	*/	
	ans=-1e18;
	cur_suf=0;
	
	for (int i=1;i<=m;i++)
	{
		int id;
		cin>>id;
		ans=max(ans,cur_suf+best_pref[id]);
		ans=max(ans,best_inside[id]);
		cur_suf=max(best_suf[id],block_sum[id]+cur_suf);
		
	//	cout<<ans<<"%"<<cur_suf<<" "<<best_pref[id]<<" "<<best_suf[id]<<" "<<best_inside[id]<<endl;
		
	}
	
	cout<<ans<<endl;
	
	return 0;
}