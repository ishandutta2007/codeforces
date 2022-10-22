#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
#define infty 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
//head

const int maxn=1000000;

char s[maxn+5];

int main()
{
	int n; scanf("%d",&n);
	scanf("%s",s+1);
	int ans=0,sum=0;
	rep(i,1,n)
	{
		sum+=s[i]=='('?1:-1;
		if(sum<0 && s[i]==')') ans++;
	}
	printf("%d\n",sum==0?ans*2:-1);
	return 0;
}