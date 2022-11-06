#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],l[N],n;
int a1[N],l1[N];
int f[N][3*N],r[N],t,z[3*N];
int ans;
map<int,int> p,q;
bool comp(int x,int y){
	return a[x]<a[y];
}
void cmax(int &x,int y){
	x=x>y?x:y;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&l[i]),p[a[i]]=p[a[i]-l[i]]=p[a[i]+l[i]]=1;
	for (auto x:p)q[x.first]=++t,z[t]=x.first;
	for (int i=1;i<=n;i++)r[i]=i;
	sort(r+1,r+n+1,comp);
	for (int i=1;i<=n;i++)a1[i]=a[r[i]],l1[i]=l[r[i]];
	memcpy(a,a1,sizeof a);
	memcpy(l,l1,sizeof l);
	for (int i=0;i<=n;i++){
		for (int j=1;j<=t;j++){
			int far=z[j];
			for (int p=i+1;p<=n;p++){
				int f1=max(far,a[p]);
				cmax(f[p][q[f1]],f[i][j]+(f1-max(z[j],a[p]-l[p])));
				far=max(far,a[p]+l[p]);
				cmax(f[p][q[a[p]+l[p]]],f[i][j]+(a[p]+l[p]-max(z[j],a[p])));
			}
			ans=max(ans,f[i][j]);
		}
	}
	cout<<ans<<endl;
}