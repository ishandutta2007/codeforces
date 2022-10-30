#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,a[500500];
map<int,int> mp;

void get(int l,int r){
	if(l>r){return;}
	int i,j,k,mx,md=(l+r)/2;
	
	mp.clear();mx=0;i=md;j=md+1;
	for(;j<=r;j++){
		mx=max(mx,a[j]);
		for(;i>=l;i--){
			if(a[i]<mx){mp[a[i]]=1;}
			else{break;}
		}
		res+=mp[mx-a[j]];
	}
	
	mp.clear();mx=0;i=md;j=md+1;
	for(;i>=l;i--){
		mx=max(mx,a[i]);
		for(;j<=r;j++){
			if(a[j]<mx){mp[a[j]]=1;}
			else{break;}
		}
		res+=mp[mx-a[i]];
	}
	if(l==r){return;}
	get(l,md);get(md+1,r);
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	get(1,n);
	printf("%d",res);
}