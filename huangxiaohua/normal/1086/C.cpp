#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,u[205],a[205],yes;
char s1[1005000],s2[1005000],s3[1005000];

void dfs(int x,int y,int z){
	//printf("a%d %d %d\n",x,y,z);
	int i,j,k;
	if(!y&&!z){
		cout<<"YES"<<'\n';
		for(i='a';i<='a'+m-1;i++){
			if(a[i]){continue;}
			for(j='a';j<='a'+m-1;j++){
				if(!u[j]){a[i]=j;u[j]=1;break;}
			}
		}
		for(i=0;i<m;i++){
			cout<<(char)a['a'+i];
		}
		cout<<'\n';yes=1;return;
	}
	if(x>n){
		cout<<"YES"<<'\n';
		for(i='a';i<='a'+m-1;i++){
			if(a[i]){continue;}
			for(j='a';j<='a'+m-1;j++){
				if(!u[j]){a[i]=j;u[j]=1;break;}
			}
		}
		for(i=0;i<m;i++){
			cout<<(char)a['a'+i];
		}
		cout<<'\n';yes=1;return;
	}
	if(a[s1[x]]){
		//puts("nmsl");
		if(y&&a[s1[x]]<s2[x]){
			return;
		}
		if(z&&a[s1[x]]>s3[x]){
			return;
		}
		dfs(x+1,y&(a[s1[x]]==s2[x]),z&(a[s1[x]]==s3[x]));
		return;
	}
	
	for(i='a';i<='a'+m-1;i++){
		if(u[i]){continue;}
		if(y&&i<s2[x]){
			continue;
		}
		if(z&&i>s3[x]){
			continue;
		}
		//printf("b%d %c %c\n",x,s1[x],i);
		a[s1[x]]=i;u[i]=1;
		dfs(x+1,y&(a[s1[x]]==s2[x]),z&(a[s1[x]]==s3[x]));
		if(yes){return;}
		a[s1[x]]=0;u[i]=0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		yes=0;
		cin>>m>>s1+1>>s2+1>>s3+1;
		n=strlen(s1+1);
		memset(u,0,sizeof(u));
		memset(a,0,sizeof(a));
		dfs(1,1,1);
		if(!yes){
			cout<<"NO"<<'\n';
		}
	}
	
}