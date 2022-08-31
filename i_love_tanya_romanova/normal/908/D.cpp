/*
Kill for gain or shoot to maim
We don't need a reason
The Golden Goose is on the loose
And never out of season
Blackened pride still burns inside
The shell of bloody treason
Here's my gun for a barrel of fun
For the love of living death

The killer's breed or the demon's seed,
The glamour, the fortune, the pain,
Go to war again, blood is freedom's stain
Don't you pray for our soul anymore

2 minutes to midnight,
The hands that threaten doom.
2 minutes to midnight,
To kill the unborn in the womb.

The blind men shout,
"Let the creatures out
We'll show the unbelievers."
Napalm screams of human flames
For a prime time Belsen feast ... yeah!
As the reasons for the carnage cut their meat and lick the gravy
We oil the jaws of the war machine and feed it with our babies.

The killer's breed or the demon's seed,
The glamour, the fortune, the pain,
Go to war again, blood is freedom's stain
Don't you pray for our soul anymore

2 minutes to midnight,
The hands that threaten doom.
2 minutes to midnight,
To kill the unborn in the womb.

The body bags and little rags of children torn in two
And the jellied brains of those who remain to put the finger right on you
As the madmen play on words and make us all dance to their song
To the tune of starving millions to make a better kind of gun.

The killer's breed or the Demon's seed,
The glamour, the fortune, the pain,
Go to war again, blood is freedom's stain
Don't you pray for my soul anymore.

2 minutes to midnight,
The hands that threaten doom.
2 minutes to midnight,
To kill the unborn in the womb.

Midnight
Midnight
Midnight
It's all night

Midnight
Midnight
Midnight
It's all night
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

long long a,b,k,inva,invb,invab;

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inv(long long x){
	return pw(x,bs-2);
}

long long dp[2031][2031];

bool next_b_will_win(int total_a,int total_ab){
	total_ab+=total_a;
	return total_ab>=k;
}

long long get_exp_wait_to_b(){
	return (a+b)*invb%bs;
}

long long get_exp_wait_to_a(){
	return (a+b)*inva%bs;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>k>>a>>b;
	inva=inv(a);
	invb=inv(b);
	invab=inv(a+b);

	dp[1][0]=1;

	long long exp_wait=get_exp_wait_to_b();

	long long exp_first_a=get_exp_wait_to_a();

	long long ans=0;//exp_first_a; // moves to get first a

	//cout<<exp_wait<<endl;

	for (int i=1;i<=k;i++){
		for (int j=0;j<=k;j++){
			if (next_b_will_win(i,j)){ // take them all then
				long long exp_len=(exp_wait+i+bs-1)%bs+j;
				ans+=dp[i][j]*exp_len;
				ans%=bs;
				continue;
			}
			// definitely making next move
			// another a
			dp[i+1][j]+=dp[i][j]*(a*invab%bs);
			dp[i+1][j]%=bs;
			// another b
			dp[i][j+i]+=dp[i][j]*(b*invab%bs);
			dp[i][j+i]%=bs;
		}
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}