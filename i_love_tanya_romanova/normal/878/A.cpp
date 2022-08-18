/*
On the street where you live girls talk about their social lives
They're made of lipstick, plastic and paint, a touch of sable in their eyes
All your life, all your life all you've asked when's your daddy gonna talk to you
But you were living in another world tryin' to get your message through.

No one heard a single word you said.
They should have seen it in your eyes
What was going around your head.

Ooh, she's a little runaway.
Daddy's girl learned fast
All those things he couldn't say.
Ooh, she's a little runaway.

A different line every night guaranteed to blow your mind
I see you out on the streets, calling for a wild time
So you sit home alone 'cause there's nothing left that you can do
There's only pictures hung in the shadows left there to look at you

You know she likes the lights at night on the neon Broadway signs
She don't really mind, it's only love she hoped to find

Ooh, she's a little runaway.
Daddy's girl learned fast
All those things he couldn't say.
Ooh, she's a little runaway.

No one heard a single word you said
They should have seen it in your eyes
What was going around your head.

Ooh, she's a little runaway
Daddy's girl learned fast
All those things he couldn't say

Ooh, she's a little runaway
Daddy's girl learned fast
Now she works the night away

Ooh, she's a little runaway
Daddy's girl learned fast
All those things he couldn't say

Ooh, she's a little runaway
Daddy's girl learned fast
Now she works the night away
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

const int N = 700031;

int n,cur_value[N],flipped[N];

int get_bit(int x,int i){
	return (x>>i)&1;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;

	for (int i=0;i<10;i++){
		cur_value[i]=-1;
	}

	for (int i=1;i<=n;i++){
		string st;
		int val;
		cin>>st;
		cin>>val;
		for (int j=0;j<10;j++){
			if (st=="^"&&get_bit(val,j)==1)
			{
				flipped[j]^=1;
			}
			if (st=="|"&&get_bit(val,j)==1){
				flipped[j]=0;
				cur_value[j]=1;
			}
			if (st=="&"&&get_bit(val,j)==0){
				flipped[j]=0;
				cur_value[j]=0;
			}
		}
	}

	cout<<3<<endl;
	// set 0s
	int x=1023;
	for (int i=0;i<10;i++){
		if (cur_value[i]==0)
			x-=(1<<i);
	}
	cout<<"& "<<x<<endl;
	// set 1s
	x=0;
	for (int i=0;i<10;i++){
		if (cur_value[i]==1)
			x|=(1<<i);
	}
	cout<<"| "<<x<<endl;
	x=0;
	// xor
	for (int i=0;i<10;i++){
		if (flipped[i])
			x^=(1<<i);
	}
	cout<<"^ "<<x<<endl;

	cin.get(); cin.get();
	return 0;
}