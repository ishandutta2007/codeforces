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

/*vector<int> order;
int ans;
vector<int> ans_order;

int dp[N];

int get_inc(vector<int> v){
	for (int i=0;i<v.size();i++){
		dp[i]=1;
		for (int j=i-1;j>=0;--j){
			if (v[i]>v[j])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	int res=0;
	for (int i=0;i<v.size();i++){
		res=max(res,dp[i]);
	}
	return res;
}

int get_dec(vector<int> v){
	for (int i=0;i<v.size();i++){
		dp[i]=1;
		for (int j=i-1;j>=0;--j){
			if (v[i]<v[j])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	int res=0;
	for (int i=0;i<v.size();i++){
		res=max(res,dp[i]);
	}
	return res;
}
*/

int n;

vector<int> ans_v;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

/*	for (int n=1;n<=10;n++){
		order.clear();
		for (int i=1;i<=n;i++){
			order.push_back(i);
		}
		ans=1e9;
		do
		{
			int here=get_inc(order)+get_dec(order);
			if (here<ans){
				ans=here;
				ans_order=order;
			}
		}while (next_permutation(order.begin(),order.end()));
		cout<<ans<<endl;
		for (int i=0;i<ans_order.size();i++){
			cout<<ans_order[i]<<" ";
		}
		cout<<endl;
	}
*/

	cin>>n;
	int ans=1e9;
	int ans_max=1e9;

	for (int max_block=1;max_block<=n;max_block++){
		int blocks=n/max_block+(n%max_block>0);
		int here=blocks+max_block;
		if (here<ans){
			ans=here;
			ans_max=max_block;
		}
	}

	for (int i=1;i<=n;i+=ans_max){
		int start=min(i+ans_max-1,n);
		for (int j=start;j>=i;--j)
			ans_v.push_back(j);
	}

	for (int i=0;i<ans_v.size();i++){
		if (i)
			cout<<" ";
		cout<<ans_v[i];
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}