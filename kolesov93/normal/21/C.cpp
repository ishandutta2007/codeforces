#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#include <deque>
#include <string>
#include <string.h>
#include <memory.h>
#include <math.h>
#define N 111111
int n,m;
long long a[N],l[N],r[N],f[N],ans=0,s;
int kol[N];

int main(void) {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%I64d",&a[i]);
		l[i] = a[i]+l[i-1];
		s += a[i];
	}
	if (s % 3 != 0) {
		puts("0");
		return 0;
	}
	s /= 3;
	
	for (int i=n;i;i--) { 
		r[i] = a[i]+r[i+1];
		if (r[i] == s) {
			kol[i] = 1;
			
		}
		kol[i] += kol[i+1];
	}
	
	for (int i=1;i<=n;i++)
		if (l[i] == s) 
			ans += kol[i+2];
		
	
	
	printf("%I64d\n",ans);
	
	return 0;
}