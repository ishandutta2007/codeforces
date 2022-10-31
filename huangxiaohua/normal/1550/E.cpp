#include <bits/stdc++.h>
using namespace std;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,f[300500],l,r,md,nxt[20][200500],it,res;
char s[200500];

bool chk(int x){
	f[0]=0;int i,j,k;
	for(i=1;i<b(m+1);i++){
		for(j=1;j<=m;j++){
			if(!(b(j)&i)){continue;}k=(b(j)^i);
			if(f[k]>n){continue;}
			f[i]=min(f[i],nxt[j][f[k]+1]);
		}
	}
	if(f[b(m+1)-1]<=n){return 1;}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m>>s+1;
	for(i=1;i<=n;i++){
		if(s[i]=='?'){s[i]=0;}
		else{s[i]-='a'-1;}
	}
	l=1;r=n;
	while(l<=r){
		md=(l+r)/2;
		memset(f,1,sizeof(f));
		memset(nxt,1,sizeof(nxt));
		for(i=1;i<=m;i++){
			it=0;
			for(j=n;j>=1;j--){
				nxt[i][j]=nxt[i][j+1];
				if(s[j]==0||s[j]==i){it++;}else{it=0;}
				if(it>=md){nxt[i][j]=min(nxt[i][j],j+md-1);}
			}
		}
		if(chk(md)){res=max(res,md);l=md+1;}
		else{r=md-1;}
	}
	cout<<res<<endl;
}