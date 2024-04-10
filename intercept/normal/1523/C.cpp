#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
int n;
int a[1009],vis[1009][2];
string s[1009];
int dfs(string t,int dep,int id){
	s[id]=t;
	int ans=2;
	while(1){
		while(a[id+1]==a[id]+1){
			s[id+1]=s[id];
			while(s[id+1].length()>=dep)s[id+1].pop_back();
			s[id+1]=s[id+1]+to_string(ans);
			id++,ans++;
		}
		if(a[id+1]==1&&id+1<=n){
			id=dfs(s[id]+".1",s[id].length()+2,id+1);
			if(a[id]==ans){
				s[id]=t;
				while(s[id].length()>=dep)s[id].pop_back();
				s[id]=s[id]+to_string(ans);
				ans++;
			}
			else return id;
		}
		else break;
	}
	return id+1;
}
void work(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	s[1]="1";
	dfs("1",1,1);
	for(int i=1;i<=n;++i)cout<<s[i]<<endl;
	for(int i=1;i<=n;++i)a[i]=0,s[i]="";
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
/*
1
13
1
1
2
3
4
5
6
7
8
9
10
1
2

*/