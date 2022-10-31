#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,sb;
ll f[1050],p[1050],a[1050],su,lst[1050];

int main() {
	ios::sync_with_stdio(0);//cin.tie(0);
	f[1]=f[2]=1;
	p[1]=1;p[2]=2;
	for(i=3;;i++){
		f[i]=f[i-1]+f[i-2];
		p[i]=p[i-1]+f[i];
		if(p[i]>100000000000ll){
			m=i;
			break;
		}
	}
	cin>>t;
	while(t--){
		cin>>n;
		su=0;
		memset(lst,0,sizeof(lst));
		a[0]=-1;
		for(i=1;i<=n;i++){
			cin>>a[i];su+=a[i];
		}
		int it=0;
		for(i=1;i<=m;i++){
			if(su==p[i]){
				it=i;break;
			}
		}
		if(!it){
			cout<<"NO\n";continue;
		}
		for(i=it;i>=1;i--){
			int mx=0;
			for(j=1;j<=n;j++){
				if(lst[j]==i+1||a[j]<f[i])continue;
				if(a[mx]<=a[j])mx=j;
			}
			if(!mx){
				cout<<"NO\n";goto aaa;
			}
			a[mx]-=f[i];
			lst[mx]=i;
		}
		cout<<"YES\n";
		aaa:;
	}
}