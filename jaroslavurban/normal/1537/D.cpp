#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int win(int n){
	for(int i=2;i*i<=n;++i)
		if(n%i==0){
			if(!win(n-n/i)||!win(n-i))
				return true;
		}
	return false;
}

bool ProGamerMove(int n=0){
	cin>>n;
	int lg=log2(n);
	if(1<<lg==n){
		if(n==1||lg&1){
			cout<<"Bob\n";
			return false;
		}
		else{
			cout<<"Alice\n";
			return true;
		}
	}
	else if((n&1)||n==2){
		cout<<"Bob\n";
		return false;
	}
	else{
		cout<<"Alice\n";
		return true;
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}