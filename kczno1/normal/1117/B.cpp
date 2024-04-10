#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y; 
} 
typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e5+5;
int a[N];

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	rep(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	int c=m/(k+1);
	cout<<(s64)a[n-1]*c+(s64)a[n]*(m-c);
}