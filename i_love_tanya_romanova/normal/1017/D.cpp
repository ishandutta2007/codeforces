/*
I'll be damned, here comes your ghost again
But that's not unusual
It's just that the moon is full
And you decided to call

And here I sit, hand on the telephone
Hearing the voice I'd known
A couple of light years ago
Headed straight for a fall

But we both know what memories can bring
They bring Diamonds and Rust
Yes we both know what memories can bring
They bring Diamonds and Rust

Now I see you standing with brown leaves all around and snow in your hair
Now we're smiling out the window of the crummy hotel over Washington Square
Our breath comes in white clouds, mingles and hangs in the air
Speaking strictly for me we both could've died then and there

Now you're telling me you're not nostalgic
Then give me another word for it
You were so good with words
And at keeping things vague

Cause I need some of that vagueness now
It's all come back too clearly, yes, I love you dearly
And if you're offering me diamonds and rust, I've already paid

But we both know what memories can bring
They bring Diamonds and Rust
Yes we both know what memories can bring
They bring Diamonds and Rust

Diamonds, Diamonds and Rust
Diamonds, Diamonds and Rust
Diamonds, Diamonds and Rust
Diamonds, Diamonds and Rust
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,m,tests,cost[N];
int CNT[N];
int WAYS[1<<13][131];

int get_cost(int a,int b){
	int ret=0;
	for (int i=0;i<12;i++)
	{
		if (!((a^b)&(1<<i))){
			ret+=cost[i];
		}
	}
	if (ret>100)
		ret=101;
	return ret;
}
int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m>>tests;

	for (int i=0;i<n;i++){
		cin>>cost[i];
	}

	for (int i=1;i<=m;i++){
		string st;
		cin>>st;
		int here=0;
		for (int j=0;j<st.size();j++){
			if (st[j]=='1')
				here+=(1<<j);
		}
		CNT[here]++;
	}

	for (int mask=0;mask<(1<<12);mask++){
		for (int mask2=0;mask2<(1<<12);mask2++){
			int here=get_cost(mask,mask2);
			WAYS[mask][here]+=CNT[mask2];
		}
	}

	for (int i=0;i<(1<<12);i++){
		for (int j=1;j<=100;j++){
			WAYS[i][j]+=WAYS[i][j-1];
		}
	}

	for (;tests;--tests){
		string query;
		int thold;
		cin>>query;
		int id=0;
		for (int j=0;j<query.size();j++){
			if (query[j]=='1')
				id|=(1<<j);
		}
		cin>>thold;
		cout<<WAYS[id][thold]<<"\n";
	}


//	cin.get(); cin.get();
	return 0;
}