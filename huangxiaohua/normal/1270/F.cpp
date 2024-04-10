#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,mp[101005000],tmp[200500],it;
ll res,a[200500],l,r,sb,sb1;
char s[200500];

int main(){
	gets(s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++){
		s[i]-='0';
		a[i]=a[i-1]+s[i];
	}
	for(i=1;i<=500;i++){
		mp[n]=1;
		for(j=1;j<=n;j++){
			res+=mp[i*a[j]-j+n];
			mp[i*a[j]-j+n]++;
			tmp[++it]=i*a[j]-j+n;
		}
		while(it){mp[tmp[it]]=0;it--;}
	}
	for(i=1;i<=400;i++){
		l=r=1;
		for(j=0;j<=n;j++){
			while(l<=n&&a[l]-a[j]<i){l++;}
			while(r<=n&&a[r]-a[j]<=i){r++;}
			sb1=(l-1-j)/i;
			if(sb1<500){sb1=500;}
			sb=(r-1-j)/i-sb1;
			if(sb>0){res+=sb;}
		}
	}
	printf("%lld",res);
}