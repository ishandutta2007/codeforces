#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int x[150010],y[150010],size,n,m,h,ans,z[150010],b[150010],a[150010];
int compare(int k1,int k2){
	return x[k1]>x[k2];
}
int main(){
	scanf("%d%d%d",&n,&m,&h); size=trunc(sqrt(n));
	for (int i=1;i<=m;i++) scanf("%d",&y[i]);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	sort(y+1,y+m+1); for (int i=1;i<=n;i++) a[i]=i; sort(a+1,a+n+1,compare);
	//for (int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
	int l=0,r=0;
	while (r<n-m+1){
		l=r+1; r=min(r+size,n-m+1); int now=1,flag=0,len=0;
		//cout<<l<<" "<<r<<endl;
		for (int i=1;i<=n;i++)
			if (a[i]>=r&&a[i]<=l+m-1){
				while (now<=m&&x[a[i]]+y[now]<h) {b[++len]=y[now]; now++;} //cout<<a[i]<<" "<<now<<" "<<m<<endl;
				if (now>m){flag=1; break;} now++;
			}
		if (flag) continue; 
		for (int i=now;i<=m;i++) b[++len]=y[i];
		//for (int i=1;i<=len;i++) cout<<b[i]<<" "; cout<<endl; 
		len=0;
		for (int i=l;i<r;i++) z[++len]=i;
		for (int i=max(l+m,r);i<=r+m-1;i++) z[++len]=i;
		sort(z+1,z+len+1,compare);
		//for (int i=1;i<=len;i++) cout<<z[i]<<" "; cout<<endl;
		for (int i=l;i<=r;i++){
			now=1; flag=0;
			for (int j=1;j<=len;j++)
				if (z[j]>=i&&z[j]<=i+m-1){
					if (b[now]+x[z[j]]>=h) now++; else {flag=1; break;}
				}
			if (flag==0) ans++;// cout<<i<<" "<<flag<<endl;
		} //cout<<endl;
	}
	cout<<ans<<endl; return 0;
}