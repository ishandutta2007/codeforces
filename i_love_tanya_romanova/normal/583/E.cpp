/*
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
#define move adsfasfsdf

using namespace std;

int gcd(int a,int b)
{
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

vector<int> divs(int x)
{
	vector<int> res;
	for (int i=1;i<=x;i++)
	{
		if (x%i==0)
			res.push_back(i);
	}
	return res;
}

int n,ar[1<<20];
long long ans;
int mx[1<<20];
int total[1<<20],f[1<<20];

long long solve(int G)
{
	for (int i=0;i<G;i++)
		mx[i]=-1;
	for (int i=0;i<n;i++)
		mx[i%G]=max(mx[i%G],ar[i]);
	
	for (int i=1;i<=n*2;i++)
	{
		total[i]=total[i-1];
		if (f[i]==G)
			++total[i];
	}
	
	long long res=0;
	int ptr=-1;
	for (int i=0;i<n*2;i++)
	{
		int need=mx[i%G];
//		cout<<ar[i]<<"   "<<need<<" "<<G<<" "<<ans<<endl;
		
		if (ar[i]!=need)
		{
			ptr=i;
			continue;
		}
		if (i<n)
			continue;
		int span=i-ptr;
//		cout<<i<<"  "<<ar[i]<<" "<<need<<" "<<G<<" "<<span<<" "<<total[span]<<endl;
		res+=total[span];
	}
	return res;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
	cin>>ar[i];

for (int i=n;i<n*2;i++)	
	ar[i]=ar[i-n];

for (int i=1;i<=n;i++)
	f[i]=gcd(i,n);

vector<int> vals=divs(n);

for (int i=0;i<vals.size();i++)
{
	ans+=solve(vals[i]);
}

cout<<ans-n<<endl;

//cin.get();cin.get();
return 0;}