/*
Dreamt up a new word today
With my ignorance I gave it meaning
Who was I to know?
To say it is to know it
To hear it is to believe, is to believe

I dreamt the world would end
I was not wrong
To doubt, to discredit
The other words I've heard before
From inside a shell pretending

It's all you've shown your faith
And what you've always known
So lay your trust in the unthinkable
It's time to justify your lesser faith

It's all your faith has shown
And all you'll ever know
Why do you matter, you're insignificant
How can you justify your lesser faith?

Oh!
To know it is to fear it
To feel it is to say no, is to say no
To the blazing highs and lows
I know I'll fail
To break, to cast it down
You take your lead
From a staff that must be broken in two

It's all your faith has shown
And all you'll ever know
Why do you matter, you're insignificant
How can you justify your lesser faith?
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
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 1100031;

vector<int> order;
vector<int> V;
map<int,int> cnt;
map<int,int>::iterator it;

long long fact[N];
long long invf[N];

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

long long get_C(long long n,long long m){
	long long ret=fact[n];
	ret*=invf[n-m];
	ret%=bs;
	ret*=invf[m];
	return ret%bs;
}
long long solver(long long n)
{
	long long ret=fact[n]*n%bs;
	ret-=(n-1);
	ret%=bs;
	for (int i=1;i<n;i++){
		long long ttl=get_C(n,i)*(fact[n-i])%bs;
		ret-=ttl;
		ret+=bs;
		ret%=bs;
	}
	ret=(ret+n-1)%bs;
	while (ret<0)
		ret+=bs;
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    fact[0]=1;
    for (int i=1;i<N;i++){
    	fact[i]=fact[i-1]*i%bs;
    }

    invf[N-1]=inv(fact[N-1]);
    for (int i=N-2;i>=0;--i)
    {
    	invf[i]=invf[i+1]*(i+1)%bs;
    }

    int n;
    cin>>n;
    cout<<solver(n)<<endl;

   /* for (int n=1;n<=9;n++){
    	order.clear();
    	for (int i=1;i<=n;i++){
    		order.push_back(i);
    	}
    	V.clear();
    	do
    	{
    		for (int i=0;i<order.size();i++)
    			V.push_back(order[i]);
    	}while (next_permutation(order.begin(),order.end()));
    	int res=0;
    	cnt.clear();
    	for (int start=0;start+n<=V.size();start++){
    		int s=0;
    		for (int i=start;i<start+n;i++){
    			s+=V[i];
    		}
    		cnt[s]++;
    		if (s==n*(n+1)/2)
    			++res;
    	}
    	cout<<n<<" "<<res<<endl;
    	cout<<solver(n)<<endl;
    }
    */


//    cin.get(); cin.get();
    return 0;
}