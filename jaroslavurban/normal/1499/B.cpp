#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s;
int n;

int onesr(int idx,int del){
	for(int i=idx;i<n;++i){
		if(s[i]=='0'&&del)return 0;
		del=s[i]=='0';
	}
	return true;
}

int zerol(int idx,int del){
	for(int i=idx;i>=0;--i){
		if(s[i]=='1'&&del)return 0;
		del=s[i]=='1';
	}
	return true;
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>s;
		n=s.size();
		int pos=false;
		for(int i=0;i<=n;++i){
			if((zerol(i-1,1)&&onesr(i,0))||(zerol(i-1,0)&&onesr(i,1))){
				pos=true;break;
			}
		}
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}