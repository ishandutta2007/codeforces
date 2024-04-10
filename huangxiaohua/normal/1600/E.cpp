#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,l[200500],r[200500],a[200500],it,lst=-1;

void ans(int x){
	cout<<((x)?"Alice":"Bob");
	exit(0);
}

int main() {
	cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	j=-1;
	for(i=1;i<=n;i++){
		k++;
		if(a[i]<j)r[i]=k;
		else r[i]=k=1;
		j=a[i];
	}
	j=-1;k=0;
	for(i=n;i>=1;i--){
		k++;
		if(a[i]<j)l[i]=k;
		else l[i]=k=1;
		j=a[i];
	}
	j=1;k=n;
	while(j<=k){
		it^=1;
		if(a[j]<=lst&&a[k]<=lst)ans(it^1);
		if(a[j]>a[k]){
			if(l[j]&1)ans(it);
			if(a[k]<=lst)ans(it^1);
			lst=a[k];k--;
			continue;
		}
		if(a[j]<a[k]){
			if(r[k]&1)ans(it);
			if(a[j]<=lst)ans(it^1);
			lst=a[j];j++;
			continue;
		}
		if((l[j]&1)||(r[k]&1)){
			ans(it);
		}
		ans(it^1);
	}
	return 1;
}