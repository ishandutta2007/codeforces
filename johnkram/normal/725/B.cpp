#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define MAXN 200005
#define gc getchar()
ll n,ans;
char c;
int main()
{
	for(c=gc;c<'0'||c>'9';c=gc);
	for(n=c^'0',c=gc;c>='0'&&c<='9';c=gc)n=(n<<3)+(n<<1)+(c^'0');
	if(!(n&3)||(n&3)==3)n-=2;
	ans=n/2*6+n-1;
	if(c>'c')ans+='g'-c;
	else ans+=c-'a'+4;
	cout<<ans<<endl;
	return 0;
}