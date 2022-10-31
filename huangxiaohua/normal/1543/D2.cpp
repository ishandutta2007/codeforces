#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,t,n,m;
int len;
ll sb1[200500],sb2[200500];

void ask(int x){
	if(!x){cout<<0<<endl;return;}
	int i,j,k,res=0;
	ll it=1;
	j=x;
	for(i=1;i<=len;i++){
		k=x%m;x/=m;
		sb1[i]=k;
	}
	x=j-1;
	for(i=1;i<=len;i++){
		k=x%m;x/=m;
		sb2[i]=k;
	}
	for(i=1;i<=len;i++){
		if(j&1){
			res+=((-sb1[i]+sb2[i]+m)%m)*it;
		}
		else{
			res+=((sb1[i]-sb2[i]+m)%m)*it;
		}
		it*=m;
	}
	cout<<res<<endl;
}


int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		len=0;
		for(ll i=1;;i*=m){
			len++;if(i>=n){break;}
		}
		for(i=0;;i++){
			ask(i);
			cin>>j;
			if(j){goto aaa;}
		}
		return 1;
		aaa:;
	}
}