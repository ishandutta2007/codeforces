/*
There's a secret place I like to go
Everyone is there but their face don't show
If you get inside you can't get out
There's no coming back, I hear them shout

Welcome to my hide away, my secret place
How I arrived I can't explain
You're welcome to, if you want to stay
But everyone just runs away

Let me in, get me out
Can't do more than twist and shout
Lost my soul without a trace
Found it again in my secret place
In disgrace

I hide from those that try to find me
Scary things that's right behind me
I lost myself, I must confess
I can't explain how I got this mess
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

const int N = 600031;

int gcd(int a,int b){
	while(a&&b)a>b?a%=b:b%=a;
	return a+b;
}

int n,ar[N];
int t[N*4];
vector<pair<int,int> > entries[N];

void build(int v,int tl,int tr){
	entries[tl].push_back(make_pair(tr,v));
	if (tl==tr)
	{
		t[v]=ar[tl];
		return;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v]=gcd(t[v*2],t[v*2+1]);
}

int tests;

int get(int v,int tl,int tr,int l,int r,int X){
	if (l>r)
		return 1;
	if (tl==l&&tr==r)
		return t[v]%X==0;
	int tm=tl+tr;
	tm/=2;
	int a=get(v*2,tl,tm,l,min(r,tm),X);
	int b=get(v*2+1,tm+1,tr,max(tm+1,l),r,X);
	return a&&b;
}

int get_rightmost(int ps,int val){
	while (true){
		if (ps>n)
			break;
		int found=0;
		for (int i=entries[ps].size()-1;i>=0;--i){
			int v_id=entries[ps][i].second;
			int reach=entries[ps][i].first;
		//	cout<<ps<<" "<<v_id<<" "<<reach<<" "<<val<<endl;
			if (t[v_id]%val==0)
			{
				ps=reach+1;
				found=1;
				break;
			}
		}
		if (found==0)
			break;
	}
	return ps-1;
}

int solver(int L,int R,int x){
	int ps=get_rightmost(L,x);
	//cout<<ps<<"@"<<endl;

	if (ps>=R-1)
		return 1;
	return get_rightmost(ps+2,x)>=R;
}

void update(int v,int tl,int tr,int ps,int val){
	if (tl==tr){
		t[v]=val;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		update(v*2,tl,tm,ps,val);
	else
		update(v*2+1,tm+1,tr,ps,val);
	t[v]=gcd(t[v*2],t[v*2+1]);
}


int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
//	cin.tie(0);

	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&ar[i]);
	}

	build(1,1,n);

	for (int i=1;i<=n;i++){
		sort(entries[i].begin(),entries[i].end());
	}

	scanf("%d",&tests);
	for (;tests;--tests){
		int tp;
		scanf("%d",&tp);
		if (tp==2){
			int ps;
			int val;
			scanf("%d",&ps);
			scanf("%d",&val);
			ar[ps]=val;
			update(1,1,n,ps,val);
		}
		if (tp==1){
			int l,r,x;
			scanf("%d",&l);
			scanf("%d",&r);
			scanf("%d",&x);
			if (solver(l,r,x))
				puts("YES");
			else
				puts("NO");
		}
	}
//	cin.get(); cin.get();
	return 0;
}