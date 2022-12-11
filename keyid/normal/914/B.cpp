#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

const int MAX=100005;

int cnt[MAX];

int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	bool flag=false;
	for (int i=1;i<=100000;i++)
		if (cnt[i]&1)
		{
			flag=true;
			break;
		}
	printf(flag?"Conan":"Agasa");
	return 0;
}