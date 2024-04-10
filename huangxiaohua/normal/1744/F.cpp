#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,pos[200500],a[200500],l,r,vis[200500],t1,x,y;
ll res=0;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(vis,0,n*4+50);
		for(i=1;i<=n;i++){cin>>a[i];pos[a[i]]=i;}
		res=0;l=r=pos[0];vis[0]=1;j=0;
		for(i=0;i<n;i++){
			if(j!=i)continue;
			while(l>pos[j]){l--;vis[a[l]]=1;}
			while(r<pos[j]){r++;vis[a[r]]=1;}
			while(vis[j])j++;
			if(j==n){res++;break;}
			x=l-1;y=n-r;
			if(pos[j]<=l)x-=pos[j];
			else y-=(n-pos[j]+1);
			t1=j+j-(r-l+1);
			if(x>y)swap(x,y);
			for(k=0;k<=min(x,t1);k++)res+=min(y,t1-k)+1;
		}
		cout<<res<<'\n';
	}
}