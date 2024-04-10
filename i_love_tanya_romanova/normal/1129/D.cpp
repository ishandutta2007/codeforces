/*
Sitting in the dark, I can't forget.
Even now, I realize the time I'll never get.
Another story of the bitter pills of fate.
I can't go back again. I can't go back again...

But you asked me to love you and I did.
Traded my emotions for a contract to commit

And when I got away, I only got so far.
The other me is dead.
I hear his voice inside my head...

We were never alive, and we won't be born again.
But I'll never survive with dead memories in my heart.
Dead memories in my heart
Dead memories in my heart

You told me to love you and I did. Tied my soul into a knot and got me to submit.

So when I got away, I only kept my scars.
The other me is gone.
Now I don't know where I belong...

And we were never alive, and we won't be born again.
But I'll never survive with dead memories in my heart.
Dead memories in my heart
Dead memories in my heart
Dead memories in my heart

Dead visions in your name.
Dead fingers in my veins.
Dead memories in my heart
Dead memories in my heart
Dead memories in my heart
Dead memories in my heart
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
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 256

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 210031;

int n,k;
int ar[N];
int prv[N];
int last_entry[N];
int dp[N];

int on_block[N];
int on_element[N];

vector<pair<int,int> > sorted_blocks[N];
vector<int> prefix_sum_block[N];

void rebuild(int block_id){

	if (on_block[block_id]){
		for (int i=block_id*bsize;i<block_id*bsize+bsize;i++){
			on_element[i]+=on_block[block_id];
		}
		on_block[block_id]=0;
	}

	for (int i=block_id*bsize;i<block_id*bsize+bsize;i++){
		sorted_blocks[block_id][i-block_id*bsize]=make_pair(on_element[i],i);
	}

	sort(sorted_blocks[block_id].begin(),sorted_blocks[block_id].end());
	int cur=0;
	prefix_sum_block[block_id][0]=0;

	for (int i=0;i<sorted_blocks[block_id].size();i++){
		int id=sorted_blocks[block_id][i].second;
		cur+=dp[id];
		if (cur>=bs)
			cur-=bs;
		prefix_sum_block[block_id][i+1]=cur;
	}
}

void add(int r,int val){
	--r;
	if (r<0)
		return;
	int full_blocks=r/bsize;
	for (int i=0;i<full_blocks;i++){
		on_block[i]+=val;
	}
	for (int i=r/bsize*bsize;i<=r;i++){
		on_element[i]+=val;
	}
	rebuild(r/bsize);
}

int query(int ps){
	int ret=0;
	for (int i=0;i<=ps/bsize;i++){
		int individual_thold=k-on_block[i];
		int first_above;
		if (sorted_blocks[i][0].first>individual_thold)
			first_above=0;
		else if (sorted_blocks[i].back().first<=individual_thold)
			first_above=sorted_blocks[i].size();
		else
			first_above=lower_bound(
				sorted_blocks[i].begin(),sorted_blocks[i].end(),make_pair(individual_thold+1,-1))
						-sorted_blocks[i].begin();

		int in_this_block=prefix_sum_block[i][first_above];
		ret+=in_this_block;
		if (ret>=bs)
			ret-=bs;
	}
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);


    cin>>n>>k;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	prv[i]=last_entry[ar[i]];
    	last_entry[ar[i]]=i;
    }

    for (int i=0;i<=n/bsize;i++){
    	sorted_blocks[i].resize(bsize);
    	prefix_sum_block[i].resize(bsize+1);
    }

    dp[0]=1;

    for (int i=0;i<=n/bsize;i++){
    	rebuild(i);
    }

    for (int i=1;i<=n;i++){

		add(i,1);
		add(prv[i],-2); // was 1, should be 0, is at 2 due to lines above
		add(prv[prv[i]],1); // was 0, should be 0, is at -1 due to lines above

    	int here=query(i);

    	dp[i]=here;
    	rebuild(i/bsize);
    }

    cout<<dp[n]<<endl;

//    cin.get(); cin.get();
    return 0;
}