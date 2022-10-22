#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m; ll a[110];
char s[64];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++){
			scanf("%s",s); a[i]=0;
			for (int j=0;j<m;j++) a[i]=((a[i]<<1)|(s[j]-'0'));
			// cerr<<a[i]<<endl;
		}
		sort(a+1,a+n+1);
		ll k=(((1ll<<m)-n-1)>>1); //cerr<<k<<endl;
		for (int i=1;i<=n;i++)
			if (a[i]<=k) k++;
		// puts("Ans:"); cerr<<k<<endl;
		for (int j=m-1;j>=0;j--) putchar(((k>>j)&1)+'0'); putchar('\n');
	}
	return 0;
}