#include<bits/stdc++.h>
using namespace std;
int T,n,k,tot,fl,j,l,i,a[1000005];
int ask(int l,int r){
	cout<<"? "<<l<<" "<<r<<'\n';cout.flush(); 
	int tot=0,cnt=0;
	for(int i=l;i<=r;++i){
		cin>>a[++tot];
		if(a[tot]>r||a[tot]<l)++cnt;
	}
	return (r-l+1-cnt)&1;
}
void solve(int l,int r){
	if(l==r){
		cout<<"! "<<l<<"\n";cout.flush();return ;
	}
	int mid=(l+r>>1);
	int fl=ask(l,mid);
	if(fl)return solve(l,mid);
	else return solve(mid+1,r);
}
int t;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		solve(1,n);
	}
}