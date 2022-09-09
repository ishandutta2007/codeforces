#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn=40;

int a[maxn],b[maxn],c[maxn],k[maxn],p[maxn];
int n,u,r;
ll answer;

void calcans()
{
	ll ans=0;
	for (int i=0;i<n;i++) /*cout << a[i] << ' ',*/ans+=((ll)a[i])*k[i];
	answer=max(answer,ans);
}

void op1()
{
	for (int i=0;i<n;i++) a[i]^=b[i];
}

void op2()
{
	for (int i=0;i<n;i++) c[i]=a[i];
	for (int i=0;i<n;i++) a[i]=c[p[i]-1]+r;
}

void op3()
{
	for (int i=0;i<n;i++) c[i]=a[i]-r;
	for (int i=0;i<n;i++) a[p[i]-1]=c[i];
}

void go(int cur)
{
	if (cur<0) return;
	if ((cur&1)==0) calcans();
	if (cur==0) return;
	op1();
	if ((cur&1)==1) calcans();
	op2();
	go(cur-2);
	op3();
	op1();
	op2();
	go(cur-1);
	op3();
}

int main()
{
	cin >> n >> u >> r;
	for (int i=0;i<n;i++) cin >> a[i];
	for (int i=0;i<n;i++) cin >> b[i];
	for (int i=0;i<n;i++) cin >> k[i];
	for (int i=0;i<n;i++) cin >> p[i];
	answer=((ll)-1e9)*((ll)1e9);
	go(u);
	cout << answer << endl;
	return 0;
}