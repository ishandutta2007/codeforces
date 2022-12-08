#include<bits/stdc++.h>
using namespace std;
typedef long double db;
typedef long long ll;
db ans;
const int N=1e6+5;
int n,m,k;
ll c[N];
int main()
{
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}sort(c+1,c+n+1);
	for(int i=n-1;i;i--){
		c[i]+=c[i+1];
	}
	for(int i=1;i<=n;i++){
		//cout<<c[i]<<endl;
		db tot=n-i+1;
		if(i-1>m)break;
		db rst=1.00/tot*(db)(min((ll)k*(n-i+1),(ll)(m-i+1)));
		ans=max(ans,(db)c[i]/tot+rst);
		//cout<<ans<<endl;
	}
	printf("%.10Lf\n",ans);
}