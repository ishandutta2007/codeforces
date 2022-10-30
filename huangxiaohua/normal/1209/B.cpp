#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,x[2005],y[2005];
bitset<105> b;

int main() {
	//ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){scanf("%1d",&k);b[i]=k;}
	for(i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	k=0;
	for(t=1;t<=100000;t++){
		k=max(k,(int)b.count());
		for(j=1;j<=n;j++){
			if(t>=y[j]&&!((t-y[j])%x[j]))b[j]=(b[j]^1);
		}
	}
	cout<<k;
}