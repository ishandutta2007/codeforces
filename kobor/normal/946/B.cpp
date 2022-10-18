#include <bits/stdc++.h>

using namespace std;

void sito(long long a, long long b){
	if(!a||!b){
		cout<<a<<' '<<b;
		return;
	}
	while(a&&b&&((a>=2*b)||(b>=2*a))){
		if(!a||!b){
			cout<<a<<' '<<b;
			return;
		}
		if(a>=2*b){
			a=a%(2*b);
		}
		if(!a||!b){
			cout<<a<<' '<<b;
			return;
		}
		if(b>=2*a){
			b=b%(2*a);
		}
	}
	cout<<a<<' '<<b;
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, b;
	cin>>a>>b;
	sito(a, b);
	cout<<'\n';
	return 0;
}