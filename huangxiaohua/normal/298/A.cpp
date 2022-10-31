#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y;

int main(){
	ios::sync_with_stdio(0);
	string s;
	int l=0,r=0;
	cin>>n>>s;
	s="X"+s;
	for(i=1;i<=n;i++){
		if(s[i]=='L'){
			l++;
			if(!x)x=i;
			y=i;
		}
		if(s[i]=='R'){
			r++;
			if(!x)x=i;
			y=i;
		}
	}
	if(!r){
		cout<<y<<' '<<x-1;
		return 0;
	}
	if(!l){
		cout<<x<<' '<<y+1;
		return 0;
	}
	cout<<y;
	for(i=1;i<=n;i++){
		if(s[i]=='L'){
			cout<<' '<<i;return 0;
		}
	}
}