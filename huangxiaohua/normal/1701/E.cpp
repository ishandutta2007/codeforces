#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,f[5050][5050],it,z[20050];
char s1[5050],s2[5050],s[20050];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>s1+1>>s2+1;
		for(i=1;i<=m;i++){
			it=0;
			for(j=i;j<=m;j++)s[it++]=s2[j];
			for(j=1;j<=n;j++)s[it++]=s1[j];
			s[it]=0;
			k=0;
			for(int i=1,l=0,r=0;i<it;++i){
				if(i<=r&&z[i-l]<r-i+1)z[i]=z[i-l];
				else{
					z[i]=max(0,r-i+1);
					while(i+z[i]<it&&s[z[i]]==s[i+z[i]])++z[i];
				}
				if(i+z[i]-1>r)l=i,r=i+z[i]-1;
			}
			for(j=1;j<=n;j++)f[j][i]=min(z[j+m-i],m-i+1);
		}
		res=n;
		for(i=1;i<=m;i++){
			if(s1[i]!=s2[i])break;
			res--;
		}
		int sb=0;
		for(i=1;i<=n;i++){
			if(sb<m&&s1[i]==s2[sb+1])sb++;
			for(j=0;j<=min(sb,m-1);j++)res=min(res,1+i+(i-j)+(n-i-f[i+1][j+1]));
		}
		if(sb!=m){cout<<-1<<endl;continue;}
		cout<<res<<'\n';
	}
}