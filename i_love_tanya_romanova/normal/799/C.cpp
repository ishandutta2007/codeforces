/*
Can you feel that?
Ah, shit
Oh, ah, ah, ah, ah
Oh, ah, ah, ah, ah
oh, oh, oh, oh, oh, oh

Drowning deep in my sea of loathing
Broken your servant I kneel
(Will you give in to me?)
It seems what's left of my human side
Is slowly changing in me
(Will you give in to me?)

Looking at my own reflection
When suddenly it changes
Violently it changes (oh no)
There is no turning back now
You've woken up the demon in me

Get up, come on get down with the sickness
Get up, come on get down with the sickness
Get up, come on get down with the sickness
Open up your hate, and let it flow into me
Get up, come on get down with the sickness
You mother get up come on get down with the sickness
You fucker get up come on get down with the sickness
Madness is the gift, that has been given to me

I can see inside you, the sickness is rising
Don't try to deny what you feel
(Will you give in to me?)
It seems that all that was good has died
And is decaying in me
(Will you give in to me?)

It seems you're having some trouble
In dealing with these changes
Living with these changes (oh no)
The world is a scary place
Now that you've woken up the demon in me

Get up, come on get down with the sickness
Get up, come on get down with the sickness
Get up, come on get down with the sickness
Open up your hate, and let it flow into me
Get up, come on get down with the sickness
You mother get up come on get down with the sickness
You fucker get up come on get down with the sickness
Madness is the gift, that has been given to me

(And when I dream)
(And when I dream)
(And when I dream), (and when I dream)
No mommy, don't do it again
Don't do it again
I'll be a good boy
I'll be a good boy, I promise
No mommy don't hit me
Why did you have to hit me like that, mommy?
Don't do it, you're hurting me
Why did you have to be such a bitch

Why don't you
Why don't you just fuck off and die
Why can't you just fuck off and die
Why can't you just leave here and die
Never stick your hand in my face again bitch
Fuck you
I don't need this shit
You stupid sadistic abusive fucking whore
How would you like to see how it feels mommy
Here it comes, get ready to die

Oh, ah, ah, ah, ah
Get up, come on get down with the sickness
Get up, come on get down with the sickness
Get up, come on get down with the sickness
Open up your hate, and let it flow into me
Get up, come on get down with the sickness
You mother get up come on get down with the sickness
You fucker get up come on get down with the sickness
Madness has now come over me
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 300031;

int n,C,D;
int b[N],p[N];
string st;
vector<pair<int,int> > v1,v2;

multiset<pair<int,int> > S;
multiset<pair<int,int> > by_beauty;
multiset<pair<int,int> > ::iterator it;

int solver(vector<pair<int,int> > v,int thold)
{
	for (int i=0;i<v.size();i++)
	{
		swap(v[i].first,v[i].second);
	}

	sort(v.begin(),v.end()); // price, beauty

	S.clear();
	by_beauty.clear();

	for (int i=0;i<v.size();i++)
	{
		S.insert(v[i]);
		by_beauty.insert(make_pair(v[i].second,v[i].first));
	}

	int ret=0;

	for (int i=0;i<v.size();i++)
	{
		int cur_cost=v[i].first;
		int rem=thold-cur_cost;

		while (true)
		{
			if (S.size()==0)
				break;
			it=S.end();
			--it;
			int cost_here=(*it).first;
			pair<int,int> pp=(*it);
			swap(pp.first,pp.second);


			if (cost_here>rem)
			{
				S.erase(it);
				by_beauty.erase(by_beauty.find(pp));
			}
			else
				break;
		}

		if (S.find(v[i])!=S.end())
			S.erase(S.find(v[i]));
		if (by_beauty.find(make_pair(v[i].second,v[i].first))!=by_beauty.end())
			by_beauty.erase(by_beauty.find(make_pair(v[i].second,v[i].first)));
		if (S.size()==0)
			continue;
		it=by_beauty.end();
		--it;
		int here=(*it).first;
		ret=max(ret,v[i].second+here);
	}
	return ret;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>C>>D;

	for (int i=1;i<=n;i++)
	{
		cin>>b[i]>>p[i];
		cin>>st;
		if (st=="C")
			v1.push_back(make_pair(b[i],p[i]));
		else
			v2.push_back(make_pair(b[i],p[i]));
	}


	int ans=0;

	int best_a=-1;
	int best_b=-1;
	for (int i=0;i<v1.size();i++)
	{
		if (v1[i].second<=C)
			best_a=max(best_a,v1[i].first);
	}
	for (int i=0;i<v2.size();i++)
	{
		if (v2[i].second<=D)
			best_b=max(best_b,v2[i].first);
	}

	if (best_a>0&&best_b>0)
		ans=best_a+best_b;

	ans=max(ans,solver(v1,C));

	ans=max(ans,solver(v2,D));

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}