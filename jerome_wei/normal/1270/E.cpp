#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
long long x[N], y[N];
int n;

inline void check(){
	int b=0;
	for(int i=1;i<=n;i++){
		// cout << x[i] << " " << y[i] << endl;
		if((x[i]%2+2)%2==(y[i]%2+2)%2){
			b++;
		}
	}
	// cout << "----" << endl;
	if(b>0&&b<n){
		cout << b << endl;
		for(int i=1;i<=n;i++){
			if((x[i]%2+2)%2==(y[i]%2+2)%2){
				printf("%d ",i);
			}
		}
		puts("");
		exit(0);
	}
}

inline void transform(){
	for(int i=1;i<=n;i++){
		long long xx=x[i],yy=y[i];
		x[i]=(long long)floor((long double)(xx+yy)/2.00),y[i]=(long long)floor((long double)(xx-yy)/2.00);
	}
}

int main()
{
	cin >> n ;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	while(1){
		check();
		transform();
	}
}