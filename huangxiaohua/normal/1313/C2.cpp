#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it;
ll a[500500],res,sb,tmp,id,l[500500],r[500500],s[500500],lst;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	
	for(i=1;i<=n;i++)cin>>a[i];
	
	for(i=1;i<=n;i++){
		while(it&&a[s[it]]>=a[i]){
			tmp-=(s[it]-s[it-1])*a[s[it]];
			it--;
		}
		tmp+=a[i]*(i-s[it]);
		s[++it]=i;
		l[i]=tmp;
	}
	tmp=it=0;
	for(i=1;i<=n;i++){
		lst=i;
		while(it&&a[n+1-s[it]]>=a[n+1-i]){
			tmp-=(s[it]-s[it-1])*a[n+1-s[it]];
			it--;
		}
		tmp+=a[n+1-i]*(i-s[it]);
		s[++it]=i;
		r[n+1-i]=tmp;
	}
	for(i=1;i<=n;i++){
		//printf("NMSL%d %d %d\n",i,l[i],r[i]);
		l[i]+=r[i]-a[i];
		if(l[i]>res){
			res=l[i];id=i;
		}
	}
	for(i=id-1;i>=1;i--){
		a[i]=min(a[i],a[i+1]);
	}
	for(i=id+1;i<=n;i++){
		a[i]=min(a[i],a[i-1]);
	}
	for(i=1;i<=n;i++)cout<<a[i]<<' ';
}