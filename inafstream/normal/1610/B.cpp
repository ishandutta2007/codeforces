#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m;
int a[200005];

bool check(int x)
{
	vector<int> v1,v2;
	int i;
	
	rep(i,n) if(a[i]!=x) v1.push_back(a[i]);
	
	v2=v1;reverse(v2.begin(),v2.end());
	return v1==v2;
}

void solve()
{
	int i,j;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	if(check(a[1])){puts("YES");return;}
	if(check(a[n])){puts("YES");return;}

	i=1;j=n;
	while(i<j&&a[i]==a[j]) i++,j--;
	if(check(a[i])){puts("YES");return;}
	if(check(a[j])){puts("YES");return;}
	
	puts("NO");
}
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve(); 
	}
	return 0;
}