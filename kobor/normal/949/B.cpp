#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n, pos, lpos;
	int q;
	cin>>n>>q;
	for(int i=0; i<q; i++){
		cin>>pos;
		while(pos%2==0){
			lpos=pos/2+1;
			pos+=n-lpos+1;
			//cout<<pos<<'\n';
		}
		cout<<pos/2+1<<'\n';
	}
	return 0;
}