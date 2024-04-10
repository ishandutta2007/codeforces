/*
There is this face in the still water
I can't remember ever wearing
Like fingerprints on your heart
Reading out the last lines of code
To the untrained eye a secret
I bled away the last of you

Sought trust in shapes of combined results
That trickles from a less than solid case
Fought off attacks of resurfaced lust
Burn the gracing grounds

No, what will give in first?
The body or the lash
Monochromatic stains
No, who will cave in first?
The leader or the fake
Monochromatic stains, oh!

This pile of ashes of a soul
Informant pokes abound
These sickly little fingers
Get away from me

Tread not the path of least restraint
Each piece of evidence a lie, a lie
The body, the face all items in place
I don't remember a thing

No, what will give in first?
The body or the lash
Monochromatic stains
No, who will cave in first?
The leader or the fake
Monochromatic stains

A sacrifice made to the loss of mind
Folly a man's demise

Track now the stains that allow my fall
Sickening, the sight of it all
Never shall I claim my innocence
I just was not there

No, what will give in first?
The body or the lash
Monochromatic stains
No, who will cave in first?
The leader or the fake
Monochromatic stains
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

#define bs 998244353

const int N = 1200031;

long long fact[N],invf[N];

long long answ;
int n;

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
	long long res=fact[n]*invf[n-m];
	res%=bs;
	res*=invf[m];
	return res%bs;
}

long long solver(int n){
	long long ret=0;

	for (int rows=1;rows<=n;rows++){
		long long ways=C(n,rows)*pw(3,rows)%bs*pw(3,(1ll*n-rows)*n)%bs;
		if (rows%2==1)
			ret+=ways;
		else
			ret+=bs-ways;
//		cout<<ways<<"@"<<rows<<endl;
		ret%=bs;
	}
	return ret;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	fact[0]=1;
	for (int i=1;i<N;i++){
		fact[i]=fact[i-1]*i%bs;
	}

	invf[N-1]=inv(fact[N-1]);
	for (int i=N-2;i>=0;--i){
		invf[i]=invf[i+1]*(i+1)%bs;
	}

	cin>>n;

	// ans = have_rows+have_cols-have_rows&cols;

	long long have_rows=solver(n);

//	cout<<have_rows<<endl;

	answ=have_rows*2%bs;

	long long s=0;

	for (int rows=1;rows<=n;rows++){
		long long dif=pw(3,rows)-3+bs;
		dif%=bs;
		dif*=pw(3,(n-rows)*1ll*n);
		dif%=bs;
		//cout<<"@"<<dif<<endl;
		// all same
		long long Q=pw(3,n-rows)+bs-1;
		Q%=bs;
		Q=pw(Q,n);
		dif+=Q*3%bs;
		dif%=bs;
		dif*=C(n,rows);
		dif%=bs;
		if (rows%2==1)
			s+=dif;
		else
			s+=bs-dif;
		s%=bs;

		//cout<<rows<<" "<<dif<<endl;
	}

	s=have_rows-s;
//	cout<<s<<endl;
	s+=bs;
	s%=bs;
	have_rows=have_rows*2-s;
	have_rows%=bs;
	if (have_rows<0)
		have_rows+=bs;
	cout<<have_rows<<endl;

//	cin.get(); cin.get();
	return 0;
}