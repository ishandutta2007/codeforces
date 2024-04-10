/*
After death has taken you from life
You have come to me in the night
The aura of an ancient beauty shining through
Like a goddess of fallen grace
I'm longing for your souls embrace
And all that life has lost i've found in you

The spirit is willing the flesh is weak
Just like a thousand suns it shines on me
The spirit is willing the flesh is weak
For now i'm seeing more than the eye can see

So i wait as i watch the stars
I feel you're near but you're yet too far
Too heal me from the flames that penetrate my mind
I could swear that i 've felt your touch
Your magic presence i need so much
Becomes reality only at night

The spirit is willing the flesh is weak
Just like a thousand suns it shines on me
The spirit is willing the flesh is weak
For now i'm seeing more than the eye can see

As i watch you disappear in silence
Was it really true or just a dream
As morning drags me back to life
And swallowed everything
Illusion killed the angel without wings
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
const int N = 1211031;

int pr[N];
vector<int> primes;

int gcd(int a,int b)
{
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

long long f(long long x)
{
	long long res=x;
	for (int ii=0;ii<primes.size();ii++)
	{
		long long i=primes[ii];
		if (i*i>x)
			break;
		if (x%i)
			continue;
		res=res/i*(i-1);
		while (x%i==0)
			x/=i;
	}

	if (x>1)
		res=(res/x*(x-1));
	return res;
}

long long g(long long x)
{
	return x;
}

long long n,k;

long long F(long long n,long long k)
{
//	cout<<n<<" "<<k<<endl;

	if (k==1)
		return f(g(n));
	if (n==1)
		return 1;
	if (k%2==0)
		return g(F(n,k-1));
	return f(F(n,k-1));
}

int main(){
//	freopen("explosion.in","r",stdin);
//	freopen("explosion.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	/*for (int i=1;i<=20;i++)
	{
		cout<<i<<" "<<f(i)<<" "<<g(i)<<endl;
	}*/

	pr[1]=1;
	for (int i=2;i<N;i++)
	{
		if (pr[i]==0)
		{
			for (int j=i*2;j<N;j+=i)
			{
				pr[j]=1;
			}
		}
	}

	for (int i=2;i<N;i++)
	{
		if (pr[i]==0)
			primes.push_back(i);
	}

//	while (true)
//	{
		cin>>n>>k;
		if (k>5000)
			k=5000;
		cout<<F(n,k)%bs<<endl;
	//}
	cin.get(); cin.get();
	return 0;
}