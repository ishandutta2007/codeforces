#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

int hh,mm,h,d,c,n;
double ans;

inline int ch(int a,int b)
{
	if(a%b==0) return a/b;
	return a/b+1;
}

int main()
{
	cin>>hh>>mm>>h>>d>>c>>n;
	ans=ch(h,n)*c;
	int lef=20*60-hh*60-mm;
	if(lef<0) lef=0;
	int hung=h+lef*d;
	if(hung%n==0) hung/=n;
	else hung=hung/n+1;
	hung*=c; ans=min(ans,hung*0.8);
	cout<<ans<<endl;
	return 0;
}