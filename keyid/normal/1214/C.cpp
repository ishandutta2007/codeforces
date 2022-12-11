#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

const int MAXN=200005;

char s[MAXN];

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n;
	scanf("%d%s",&n,s);
	int sum=0;
	for (int i=0;i<n;i++)
		sum+=(s[i]=='('?1:-1);
	if (sum!=0)
		printf("NO");
	else
	{
		sum=0;
		bool fir=false;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='(')
				sum++;
			else if (fir)
				sum--;
			else
				fir=true;
			if (sum<0)
			{
				printf("NO");
				return 0;
			}
		}
		printf("YES");
	}
	
	return 0;
}