#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],b[200500],r[200500],f[200500],st[200500][20],l2[200500],mp[200500];
int rx,ry,res;
set<pair<int,int> >s;
int chk(int l,int r){int k=l2[r-l+1];return max(st[l][k],st[r-(1<<k)+1][k]);}


int main(){
	l2[0]=-1;
	for(i=1;i<=200000;i++){
		l2[i]=l2[i>>1]+1;
	}
	
    ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=n;i>=1;i--){
		if(!r[a[i]])r[a[i]]=i;
		b[i]=r[a[i]];
		st[i][0]=b[i];
	}
	for(j=1;j<=18;j++){
		for(i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	for(i=n;i>=1;i--){
		f[i]=f[i+1];
		k=chk(i,b[i]);
		k=mp[k];
		
		f[i]=max(f[i],f[b[i]+1]+(b[i]-i-1));
		f[i]=max(f[i],f[k]+(k-i-1));
		
		//printf("a%d %d %d %d\n",i,k,f[i],b[i]);
		mp[b[i]]=i;
	}
	cout<<f[1];
}