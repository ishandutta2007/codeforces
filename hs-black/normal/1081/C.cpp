#include<bits/stdc++.h>
using namespace std;
long long jie[2001],ni[2001],max1=2000,mod=998244353,n,k,m;
long long cheng(long long x,long long y){//
	return (x*y)%mod;
}
long long kuai(int k,int x){//
	long long s=1;
	for(;x;k=cheng(k,k),x=x>>1){
		if(x&1){
			s=cheng(s,k);
		}
	}
	return s;
}
void work(){//
	jie[0]=ni[0]=1;
	for(int i=1;i<=max1;i++){//
		jie[i]=cheng(jie[i-1],i);
	}
	ni[max1]=kuai(jie[max1],mod-2);//
	for(int i=max1-1;i>=1;i--){//
		ni[i]=cheng(ni[i+1],i+1);
	}
}
long long C1(long long a,long long b){//
	return cheng(jie[a],cheng(ni[b],ni[a-b]));
}
int main(){
	cin>>n>>m>>k;
	work();
	cout<<cheng(C1(n-1,k),cheng(kuai(m-1,k),m));//
	return 0;
}