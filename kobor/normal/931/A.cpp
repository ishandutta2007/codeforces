#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, wyn=0;
	cin>>a>>b;
	if(a>b){
		swap(a, b);
	}
	if(abs(a-b)%2==0){
		cout<<abs(a-b)/2*(abs(a-b)/2+1)<<'\n';
	}
	else{
		a++;
		wyn++;
		wyn+=abs(a-b)/2*(abs(a-b)/2+1);
		wyn+=abs(a-b)/2;
		cout<<wyn<<'\n';
	}
	return 0;
}