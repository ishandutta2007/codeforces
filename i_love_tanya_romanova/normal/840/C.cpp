/*
Well I'll be damned
Here comes your ghost again
But that's not unusual
It's just that the moon is full
And you happened to call

And here I sit
My hand on the telephone
Hearing a voice I'd known
A couple of light years ago
Heading straight for a fall

As I remember your eyes
Were bluer than robin's eggs
My poetry was lousy you said
Where are you calling from?
A booth in the midwest

Ten years ago
I bought you some cufflinks
Oh and you brought me something
We both know what memories can bring
They bring diamonds and rust

Well you burst on the scene
Already a legend
The unwashed phenomenon
The original vagabond
You strayed into my arms

And there you stayed
Temporarily lost at sea
The Madonna was yours for free
Yes the girl on the half-shell
Would keep you unharmed

Now I see you standing
With leaves falling around
And snow in your hair
Now you're smiling out the window
Of that hotel
Over Washington Square
Our breath comes out white clouds
Mingles and hangs in the air
Speaking strictly for me
We both could have died then and there

Now you're telling me
You're not nostalgic
Then give me another word for it
You are always so good with words
And at keeping things vague

Because I need some of that vagueness now
It's all coming back too clearly
Oh I loved you dearly
And if you're offering me diamonds and rust
I've already paid

Diamonds and rust
Diamonds and rust
Diamonds and rust
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007
const int N = 501031;

int n,ar[N];
int con[1031][1031];
vector<int> comps;
vector<int> rep[N];
int used[N];
int cnt_in_comp;

void dfs(int ps)
{
	cnt_in_comp++;
	used[ps]=1;
	for (int i=1;i<=n;i++)
	{
		if (con[i][ps]==1&&used[i]==0)
			dfs(i);
	}
}

vector<int> get_representation(int val){
	vector<int> ret;
	for (int i=2;i*i<=val;i++)
	{
		if (val%i)
			continue;
		int cnt=0;
		while (val%i==0)
		{
			cnt++;
			val/=i;
		}
		if (cnt%2)
			ret.push_back(i);
	}
	if (val>1)
		ret.push_back(val);
	sort(ret.begin(),ret.end());
	return ret;
}

long long fact[N];
long long dp[1031][1031];

long long pref_sum[N];

long long C[1031][1031];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	for (int i=0;i<1031;i++)
	{
		for (int j=0;j<=i;j++)
		{
			if (j==0||j==i)
				C[i][j]=1;
			else
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%bs;
		}
	}

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
		rep[i]=get_representation(ar[i]);
	}

	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (rep[i]==rep[j])
			{
				con[i][j]=1;
			}
			else
			{
				con[i][j]=0;
			}
		}
	}

	for (int i=1;i<=n;i++)
	{
		if (used[i])
			continue;
		cnt_in_comp=0;
		dfs(i);
		comps.push_back(cnt_in_comp);
	}

	/*for (int i=0;i<comps.size();i++)
	{
		cout<<comps[i]<<" ";
	}
	cout<<endl;
*/
	fact[0]=1;
	for (int i=1;i<N;i++)
	{
		fact[i]=fact[i-1]*i%bs;
	}

	dp[1][comps[0]-1]=fact[comps[0]];

	pref_sum[0]=0;
	for (int i=0;i<comps.size();i++)
	{
		pref_sum[i+1]=pref_sum[i]+comps[i];
		//cout<<"@"<<comps[i]<<endl;
	}

	for (int processed=1;processed<comps.size();processed++)
	{
		for (int current_bad_positions=0;current_bad_positions<pref_sum[processed];current_bad_positions++)
		{
			if (dp[processed][current_bad_positions]==0)
				continue;
//			cout<<"OUTER: "<<processed<<" "<<current_bad_positions<<" "<<dp[processed][current_bad_positions]<<" "<<
//					comps[processed]<<endl;

			for (int groups_here=1;groups_here<=comps[processed];groups_here++)
			{
				for (int bad_positions_split=0;bad_positions_split<=current_bad_positions&&
				bad_positions_split<=groups_here;bad_positions_split++)
				{
					int new_bad_positions=current_bad_positions-bad_positions_split; // remove old
					new_bad_positions+=comps[processed]-groups_here; // add new
					long long ways=dp[processed][current_bad_positions];
					//cout<<"@"<<ways<<endl;
					ways=(ways*fact[comps[processed]])%bs; // reorder arbitrary
					//cout<<ways<<endl;
					ways=(ways*C[current_bad_positions][bad_positions_split])%bs; // pick bad to split
					//cout<<ways<<endl;
					ways=(ways*C[pref_sum[processed]+1-current_bad_positions][groups_here-bad_positions_split])%bs; // pick good to place remaining
					//cout<<ways<<endl;
					ways=(ways*C[comps[processed]-1][groups_here-1])%bs; // split into groups
					//cout<<ways<<endl;
					dp[processed+1][new_bad_positions]=(dp[processed+1][new_bad_positions]+ways)%bs;
					//cout<<new_bad_positions<<" "<<groups_here<<" "<<ways<<" "<<endl;
				}
			}
		}
	}

	cout<<dp[comps.size()][0]<<endl;

	cin.get(); cin.get();
	return 0;
}