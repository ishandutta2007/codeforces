/*
Woo.
I'm ahead, I'm a man
I'm the first mammal to wear pants, yeah
I'm at peace with my lust
I can kill 'cause in God I trust, yeah
It's evolution, baby

I'm at peace, I'm the man
Buying stocks on the day of the crash
On the loose, I'm a truck
All the rolling hills, I'll flatten 'em out, yeah
It's herd behavior, uh huh
It's evolution, baby

Admire me, admire my home
Admire my son, he's my clone
Yeah, yeah, yeah, yeah
This land is mine, this land is free
I'll do what I want but irresponsibly
It's evolution, baby

I'm a thief, I'm a liar
There's my church, I sing in the choir:
Hallelujah, hallelujah

Admire me, admire my home
Admire my son, admire my clones
'Cause we know, appetite for a nightly feast
Those ignorant Indians got nothin' on me
Nothin', why?
Because... it's evolution, baby!

I am ahead, I am advanced
I am the first mammal to make plans, yeah
I crawled the earth, but now I'm higher
2010, watch it go to fire
It's evolution, baby
Do the evolution
Come on, come on, come on
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

const int N = 5031;

int n;
int S[N][N],dp[N][N];
string st[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>st[i];
	}

	dp[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=n;j>=0;--j){
			S[i-1][j]=S[i-1][j+1]+dp[i-1][j];
			S[i-1][j]%=bs;
		}
		for (int j=0;j<=n;j++){
			if (j>0&&st[i]=="f"){
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				if (st[i]=="f")
					continue;
				dp[i][j]=S[i-1][j];
			}
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}

	cout<<dp[n][0]<<endl;

	cin.get(); cin.get();
	return 0;
}