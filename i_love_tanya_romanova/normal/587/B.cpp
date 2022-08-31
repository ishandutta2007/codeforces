/*
I've marched to wars, with a vicious rage
I've counted thousands dead from righteous plague
I am history, from all you know
I am the future, that you will sow

I've been to hell, I've touched the sun
I've seen heavens fall, I am the one

I am the power, who blacks the night
I am the anger, for all your fights
I am the power, who parts the seas
I am the savoir, for all your needs

I was at the birth, of the longest day
I was there at the death, of the wisest sage
Over and over now it'll be the same
Mankind's on the path, to the final shame

I've been to hell, I've touched the sun
I've seen heavens fall, I am the one

I am the power, who blacks the night
I am the anger, for all your fights
I am the power, who parts the seas
I am the savoir, for all your needs

I am the power
I blacken the night

I am the power, who blacks the night
I am the anger, for all your fights
I am the power, who parts the seas
I am the savoir, for all your needs

I am the power, I blackened the night
I am the anger, who causes your fights
I am the power, who plants the seeds
I am the savoir, for your dark deeds
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

int n;
long long l;
int k;
int ar[1<<20];
int t[1<<21],dp[1<<21];

void add(int&a,int&b)
{
	a+=b;
	if (a>=bs)
		a-=bs;
}

int sum(int r)
{
	int res=0;
	for (;r>=0;r=(r&(r+1))-1)
		add(res,t[r]);
	return res;
}

void inc(int i,int delta)
{
	for (;i<(1<<20);i=(i|(i+1)))
		add(t[i],delta);
}

vector<pair<int, int> > order;

int get(int id)
{
	int block=id/n;
	if (block==0)
		return 1;
	--block;
	int lb=block*n;
	int rb=block*n+n-1;
	int res=sum(rb)-sum(lb-1);
	if (res<0)
		res+=bs;
//	cout<<"@"<<id<<" "<<res<<" "<<lb<<" "<<rb<<endl;
	return res;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>l>>k;

for (int i=0;i<n;i++)
	cin>>ar[i];

for (int i=0;i<n*k;i++)
{
	ar[i]=ar[i%n];
}

for (int i=0;i<n*k;i++)
{
	order.push_back(make_pair(ar[i],i));
}
sort(order.begin(),order.end());

for (int i=0;i<order.size();i++)
{
	int id=order[i].second;
	//int block=id/n;
	int res=get(id);
	dp[id]=res;
	inc(id,res);
}

int ans=0;

for (int i=0;i<n*k;i++)
{
	int id=i;
	int block=id/n;
	if (block>l/n)
		continue;
	long long remb=l/n-block;
	if (id%n<l%n)
		remb++;
	remb%=bs;
//	cout<<i<<" "<<block<<" "<<remb<<" "<<dp[i]<<endl;
	
	ans=(ans+1ll*remb*dp[i])%bs;
}
cout<<ans<<endl;


//cin.get();cin.get();
return 0;}