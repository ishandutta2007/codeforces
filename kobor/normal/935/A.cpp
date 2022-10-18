#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, wyn=0;
	cin>>n;
	for(int i=2; i<=n; i++){
		if(n%i==0){
			wyn++;
		}
	}
	cout<<wyn<<'\n';
	return 0;
}