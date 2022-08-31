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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define ends adsfasfsdf

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int solve(int n)
{
	int res=1;
	for (int len=1;len<=n*2;len++)
	{
		for (int mask=0;mask<(1<<len);mask++)
		{
			int s1,s2;
			s1=s2=0;
			for (int i=0;i<len;i++)
				if (mask&(1<<i))
					s1++;
				else
					s2++;
		if (s1<=n&&s2<=n)
			++res;
		}
	}
	return res;
}

long long fact[1<<20],invf[1<<20];

long long pw(long long a,long long b)
{
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inv(long long x)
{
	return pw(x,bs-2);
}

long long C(long long n,long long m)
{
	long long res=fact[n];
	res*=invf[m];
	res%=bs;
	res*=invf[n-m];
	return res%bs;
}

int main(){
//freopen("center.in","r",stdin);
//freopen("center.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

fact[0]=1;
invf[0]=inv(fact[0]);

for (int i=1;i<=1000001;i++)
{
	fact[i]=fact[i-1]*i%bs;
	invf[i]=inv(fact[i]);
}
/*
for (int n=1;n<=10;n++)
{
	cout<<n<<" "<<solve(n)<<endl;
}
*/
int n;
cin>>n;

++n;
long long res=0;


for (int i=1;i<=n;i++)
{
	long long c=C(n,i);
	res+=c*c%bs;
	res%=bs;
}

cout<<res<<endl;

return 0;}