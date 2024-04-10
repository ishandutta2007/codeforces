#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll fl[10050],fr[10050],a[10050],res,sb,t1,t2,mn[10050],lst;

void work(){
	for(i=1;i<=n;i++){
		int l=i,r=i;
		while(a[l-1]>=a[i])l--;
		while(a[r+1]>=a[i])r++;
		mn[r]=1e18;
		lst=0;
		for(j=r+1;j<=n;j++)mn[j]=min(mn[j-1],a[j]);
		j=l;k=n;
		t1=a[i];
		while(j!=1){
			j--;t1=min(t1,a[j]);
			while(k!=r){
				if(mn[k]+t1<a[i]){
					lst=max(lst,(k-l+1)*mn[k]);
					res=max(res,(r-j+1)*t1+lst);
					k--;
				}
				else break;
			}
			res=max(res,(r-j+1)*t1+lst);
			if(k!=r)res=max(res,(r-j+1)*t1+(k-l+1)*(a[i]-t1));
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	a[0]=a[n+1]=-1;
	mn[n+1]=1e18;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++){
		sb=a[i];
		for(j=i;j>=1;j--){
			sb=min(sb,a[j]);
			fl[i]=max(fl[i],sb*(i-j+1));
		}
		fl[i]=max(fl[i],fl[i-1]);
	}
	for(i=n;i>=1;i--){
		sb=a[i];
		for(j=i;j<=n;j++){
			sb=min(sb,a[j]);
			fr[i]=max(fr[i],sb*(j-i+1));
		}
		fr[i]=max(fr[i],fr[i+1]);
	} 
	for(i=0;i<=n;i++)res=max(res,fl[i]+fr[i+1]);
	for(i=1;i<=n;i++){
		int l=i,r=i;
		while(a[l-1]>=a[i])l--;
		while(a[r+1]>=a[i])r++;
		j=l;k=r;sb=1e18;t=0;
		while(j!=1||k!=n){
			if(a[j-1]>a[k+1])j--;
			else k++;
			t++;
			sb=min({sb,a[j],a[k]});
			res=max(res,sb*t+(r-l+1)*a[i]);
		}
	}
	work();reverse(a+1,a+n+1);work();
	cout<<res;
}