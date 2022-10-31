#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<vector>
#define f first 
#define s second 
#define mp make_pair 
#define ll long long
#define pii pair<int,int>

using namespace std;


int n;
ll A,x,y,m,b[333333],s[333333];
pii a[333333];


bool ok(int M,int k) {
	pii P = mp(M,-1);
	int p = lower_bound(a + 1,a + n + 1,P) - a - 1;
	p = min(p,n - k);
	return (1ll*p*M - s[p] + A*k - s[n] + s[n - k] <= m);
}


int main(){
//        freopen("input","r",stdin);
  //      freopen("output","w",stdout);

        scanf("%d%I64d%I64d%I64d%I64d",&n,&A,&x,&y,&m);
        for(int i = 1;i <= n;i++) {
        	scanf("%d",&a[i].f);	
        	a[i].s = i;
        }

        sort(a + 1,a + n + 1);
        for(int i = 1;i <= n;i++) {
        	s[i] = s[i - 1] + a[i].f;
        	b[a[i].s] = a[i].f;
        }

        if(n*A - s[n] <= m) {
        	printf("%I64d\n",n*x + A*y);
        	for(int i = 1;i <= n;i++)
        		printf("%I64d ",A);
        	return 0;
        }

        ll Max = -1,cnt = 0,Min = 0;


        for(int k = 0;k < n;k++) {
        	if(m < A*k - s[n] + s[n - k]) break;
        	int l = 0,r = A + 1,M;
        	while(r > l + 1) {
        		M = (l + r)/2;
        		if(ok(M,k)) l = M;
        		else r = M;
        	}
        	if(k*x + l*y > Max) {
        		Max = k*x + l*y;
        		cnt = k;
        		Min = l;
        	}
        }

        printf("%I64d\n",Max);

        pii P = mp(Min,-1);
	int p = lower_bound(a + 1,a + n + 1,P) - a - 1;
	p = min(1LL*p,n - cnt);

	for(int i = n - cnt + 1;i <= n;i++)
		b[a[i].s] = A;
	for(int i = 1;i <= p;i++)
		b[a[i].s] = Min;

	for(int i = 1;i <= n;i++)
		printf("%I64d ",b[i]);

	return 0;
}