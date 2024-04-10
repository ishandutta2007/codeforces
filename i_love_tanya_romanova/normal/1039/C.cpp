/*
Don't try to tell us what is right for us
We don't give a fuck anyway
Don't try to steal imagination from us
Things we believe and we will never betray, never betray

Those who have the power to
Suck us dry - throw us away
Those who never could create
Destroy the music of today

Those devoid of any feeling
Those who make the compromise
Betray themselves to make a deal
Sell their soul at any price

Sounds without feeling, energy or aggression
From money hungry brains and not from the heart
Fortune, fame and glory are their obsession
Salesmen, deaf to music, blind to art

No honesty, just sterility
A cautious sound they make without creativity
It's still the same as another age
When they took the words of truth and put them to a flame

No more
Love us or hate us
No more
Love us or hate us

Some have eyes and still can't see
Their plastic noise is anything but music to me
Mechanized and computerized
Switch off your brain and make sounds that dehumanize

No more
Love us or hate us
No more
Love us or hate us

Don't try to take our dreams away from us
We will never be like you
Love us or hate us, it doesn't matter to me
We don't want to be a part of this sick society

Those who have a passion to
Will never change our way of life
We may not think the way you do
But we know that we are right
Those who want to form a world
Of trends and monotony
Have to do it without us
'Cause we always will be free
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600000;

long long n,m,k,C[N];
vector<pair<long long, long long> > order;
long long V[N];
long long w[N];
long long a[N],b[N];
long long comps;
vector<long long> edges_to_clean;

int get(int x){
	if (x==w[x])
		return x;
	w[x]=get(w[x]);
	return w[x];
}

int merge(int a,int b){
	w[a]=b;
}

long long values_of_virus;

long long ans;

long long pw(long long a,long long b){
	a%=bs;
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

void solver(){
	values_of_virus--;
	long long for_this=pw(2,comps);
	ans=ans+for_this;
	ans%=bs;
}

void cleanup()
{
	for (int i=0;i<edges_to_clean.size();i++){
		int id=edges_to_clean[i];
		w[a[id]]=a[id];
		w[b[id]]=b[id];
	}
	edges_to_clean.clear();
	comps=n;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
		scanf("%lld",&C[i]);//cin>>C[i];
	}

	for (int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
		scanf("%lld",&b[i]);
		V[i]=(C[a[i]]^C[b[i]]);
		order.push_back(make_pair(V[i],i));
	}

	sort(order.begin(),order.end());

	values_of_virus=(1ll<<k);

	for (int i=1;i<=n;i++){
		w[i]=i;
	}

	comps=n;

	for (int i=0;i<order.size();i++){
		if (i>0&&order[i].first!=order[i-1].first){
			solver();
			cleanup();
		}
		int id=order[i].second;
		edges_to_clean.push_back(id);
		int v1=a[id];
		int v2=b[id];
		v1=get(v1);
		v2=get(v2);
		if (v1!=v2)
			comps--;
		merge(v1,v2);
	}

	if (order.size()>0) // last block
	{
		solver();
	}

	long long for_boring=pw(2,n);
	values_of_virus%=bs;
	ans+=for_boring*values_of_virus;
	ans%=bs;

	printf("%lld\n",ans);

//	cin.get(); cin.get();
	return 0;
}