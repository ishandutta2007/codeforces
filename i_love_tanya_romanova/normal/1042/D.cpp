/*
Like the poison running through your veins
You're addicted to the pain and the shame
Chasing the same game every day
Hooked on all your bullshit and your vanity

Blind decisions, no regrets
A bittersweet of toxic sweat

Take my pride, taken chances all my life
Never answers, but in time
You just wait, you're gonna say my name
Break this bind, cut my losses
No more carrying all your crosses, 'cause in time
You just wait, you're gonna say my name
Oh, you're gonna say my name

A normal situation in disguise
Dragging me through your self-inflicted lies
Too bad you're never gonna win this game
Your misery's your only friend and you're to blame

Blind decisions, no regrets
A bittersweet of toxic sweat

Take my pride, taken chances all my life
Never answers, but in time
You just wait, you're gonna say my name
Break this bind, cut my losses
No more carrying all your crosses, 'cause in time
You just wait, you're gonna say my name
Oh, you're gonna say my name

Bringing everybody down, down, down and turn it around
Into the same game, twisting it upside down
Another go around, you're gonna say my name
It's gonna come around... yeah!
Bringing everybody down, down, down and turn it around
Into the same game, twisting it upside down
Another go around, you're gonna say my name
You're gonna say my name, say my name

Take my pride, taken chances all my life
Never answers, but in time
You just wait, you're gonna say my name
Break this bind, cut my losses
No more carrying all your crosses, 'cause in time
You just wait, you're gonna say my name
Oh, bitch! Say my name
You know you're gonna say my name
Oh, say my name
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

int n;
long long t;
long long S[N];
long long T[N*4];
int ar[N];
vector<pair<long long, int> >order;

long long ans;

void add(int v,int tl,int tr,int ps,int val){
	if (tl==tr){
		T[v]+=val;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		add(v*2,tl,tm,ps,val);
	else
		add(v*2+1,tm+1,tr,ps,val);
	T[v]=T[v*2]+T[v*2+1];
}

int get(int v,int tl,int tr,int l,int r)
{
	if (l>r)
		return 0;
	if (tl==l&&tr==r)
		return T[v];
	int tm=tl+tr;
	tm/=2;
	return get(v*2,tl,tm,l,min(r,tm))+get(v*2+1,tm+1,tr,max(tm+1,l),r);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>t;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		S[i]=S[i-1]+ar[i];
		order.push_back(make_pair(S[i],i));
	}

	order.push_back(make_pair(S[0],0));
	sort(order.begin(),order.end());

	/*for (int i=0;i<order.size();i++){
		cout<<order[i].first<<" "<<order[i].second<<endl;
	}*/

	for (int i=0;i<=n;i++){
		long long need=S[i]-t+1;
		int id=lower_bound(order.begin(),order.end(),make_pair(need,-1))-order.begin();
		ans+=get(1,0,n,id,n);
	//	cout<<"@"<<id<<" "<<ans<<endl;

		id=lower_bound(order.begin(),order.end(),make_pair(S[i],i))-order.begin();
		add(1,0,n,id,1);
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}