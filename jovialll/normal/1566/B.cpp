#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define pb push_back
#define mod 998244353
#define pn cout<<"No\n"
#define py cout<<"Yes\n"

vector<int>son[N];
int T,n,a[N],l,cnt,i,j,x,y,z,k,c[N];
char s[N];
int main(){
	cin>>T;
	while(T--){
		scanf("%s",s+1);
		l=strlen(s+1);
		s[l+1]='1';cnt=0;
		for(i=1;i<=l;++i){
			if(s[i]=='0'&&s[i+1]=='1')++cnt;
		}
		cout<<min(cnt,2)<<'\n';
	}
}