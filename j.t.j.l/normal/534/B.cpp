#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int a[MAXN];

int main(){
	int v1,v2,t,d;
	cin>>v1>>v2>>t>>d;
	a[1] = v1;
	for(int i = 2; i <= t; i++){
		a[i] = a[i-1] + d;
	}
	int now = v2;
	for(int i = t; i; i--){
		if (now < a[i]){
			a[i] = now;
			now += d;
		}
		else
			break;
	}
	long long ans  = 0;
	for(int i = 1; i <= t; i++)
		ans += a[i];
	cout<<ans<<endl;
	return 0;
}