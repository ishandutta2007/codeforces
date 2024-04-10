#include<iostream>
using namespace std;
int l,r,a[123],b[123],n,m,c,t,z;

int main(){

	cin>>n;
	for(int i=0; i<n;i++){
		cin>>m;
		a[m]++;
	}
	cin>>m;
	for(int i=0; i<m;i++){
		cin>>n;
		b[n]++;
	}
	for (int i=1; i<=100; i++){
		if ( b[i-1]>=a[i] && a[i]>0   ) { b[i-1]-=a[i]; z+=a[i];   a[i]=0;   }
		if ( b[i-1]<a[i]  && b[i-1]>0 ) { a[i]-=b[i-1]; z+=b[i-1]; b[i-1]=0; }
		if ( b[i]>=a[i]   && a[i]>0   ) { b[i]-=a[i];   z+=a[i];   a[i]=0;   }
		if ( b[i]<a[i]    && b[i]>0   ) { a[i]-=b[i];   z+=b[i];   b[i]=0;   }
		if ( b[i+1]>=a[i] && a[i]>0   ) { b[i+1]-=a[i]; z+=a[i];   a[i]=0;   }
		if ( b[i+1]<a[i]  && b[i+1]>0 ) { a[i]-=b[i+1]; z+=b[i+1]; b[i+1]=0; }
		
	}
	cout<<z;
return 0;
}