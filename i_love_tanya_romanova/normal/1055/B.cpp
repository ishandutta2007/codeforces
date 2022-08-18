/*
Spare the rod, spoil the child
Daddy's boy's been too wild
His discipline's taught with a strap
No sweet song on father's lap
He always said that men don't cry
But burns and bruises seldom lie
Dad learned his lesson well
Spitting image of a man in hell

Brought up in a home where love's replaced by pain
And when he's on his own he's sure to do the same
Expressing his feelings not with love but with his fists
The pattern of hurting began generations before

Like father, like son
Another life has begun
The punishing ways that you choose
You were always born to lose
Like father, like son
A war you've never won
Please Daddy, no more...
Please Daddy, no more!

The circle continues of violence passed down
All there is hope for is a tear from a clown
Hoping someday that this torture will end
To prison or death I hope you will be sent

Now do you feel like your life is on hold?
Maybe you've come to the end of your road
Admitting your sins may be your sacrifice
To stop all this pain to your son and your wife
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

int n,m,l;
int w[N];
int comps;

long long ar[N];

int get(int x){
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

void merge(int a,int b){
	a=get(a);
	b=get(b);
	if (a==b)
		return ;
	--comps;
	w[a]=b;
}

void update(int ps){
	w[ps]=ps;
	++comps;
	if (ar[ps-1]>l){
		merge(ps,ps-1);
	}
	if (ar[ps+1]>l){
		merge(ps,ps+1);
	}
}

void add(int ps,int val){
	if (ar[ps]<=l&&ar[ps]+val>l){
		update(ps);
	}
	ar[ps]+=val;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>l;

	for (int i=1;i<=n;i++){
		int val;
		cin>>val;
		add(i,val);
	}

	for (;m;--m){
		int tp;
		cin>>tp;
		if (tp==0){
			cout<<comps<<"\n";
		}
		else
		{
			int ps,val;
			cin>>ps>>val;
			add(ps,val);
		}
	}

//	cin.get(); cin.get();
	return 0;
}