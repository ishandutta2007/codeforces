/*
Driving my fist down deep inside it, oh yeah
Gonna take it to a whole new level in spite of your bullshit (Baby)
Tasting sweet anxiety, breaking through another day
Maybe I just don't care anymore what you think of me

I'll take it to the edge
I'll take it to the other side
I hear it screaming
It's coming alive
I'll take it to the edge
I'll take it to the other side
I feel it breathing
Deep down inside
Deep down inside

Tearing through shards of broken glass, oh yeah
Getting one step closer to the edge and taking it all back (Baby)
Surging through my blackened veins, uncontrolled in a different way
I can't wait to get away from everything

I'll take it to the edge
I'll take it to the other side
I hear it screaming
It's coming alive
I'll take it to the edge
I'll take it to the other side
I feel it breathing
Deep down inside

Oh yeah, alright
I feel it coming alive, yeah
Oh yeah, alright
I'm breaking on through the other side

I'll take it to the edge
I'll take it to the other side
I hear it screaming
It's coming alive
I'll take it to the edge
I'll take it to the other side
I feel it breathing
Deep down inside

I'll take it to the edge of life, alright
I'll take it to the edge of life, I'm so alive
I'll take it to the edge of life, alright
I'll take it to the edge of life, alright
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

#define bs 1000000007

const int N = 410031;

long long n,k,A[N],B[N],a[N],b[N];

pair<long long, long long> p;
priority_queue<pair<long long, long long> > S;

bool solve(long long cap){
	for (int i=1;i<=n;i++){
		a[i]=A[i];
	}
	while (S.size())
		S.pop();

	for (int i=1;i<=n;i++){
		long long time=a[i]/B[i]+1;
		//cout<<i<<" "<<time<<endl;
		if (time<k)
			S.push(make_pair(-time,i));
	}

	for (int i=0;i<k;i++){
		if (S.size()==0)
			return true;
		p=S.top();
		p.first*=-1;
		S.pop();
		//cout<<p.first<<"@"<<p.second<<endl;
		if (p.first<=i)
			return false;
		a[p.second]+=cap;
		long long time=a[p.second]/B[p.second]+1;
		//cout<<time<<" "<<i<<" "<<p.second<<" "<<p.first<<endl;
		//cout<<cap<<" "<<i<<"@"<<time<<" "<<p.second<<" "<<a[p.second]<<endl;
		if (time<=i)
			return false;
		if (time<k)
			S.push(make_pair(-time,p.second));
	}
	return true;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>k;

    for (int i=1;i<=n;i++){
    	//cin>>A[i];
    	scanf("%lld",&A[i]);
    }
    for (int i=1;i<=n;i++){
    	//cin>>B[i];
    	scanf("%lld",&B[i]);
    }


    long long l,r;
    l=0;
    r=3e12;

    while (l<r){
    	long long mid=l+r;
    	mid/=2;
    	if (solve(mid))
    		r=mid;
    	else
    		l=mid+1;
    }

    if (l>2e12)
    	l=-1;
    cout<<l<<endl;

//    cin.get(); cin.get();
    return 0;
}