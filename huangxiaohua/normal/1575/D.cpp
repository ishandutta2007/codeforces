#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,p[15];
unordered_set<int> st;
char sb[66];

void dfs(int s,int dep,int x){
	//cout<<s<<' '<<dep<<' '<<x<<endl;
	
	if(dep==0){
		if(s%25)return;
		st.insert(s);
		return;
	}
	
	if(sb[dep]=='X'){
		if(n>1&&dep==1&&!x)return;
		
		s+=x*p[n-dep];
		dfs(s,dep-1,x);
		return;
	}

	if(sb[dep]=='_'){
		for(int i=0;i<=9;i++){
			if(dep==1&&n>1&&!i)continue;
			dfs(s+p[n-dep]*i,dep-1,x);
		}
		return;
	}
	
	int i=sb[dep]-'0';
	if(n>1&&dep==1&&!i)return;

	dfs(s+p[n-dep]*i,dep-1,x);
	
	
}

int main(){
	p[0]=1;
	for(i=1;i<=9;i++){
		p[i]=p[i-1]*10;
	}
	
	ios::sync_with_stdio(0);
	cin>>sb+1;
	n=strlen(sb+1);
	int xx=0;
	for(i=1;i<=n;i++){
		if(sb[i]=='X')xx=1;
	}
	for(i=0;i<=9;i++){
		dfs(0,n,i);
		if(!xx)break;
	}
	cout<<st.size();
}