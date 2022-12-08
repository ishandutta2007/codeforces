#include<bits/stdc++.h>
using namespace std;
int n;
const int N=4e5+5;
typedef long long ll;
ll c[N],t[N];
ll c2[N],t2[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&t[i]);
	if(c[1]!=t[1]||c[n]!=t[n]){
		puts("No");
		return 0;
	}
	for(int i=1;i<n;i++)c2[i]=fabs(c[i]-c[i+1]),t2[i]=fabs(t[i]-t[i+1]);
	sort(c2+1,c2+n);
	sort(t2+1,t2+n);
	for(int i=1;i<n;i++){
		if(c2[i]!=t2[i]){
			printf("No");
			return 0;
		}
	}
	printf("Yes\n");
}