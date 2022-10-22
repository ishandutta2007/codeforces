#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int x,y,p1,p2=1,k,n,m,a[100009],ans[100009],c=1,mark[100009];
int main(){
	cin>>n>>m;
	f(i,0,n) cin>>a[i];
	while(p2<n-1){
		if(a[p2+1]>a[p2] && k==0) p2++; 
		if(a[p2+1]>a[p2] && k==1){ans[p1]=c;mark[p2]=1;c++;p2++;p1=p2;k=0;}
		if(a[p2+1]<a[p2] && k==1) p2++;
		if(a[p2+1]<a[p2] && k==0){k=1;p2++;}
		if(a[p2+1]==a[p2]) p2++;	
	}
	ans[p1]=c;
	f(i,1,n){
		if(ans[i]==0) ans[i]=ans[i-1];
	}
	f_(i,n-2,0){
		if(mark[i+1]==1 && a[i]==a[i+1]) mark[i]=1;
	}
	cout<<endl;
	f(i,0,m){
		cin>>x>>y;x--;y--;
		if(ans[x]==ans[y] || (mark[x]==1 && ans[y]==ans[x]+1)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}