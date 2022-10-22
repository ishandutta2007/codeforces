#include <bits/stdc++.h>
using namespace std;
#define int long long
int m = 1e9 + 7;
int get(int x){
	if (x == 0){
		return 0;
	}
	int k = 0,a=0;
	while(  (k + 1) * 2 -1 <= x ){
		k = (k + 1)*2 -1;
		a++;
	}
	int kol = 1;
	int ans = 1,tmp=1;
	for(int i=1;i<a;i++){
		kol = 3 - kol;
		if (kol == 2){
			tmp = (tmp * 2 + 1);
		}
		else{
				tmp = (tmp * 2 );
		}
		tmp %= m;
		ans = (ans + tmp * ((2ll <<(i - 1) )%m)) % m;
	}
	int z = x - k;
	a++;
	if(a%2==1){
		int b =a/2;
		int t = 1,t1=0;
		while(b--){
			t1 = (t+t1);
			t *= 4;
			t%=m;
			t1%=m;
		}
		z %= m;
		z+=m;
		
		int v = 1 + t1 * 2;
		v %= m;
		v+=m;
		return ((ans + v * z + (z)*(z-1))%m);
		
	}
	else{
		int b = a/2-1;
		int t = 2,t1=0;
		while(b--){
			t1 = (t+t1);
			t *= 4;
			t%=m;
			t1%=m;
		}
		
		z %= m;
		z+=m;
		int v = 2 + t1 * 2;
		v %= m;
		v+=m;
		return (ans + v * z + (z)*(z-1))%m;
	}
	
	
}
signed main() {
	int a,b;
	cin >> a >> b;
	cout << (get(b) - get(a - 1) + m*4)%m;
	
}