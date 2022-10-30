#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,a[100500],res=1,b[100500];

#define N 500

void fuck(int l,int r){
	int i,j,k;
	int d;
	for(i=l+1;i<=r;i++){
		d=a[i]-a[l];
		//printf("NMSL%d %d %d %d\n",l,r,i,d);
		if(d%(i-l))continue;
		d/=(i-l);
		k=0;
		for(j=l;j<=r;j++){
			if(a[j]== (a[l]+d*(j-l)) )k++;
		}
		res=max(res,k);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	//n=100000;
	for(i=1;i<=n;i++){
		cin>>a[i];
		//a[i]=i;
	}
	for(t=-N;t<=N;t++){
		//cout<<t<<endl;
		for(i=1;i<=n;i++){
			b[i]=a[i]-i*t;
		}
		sort(b+1,b+n+1);
		k=1;
		for(i=2;i<=n;i++){
			if(b[i]==b[i-1])k++;
			else k=1;
			res=max(res,k);
		}
	}
	for(i=1;i<=n;i++){
		fuck(i,min(i+100000/N,n));
	}
	cout<<n-res;
}//