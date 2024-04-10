#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,f[300500],a[300500],M,b[300500];
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}
ll sb;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>t>>M;
	f[1]=f[2]=1%M;
	for(i=3;i<=300005;i++)f[i]=su(f[i-1],f[i-2]);
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		cin>>k;a[i]=su(a[i],M-k);
	}
	b[1]=a[1];b[2]=su(a[2],M-a[1]);
	for(i=3;i<=n;i++){
		b[i]=a[i];
		b[i]=su(b[i],M-a[i-1]);
		b[i]=su(b[i],M-a[i-2]);
	}
	b[n+1]=b[n+2]=0;
	for(i=1;i<=n;i++)sb+=b[i];
	while(t--){
		string op;int l,r;
		cin>>op>>l>>r;
		sb-=b[l];sb-=b[r+1];sb-=b[r+2];
		if(op=="A"){
			b[l]=su(b[l],f[1]);
			if(r+1<=n)b[r+1]=su(b[r+1],M-f[r-l+2]);
			if(r+2<=n)b[r+2]=su(b[r+2],M-f[r-l+1]);
		}
		else{
			b[l]=su(b[l],M-f[1]);
			if(r+1<=n)b[r+1]=su(b[r+1],f[r-l+2]);
			if(r+2<=n)b[r+2]=su(b[r+2],f[r-l+1]);
		}
		sb+=b[l];sb+=b[r+1];sb+=b[r+2];
		assert(!b[n+1]&&!b[n+2]);
		cout<<((sb)?"NO\n":"YES\n");
	}
}//