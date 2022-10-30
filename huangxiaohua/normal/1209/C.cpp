#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,mx;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s;
		s="X"+s;
		for(auto &i:s){i-='0';}
		for(i=0;i<=9;i++){
			string res(n,'X');
			mx=i;
			for(j=n;j>=1;j--){
				if(s[j]>i)continue;
				if(s[j]>mx){
					if(s[j]>=i)continue;
					goto aaa;
				}
				res[j-1]='1';
				mx=s[j];
			}
			mx=i;
			//cout<<res<<endl;
			for(j=1;j<=n;j++){
				if(res[j-1]=='1')continue;
				if(s[j]<mx){
					goto aaa;
				}
				res[j-1]='2';
				mx=s[j];
			}
			cout<<res<<'\n';
			goto bbb;
			aaa:;
		}
		cout<<"-\n";
		bbb:;
	}
}