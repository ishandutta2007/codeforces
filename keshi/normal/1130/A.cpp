#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,a,x=0,y=0;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a;
		if (a>0) x++;
		if (a<0) y++;
	}
	if (x*2>=n){
		cout << 1;
	}
	else if (y*2>=n){
		cout << -1;
	}
	else{
		cout << 0;
	}
	return 0;
}