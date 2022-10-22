#include<bits/stdc++.h>
using namespace std;
int n,p1,p2;
int xorv[200010],cnt[200010];
inline void putans(int a1) {
	printf("! %d",a1);
	for(int i=2;i<=n;++i) cout<<' '<<(a1^xorv[i]);
	cout<<endl,fflush(stdout);
	exit(0);
}
signed main(){
	cin>>n;
	for(int i=2;i<=n;++i) {
		printf("XOR 1 %d\n",i),fflush(stdout);
		cin>>xorv[i];
		++cnt[xorv[i]];
	}
	if(cnt[0]>0) {
		for(int i=2;i<=n;++i) if(xorv[i]==0) {
			printf("OR 1 %d\n",i),fflush(stdout);
			cin>>p1;
			putans(p1);
		}
	}
	for(int i=1;i<n;++i) if(cnt[i]>1) {
		for(int j=1;j<=n;++j) if(xorv[j]==i) {
			if(!p1) p1=j; else p2=j;
		}
		printf("OR %d %d\n",p1,p2),fflush(stdout);
		cin>>p2;
		putans(xorv[p1]^p2);
	}
	for(int i=2;i<=n;++i) {
		if(xorv[i]==1) p1=i;
		if(xorv[i]==n-2) p2=i;
	}
	printf("AND 1 %d\n",p1),fflush(stdout);
	cin>>p1;
	printf("AND 1 %d\n",p2),fflush(stdout);
	cin>>p2;
	putans(p1^p2);
	return 0;
}