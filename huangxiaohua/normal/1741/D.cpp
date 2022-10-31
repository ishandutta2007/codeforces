#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,a[1000005];

#define md ((l+r)/2)
void fuck(int l,int r){
	if(l==r)return;
	if(res==-1)return;
	int mxl,mxr,mnl,mnr;
	mxl=mnl=a[l];
	mxr=mnr=a[r];
	for(i=l;i<=md;i++){
		mxl=max(mxl,a[i]);
		mnl=min(mnl,a[i]);
	}
	for(i=md+1;i<=r;i++){
		mxr=max(mxr,a[i]);
		mnr=min(mnr,a[i]);
	}
	if(mnl<mxr){
		if(mxl>mnr)res=-1;
		else res+=0;
	}
	else if(mnl>mxr){
		if(mxl<mnr)res=-1;
		else res+=1;
	}
	fuck(l,md);fuck(md+1,r);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		res=0;
		fuck(1,n);
		cout<<res<<'\n';
	}
}