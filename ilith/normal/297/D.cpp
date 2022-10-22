#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans;
string s[2010],s2[2010];
int a[1010][1010],x[1010][1010],y[1010][1010];
int ena,flg;
int main(){
	ios::sync_with_stdio(0); 
	cin>>n>>m>>k;
	for(int i=1;i<2*n;i++){
		cin>>s2[i];
	}
	if(m<n){
		for(int i=1;i<2*n;i++){
			for(int j=0;j<s2[i].size();j++){
				s[2*(j+1)-((i&1)^1)]+=s2[i][j];
			}
		}
		swap(m,n),flg=1;
	}
	else{
		for(int i=1;i<2*n;i++){
			s[i]=s2[i];
		}
	}
	for(int i=1;i<2*n;i++){
		if(i&1){
			for(int j=0;j<s[i].size();j++){
				x[i/2+1][j+1]=(s[i][j]=='E'?0:1);
				ena+=(s[i][j]=='E');
			}
		}
		else{
			for(int j=0;j<s[i].size();j++){
				y[i/2][j+1]=(s[i][j]=='E'?0:1);
				ena+=(s[i][j]=='E');
			}
		}
	}
	if(k==1){
		if(ena*4>=3*n*(m-1)+3*m*(n-1)){
			cout<<"YES"<<'\n';
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					cout<<"1 ";
				}
				cout<<'\n';
			}
		}
		else cout<<"NO";
		return 0;
	}
	cout<<"YES"<<'\n';
	for(int i=1;i<=n;i++){
		a[i][1]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			a[i][j]=a[i][j-1]^x[i][j-1];
		}
	}
	for(int i=2;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=m;j++){
			cnt+=a[i][j]^a[i-1][j]^y[i-1][j]^1;
		}
		if(cnt<m-cnt){
			for(int j=1;j<=m;j++){
				a[i][j]^=1;
			}
		}
	}
	if(!flg){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<a[i][j]+1<<' ';
			}
			cout<<'\n';
		}
	}
	else{
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cout<<a[j][i]+1<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}