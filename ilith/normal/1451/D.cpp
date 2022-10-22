#include<bits/stdc++.h>
using namespace std;
signed main(){
	int t;
	cin>>t;
	while(t--) {
		long long d,k;
		cin>>d>>k;
		long long d1,d2;
		for(d1=0;2ll*d1*d1<=d*d;d1+=k);
		for(d2=0;d2*d2+(d2+k)*(d2+k)<=d*d;d2+=k);
		puts(d2>=d1?"Ashish":"Utkarsh");
	}
	return 0;
}