/*
I've been walking over graves
Carving out the headstone
That I own
My own
I'm like a monster in a cage
Trapped inside a maze
I am home
I'm home
I'm here and gone
I'm dead and done
I know
There's nothing I can change (digging my own)
And I regret (digging my own)
The things I didn't say
I resent
How I walked away (digging my own)
Now I'm digging my own grave (digging my own)
Now I'm digging my own
Digging my own grave
Is there peace beyond the rage?
Tell me where it truly
All went wrong
Went wrong
I've been walking through the graves
Dancing with the lonely
And the strong
The strong
I'm here and gone
I'm dead and done
I know
There's nothing I can change (digging my own)
And I regret (digging my own)
The things I didn't say
I resent
How I walked away (digging my own)
Now I'm digging my own grave (digging my own)
Now I'm digging my own
Digging my own grave
Digging my
Digging my grave

I know
There's nothing I can change (digging my own)
And I regret (digging my own)
The things I didn't say (digging my, digging my grave)
I resent
How I walked away (digging my own)
Now I'm digging my own grave (digging my own)
Now I'm digging my own
Digging my own grave
Is there peace beyond the rage
'Cause I've been digging my own
Digging my own
Grave
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
const int N = 411031;

int n,a[N],b[N],h[N];
vector<int> vals;
vector<pair<int,int> > order;
map<int,int> maps;

long long ans;
long long t[N*4];

vector<int> compress(vector<int> v){
	sort(v.begin(),v.end());
	vector<int> ret;
	for (int i=0;i<v.size();i++)
	{
		if (i==0||v[i]!=v[i-1])
			ret.push_back(v[i]);
	}
	return ret;
}

long long get(int v,int tl,int tr,int l,int r)
{
	if (l>r)
		return 0;
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	return max(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

void update(int v,int tl,int tr,int ps,long long val)
{
	if (tl==tr)
	{
		t[v]=max(t[v],val);
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		update(v*2,tl,tm,ps,val);
	else
		update(v*2+1,tm+1,tr,ps,val);
	t[v]=max(t[v*2],t[v*2+1]);
}

bool cmp2(int v1,int v2)
{
	if (b[v1]!=b[v2])
		return b[v1]>b[v2];
	return a[v1]>a[v2];
}

bool cmp(pair<int,int> p1,pair<int,int> p2)
{
	return cmp2(p1.second,p2.second);
}

int main(){
//	freopen("explosion.in","r",stdin);
//	freopen("explosion.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>h[i];
		vals.push_back(a[i]);
		vals.push_back(b[i]);
//		order.push_back(make_pair(b[i],i));
	}

	vals=compress(vals);
	for (int i=0;i<vals.size();i++)
	{
		maps[vals[i]]=i;
	}

	for (int i=1;i<=n;i++)
	{
		a[i]=maps[a[i]];
		b[i]=maps[b[i]];
		order.push_back(make_pair(b[i],i));
	}

	sort(order.begin(),order.end(),cmp);
	//reverse(order.begin(),order.end());

	for (int i=0;i<order.size();i++)
	{
		int id=order[i].second;
		long long here=get(1,0,vals.size()-1,0,b[id]-1);
		ans=max(ans,here+h[id]);
		update(1,0,vals.size()-1,a[id],here+h[id]);
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}