#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[666],b[666][666],res;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin>>s;
	for(auto i:s){
		i-='a'-1;
		for(j=1;j<=26;j++){
			b[j][i]+=a[j];
			res=max(res,b[j][i]);
		}
		a[i]++;
		res=max(res,a[i]);
	}
	cout<<res;
}