/*
Standing in the shadow of our lies,
To hide our imperfection,
Doing anything we can to hide.
Eyes wide open but still blind
To see what really matters,
And insecurity won't go,
See me in shadow.

Standing by the ruins of your soul,
That cries for some more meaning.
Wondering when you have
Become so cold,

So cold,
And all the pictures of your past are gone.
So cold, so cold,
Forget yourself
And who you are,
Another life is not that far.

Standing by the paintings of your dreams,
But you have awoken
And all the purples and the greens
Have turned to black.
And the ruins of your soul
Have died, no more meaning.
Wonder when you have
Become so cold,

So cold,
And all the pictures of your past are gone.
So cold, so cold,
Forget yourself
And who you are,
Another life is not that far.

Not that far,
Not that far,
Not that far.
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

int n;
string st;
long long pw[200];
long long dp[60][30][30];
long long par[131][31][31];
vector<string> ans;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st;
for (int i=0;i<=n*2;i++)
	for (int j=0;j<=n;j++)
		for (int q=0;q<=n;q++)
			dp[i][j][q]=-5e18;

dp[0][0][0]=0;

pw[0]=1;
for (int i=0;i<18;i++)
	pw[i+1]=pw[i]*10;

for (int i=0;i<n*2;i++)
	for (int j=0;j<=n;j++)
		for (int q=0;q<=n;q++)
		{
			if(j<n)
			{
				long long res=dp[i][j][q]+(st[i]-48)*pw[n-j-1];
				if (res>dp[i+1][j+1][q])
				{
					dp[i+1][j+1][q]=res;
					par[i+1][j+1][q]=0;
				}
			}
			if (q<n)
			{
				long long res=dp[i][j][q]+(st[i]-48)*pw[n-q-1];
				if (res>dp[i+1][j][q+1])
				{
					dp[i+1][j][q+1]=res;
					par[i+1][j][q+1]=1;
				}
			}
		}

int curx=n;
int cury=n;
for (int iter=n*2;iter;--iter)
{
//	cout<<curx<<" "<<cury<<" "<<dp[iter][curx][cury]<<endl;
	
	if (par[iter][curx][cury]==0)
	{
		ans.push_back("H");
		--curx;
	}
	else
	{
		ans.push_back("M");
		--cury;
	}
}

reverse(ans.begin(),ans.end());
for (int i=0;i<ans.size();i++)
	cout<<ans[i];
cout<<endl;

//cout<<dp[n*2][n][n]<<endl;
		
//cin.get();cin.get();
return 0;}