#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int N = 100005;

int n, cnt[4];

long long ans;

char a[N], b[N];

int main()
{
	scanf("%d%s%s",&n,a+1,b+1);
	for(int i=1;i<=n;i++) {
		cnt[(b[i]=='1')*2+(a[i]=='1')]++;
	}
	for(int i=0;i<4;i++) {
		for(int j=i+1;j<4;j++) {
			int A = i/2*2+j%2, B = j/2*2+i%2;
			if((!!i) != (!!A) || (!!j) != (!!B)) {
				ans += 1ll * cnt[i] * cnt[j];
			}
		}
	}
	printf("%lld\n",ans);
}