#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[666];
char s[20050];

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m>>s+1;
	for(i=1;i<=m;i++){
		f['0']=f['1']=0;
		for(j=i;j<=n;j+=m){
			f[s[j]]=1;
		}
		for(j=i;j<=n;j+=m){
			if(s[j]!='.')continue;
			if(!f['0']){
				s[j]='0';
				f['0']=1;
				continue;
			}
			if(!f['1']){
				s[j]='1';
				f['1']=1;
				continue;
			}
			s[j]='0';
		}
	}
	for(i=1;i<=m;i++){
		f['0']=f['1']=0;
		for(j=i;j<=n;j+=m){
			f[s[j]]=1;
		}
		if(f['0']&&f['1']){
			cout<<s+1;
			return 0;
		}
	}
	cout<<"No";
}