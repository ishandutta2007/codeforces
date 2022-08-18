/*
If you like to gamble, I tell you I'm your man,
You win some, lose some, all the same to me,
The pleasure is to play, makes no difference what you say,
I don't share your greed, the only card I need is
The Ace Of Spades

Playing for the high one, dancing with the devil,
Going with the flow, it's all the game to me,
Seven or Eleven, snake eyes watching you,
Double up or quit, double stake or split,
The Ace Of Spades

You know I'm born to lose, and gambling's for fools,
But that's the way I like it baby,
I don't wanna live for ever,
And don't forget the joker!

Pushing up the ante, I know you wanna see me,
Read 'em and weep, the dead man's hand again,
I see it in your eyes, take one look and die,
The only thing you see, you know it's gonna be,
The Ace Of Spades
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

const int N = 1100031;

string a;
string b;

int cnt[N];
int fact[N];
int invf[N];

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

long long C(long long n,long long m){
	if (n<m)
		return 0;
	long long res=1ll*fact[n]*invf[n-m]%bs*invf[m]%bs;
	return res;
}

long long count_ways(int ps){
	long long res=fact[ps];
	for (int i=0;i<26;i++){
		if (cnt[i]<0)
			return 0;
		res*=invf[cnt[i]];
		res%=bs;
	}
	return res;
}

int solver(string have,string Z){
	for (int i=0;i<26;i++){
		cnt[i]=0;
	}
	for (int i=0;i<have.size();i++){
		cnt[have[i]-'a']++;
	}

	long long res=0;

	for (int cp=0;cp<have.size();cp++){
		long long here=fact[have.size()-cp];
		for (int j=0;j<26;j++){
			here*=invf[cnt[j]];
			here%=bs;
		}

		for (int next_char=0;next_char<Z[cp]-'a';next_char++){
			cnt[next_char]--;
			if (cnt[next_char]>=0){
				long long here2=here;
				here2*=fact[cnt[next_char]+1];
				here2%=bs;
				here2*=invf[cnt[next_char]];
				here2%=bs;
				here2*=invf[have.size()-cp];
				here2%=bs;
				here2*=fact[have.size()-cp-1];
				here2%=bs;
				res+=here2;
				if (res>=bs)
					res-=bs;
			}
			cnt[next_char]++;
		}
		cnt[Z[cp]-'a']--;
		if (cnt[Z[cp]-'a']<0)
			break;
	}

	return res;
}
int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	fact[0]=1;
	for (int i=1;i<N;i++){
		fact[i]=1ll*fact[i-1]*i%bs;
	}

	invf[N-1]=inv(fact[N-1]);
	for (int i=N-2;i>=0;--i){
		invf[i]=1ll*invf[i+1]*(i+1)%bs;
	}

//	cout<<fact[1]<<" "<<" "<<fact[10]<<" "<<invf[1]<<" "<<endl;

	cin>>a>>b;

	int res=solver(a,b)-solver(a,a)-1;
	while (res<0)
		res+=bs;

	cout<<res<<endl;

//	cin.get(); cin.get();
	return 0;
}