#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l=1,r,res[200500],sb;
ll a[200500];
char s[200500];
int main(){
	cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cin>>s+1;
	for(i=1;i<=n;i++){
		if(s[i]==s[i-1])res[i]=--l;
		else res[i]=++r;
	}
	k=((s[1]=='L')^((res[1]-(l-1))&1));
	if(s[1]=='L'&&k)sb=1;
	if(s[1]=='R'&&!k)sb=1;
	for(i=1;i<=n;i++){
		res[i]-=l-1;
		cout<<a[res[i]]<<(((s[1]=='L')^(res[i]&1)^sb)?" R":" L")<<'\n';
	}
}