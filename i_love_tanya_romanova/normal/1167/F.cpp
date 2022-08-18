/*
The freeway is jammed and it's backed up for miles
The car is an oven and baking is wild
Nothing is ever the way it should be
What we deserve we just don't get you see

A briefcase, a lunch and a man on the edge
Each step gets closer to losing his head
Is someone in heaven are they looking down
'Cause nothing is fair just you look around

Falling down

He's sick of waiting of lying like this
There's a hole in the sky for the angels to kiss
Branded a leper because you don't fit
In the land of the free you just live by your wits

Once he built missiles a nation's defence
Now he can't even give birthday presents
Across the city he leaves in his wake
A glimpse of the future a cannibal state

Falling down

The freeway is jammed and it's backed up for miles
The car is an oven and baking is wild
Nothing is ever the way it should be
What we deserve we just don't get you see

A briefcase, a lunch and a man on the edge
Each step gets closer to losing his head
Is someone in heaven are they looking down
'Cause nothing is fair just you look around

Falling down
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 700031;

int n,ar[N];
vector<pair<int,int> > order;
long long ans;
long long t1[N];
long long t2[N];

long long sum1 (int r)
{
	long long result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t1[r],
		result%=bs;
	return result;
}

long long sum2 (int r)
{
	long long result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t2[r],
		result%=bs;
	return result;
}


long long sum1(int l,int r){
	long long ret=sum1(r)-sum1(l-1);
	if (ret<0)
		ret+=bs;
	return ret;
}

long long sum2(int l,int r){
	long long ret=sum2(r)-sum2(l-1);
	if (ret<0)
		ret+=bs;
	return ret;
}

void add1 (int i, long long delta)
{
	for (; i <= n; i = (i | (i+1)))
		t1[i] += delta,
		t1[i]%=bs;
}

void add2 (int i, long long delta)
{
	for (; i <= n; i = (i | (i+1)))
		t2[i] += delta,
		t2[i]%=bs;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	order.push_back(make_pair(ar[i],i));
    }

    sort(order.begin(),order.end());

    for (int i=0;i<order.size();i++){
    	int id=order[i].second;
    	add1(id,id);
    	add2(id,n-id+1);
    	ans+=(n-id+1)*sum1(1,id-1)%bs*ar[id]%bs;
    	ans+=id*sum2(id+1,n)%bs*ar[id]%bs;
    	ans%=bs;
    	ans+=1ll*id*(n-id+1)%bs*ar[id]%bs;
    	ans%=bs;
    }

    cout<<ans<<endl;


//    cin.get(); cin.get();
    return 0;
}