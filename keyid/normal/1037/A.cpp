#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair <int,int> pii;

int main()
{
	//freopen("read.txt","r",stdin);
	int n;
	scanf("%d",&n);
	printf("%d",32-__builtin_clz(n));
	return 0;
}