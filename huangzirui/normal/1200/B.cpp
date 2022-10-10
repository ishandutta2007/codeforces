#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll i,j,k,n,m;
void read(int &x){
	char c;x=0;do c=getchar();while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);
}
void read(ll &x){
	char c;x=0;do c=getchar();while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);
}
ll a[110];
int main() {
    int t;
	cin>>t;
	while(t--){
		read(n);read(m);read(k);
		for(i=1;i<=n;i++)
			scanf("%I64d",&a[i]);
		if(n==1){puts("YES");continue;}
		for(i=1;i<n;i++){
			ll need=a[i+1]-k;
			need=max(need,0ll);
			m+=a[i];
			m-=need;
			if(m<0){
				puts("NO");
				break;
			}
			if(i==n-1)
				puts("YES");
		}
	}
    //cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
    return 0;
}