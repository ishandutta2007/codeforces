#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
int main(){
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#else
		cin.tie(0);
		cin.sync_with_stdio(0);
	#endif
	string s="codeforces";
	ll k;
	cin>>k;
	ll cur=1;
	if(k==1){cout<<s;return 0;}
	for(int i=2;1;i++){
		for(int j=0;j<10;j++){
			cur/=i-1;
			cur*=i;
			if(cur>=k){
				for(int l=0;l<10;l++){
					for(int m=0;m<i-(l>j);m++)printf("%c",s[l]);
				}
				return 0;
			}
		}
	}
}