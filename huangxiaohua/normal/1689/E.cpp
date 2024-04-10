#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,a[10050],sb,mx;
#define b(x) (1<<((x)-1))

bool chk(){
	int i,j,k,f[33]={0},cur=0;
	for(i=1;i<=n;i++)for(j=1;j<=30;j++)if(a[i]&b(j)){
		f[j]|=a[i];cur=f[j];
	}
	for(i=1;i<=30;i++)for(j=1;j<=30;j++)if(cur&f[j])cur|=f[j];
	for(i=1;i<=30;i++)if((cur&f[i])!=f[i])return 0;
	return 1;
}

void show(){
	cout<<res<<'\n';
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<'\n';
}

int main(void){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		mx=res=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			if(!a[i]){res++;a[i]++;continue;}
			sb=(-a[i]&a[i]);
			if(sb>mx)mx=sb;
		}
		if(chk())goto aaa;
		res++;
		for(i=1;i<=n;i++){
			if(a[i]==1)goto aa;
			a[i]--;if(chk()){goto aaa;}a[i]++;
			aa:;
			a[i]++;if(chk()){goto aaa;}a[i]--;
		}
		res++;
		for(i=1;i<=n;i++)if((-a[i]&a[i])==mx){a[i]--;break;}
		for(i=1;i<=n;i++)if((-a[i]&a[i])==mx){a[i]++;break;}
		aaa:;
		show();
	}
}