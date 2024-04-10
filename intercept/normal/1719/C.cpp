#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n,q;
int a[M],p[M],s[M],la[M];
void work(){
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[i]=max(p[i-1],a[i]);
	}
	int top=0;
	for(int i=n;i>=1;--i){
		while(top&&a[s[top]]<a[i])top--;
		if(top)la[i]=s[top]-i-1;
		s[++top]=i;
	}
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		if(a[x]<p[x-1]){
			puts("0");
			continue;
		}
		if(x>1)y-=x-2;
		if(y<0)puts("0");
		else{
			if(a[x]==n)cout<<y<<endl;
			else if(x==1)cout<<min(y,la[x])<<endl;
			else cout<<min(y,la[x]+1)<<endl;
		}
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
5 2
3 1 2 5 4
1 2
1 1
*/