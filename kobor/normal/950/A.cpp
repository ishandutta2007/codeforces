#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int l, r, a;
	cin>>l>>r>>a;
	if(l>r){
		swap(l, r);
	}
	while(a&&l<r){
		a--;
		l++;
	}
	if(l<r){
		cout<<l*2<<'\n';
		return 0;
	}
	l+=a/2;
	r+=a/2;
	cout<<l+r<<'\n';
	return 0;
}