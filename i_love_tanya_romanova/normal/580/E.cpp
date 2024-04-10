/*
Stop it
There's been too much debate
We could save ourselves from holocaust
Or is that just our fate

Start now
But we continue to balk
We let the genie out of the bottle
But we still hold the cork

One, two, not!
Three, four, die
One, two, not!
Three, four, die

Ignorance is no excuse
For violence, no one wins
One world! One world!

One world! Welcome to it
One world! Don't abuse it
One world! To live out your life
One world! Total schism, tunnel vision
One world! Taming the beast, fighting for peace

Killing
You pushed a button, that's all you did
It's much harder to kill a man
If you've seen pictures of his kids

Responsibility
And what are all our lives worth?
What kind of sentence would you serve
For killing the earth

One, two, not!
Three, four, die
One, two, not!
Three, four, die

Ignorance is no excuse
For violence, no one wins
One world! One world!

One world! Welcome to it
One world! Don't abuse it
One world! To live out your life
One world! Total schism, tunnel vision
One world! Taming the beast, fighting for peace

One world! One world!

One world! Welcome to it
One world! Don't abuse it
One world! To live out your life
One world! Total schism, tunnel vision
One world! Taming the beast, fighting for peace

Russians
They're only people like us
Do you really think they'd blow up the world
Don't they love their lives less

America
Stop singing hail to the chief
Instead of thinking S.D.I.
He should be thinking of peace

One, two, not!
Three, four, die
One, two, not!
Three, four, die

Ignorance is no excuse
For violence, no one wins
One world! One world!

One world! Welcome to it
One world! Don't abuse it
One world! To live out your life
One world! Total schism, tunnel vision
One world! Taming the beast, fighting for peace

One world!
*/

//#pragma comment(linker, "/STACK:16777216")
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

string st;
int n,m,k;
long long pw1[1<<21],pw2[1<<21];
long long s1[1<<21],s2[1<<21];
int topush[1<<21];
pair<long long, long long> t[1<<21];

void push(int v,int tl,int tr)
{
	if (topush[v]==-1)
		return ;
	topush[v*2]=topush[v];
	topush[v*2+1]=topush[v];
	int val=topush[v];
	topush[v]=-1;
	int tm=tl+tr;
	tm/=2;
	
	t[v*2].first=s1[(tm-tl+1)]*val%bs;
	t[v*2].second=s2[(tm-tl+1)]*val%bs;
	
	t[v*2+1].first=s1[(tr-tm)]*val%bs;
	t[v*2+1].second=s2[(tr-tm)]*val%bs;
	
	t[v].first=(t[v*2].first+t[v*2+1].first*pw1[tm-tl+1])%bs;
	t[v].second=(t[v*2].second+t[v*2+1].second*pw2[tm-tl+1])%bs;
}

void build(int v,int tl,int tr)
{
	topush[v]=-1;
	
	if (tl==tr)
	{
		int val=st[tl]-48;
		t[v]=make_pair(val,val);
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	
	t[v].first=(t[v*2].first+t[v*2+1].first*pw1[tm-tl+1])%bs;
	t[v].second=(t[v*2].second+t[v*2+1].second*pw2[tm-tl+1])%bs;
}

pair<long long, long long> get(int v,int tl,int tr,int l,int r,int ofset)
{
	if (l>r)
		return make_pair(0,0);
	if (tl==l&&tr==r)
		return make_pair(t[v].first*pw1[ofset]%bs,t[v].second*pw2[ofset]%bs);
	
	push(v,tl,tr);
	
	int tm=tl+tr;
	tm/=2;
	pair<long long, long long> p1,p2;
	p1=get(v*2,tl,tm,l,min(r,tm),ofset);
	int ohead=(tm+1)-l;
	if (ohead<0)
		ohead=0;
	p2=get(v*2+1,tm+1,tr,max(tm+1,l),r,ofset+ohead);
	return make_pair((p1.first+p2.first)%bs,(p1.second+p2.second)%bs);
}

void update(int v,int tl,int tr,int l,int r,int val)
{
	if (l>r)
		return ;
	if (l==tl&&r==tr)
	{
		topush[v]=val;
		t[v].first=s1[(r-l+1)]*val%bs;
		t[v].second=s2[(r-l+1)]*val%bs;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	push(v,tl,tr);
	
	update(v*2,tl,tm,l,min(r,tm),val);
	update(v*2+1,tm+1,tr,max(tm+1,l),r,val);
	
	t[v].first=(t[v*2].first+t[v*2+1].first*pw1[tm-tl+1])%bs;
	t[v].second=(t[v*2].second+t[v*2+1].second*pw2[tm-tl+1])%bs;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;

pw1[0]=1;
for (int i=1;i<=(1<<20);i++)
	pw1[i]=pw1[i-1]*137%bs;
pw2[0]=1;
for (int i=1;i<=(1<<20);i++)
	pw2[i]=pw2[i-1]*187%bs;

for (int i=0;i<(1<<20);i++)
{
	s1[i+1]=s1[i]+pw1[i];
	s2[i+1]=s2[i]+pw2[i];
	s1[i+1]%=bs;
	s2[i+1]%=bs;
}

cin>>st;
build(1,0,n-1);

for (int iter=1;iter<=m+k;iter++)
{
	int tp;
	cin>>tp;
	if (tp==1)
	{
		int l,r,val;
		cin>>l>>r>>val;
		--l;
		--r;
		update(1,0,n-1,l,r,val);
	}
	else
	{
		int l,r,d;
		cin>>l>>r>>d;
		--l;
		--r;
		pair<long long ,long long> p1,p2;
		p1=get(1,0,n-1,l,r-d,0);
		p2=get(1,0,n-1,l+d,r,0);
		if (p1.first==p2.first&&p1.second==p2.second)
			puts("YES");
		else
			puts("NO");
	}
}

//cin.get();cin.get();
return 0;}