/*
As through your shattered eyes
It all came together
And your heart cries
Weeping through the weather
Another way to change your mind
I'm weaker than they say
To leave this all behind
The only way to stay

Don't you know
I'm the end of what we'll be
And right below us
The last thing you'll see

In the water
I saw you drown
Down the water
Saw you drown

As through my shattered sight
You're no longer here
And my heart cries
Sleeping through the light
Another way to change my mind
Never is the day
To leave this all behind
The only way to stay
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const int bs = 998244353;

const int N = 600031;

long long fact[N],invf[N];

long long pw(long long a,long long b){
	if (b==0)
		return 1%bs;
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
	long long res=fact[n];
	res*=invf[n-m];
	res%=bs;
	res*=invf[m];
	return res%bs;
}

int n,k;
int S[N];
vector<pair<int,int> > events;
int l[N],r[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    fact[0]=1;
    for (int i=1;i<N;i++){
    	fact[i]=fact[i-1]*i%bs;
    }

    invf[N-1]=inv(fact[N-1]);
    for (int i=N-2;i>=0;i--){
    	invf[i]=invf[i+1]*(i+1)%bs;
    }
    cin>>n>>k;
    for (int i=1;i<=n;i++){
    	cin>>l[i]>>r[i];
    	events.push_back(make_pair(l[i],-i));
    	events.push_back(make_pair(r[i],i));
    }
    sort(events.begin(),events.end());

    for (int i=0;i<events.size();i++){
    	S[i]=(events[i].second<0);
    	if (i>0)
    		S[i]+=S[i-1];
    }

    long long ans=0;

    int opn=0;

    for (int i=0;i<events.size();i++){
    	if (events[i].second<0){
    		++opn;
    		continue;
    	}
    	long long here=C(opn-1,k-1);
    	ans+=here;
    	ans%=bs;
    	--opn;
    }

    cout<<ans<<endl;

    //cin.get(); cin.get();
    return 0;
}