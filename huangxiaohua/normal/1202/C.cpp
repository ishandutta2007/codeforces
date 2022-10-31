#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x[200500],y[200500],cx,cy,mx,mn;
ll rx,ry,sb1,sb2;
char s[200500];

void chkx(){
	int i,j;
	k=1;
	for(i=0;i<=n;i++){
		if(x[i]==mx){k=0;
			if(!i||x[i-1]==mn){k=1;break;}
			for(j=i;j<=n;j++){
				if(x[j]==mn){k=1;break;}
			}break;
		}
	}
	if(!k){sb1=1;}
	
	k=1;
	for(i=0;i<=n;i++){
		if(x[i]==mn){k=0;
			if(!i||x[i-1]==mx){k=1;break;}
			for(j=i;j<=n;j++){
				if(x[j]==mx){k=1;break;}
			}break;
		}
	}
	if(!k){sb1=1;}
}

void chky(){
	int i,j;
	k=1;
	for(i=0;i<=n;i++){
		if(y[i]==mx){k=0;
			if(!i||y[i-1]==mn){k=1;break;}
			for(j=i;j<=n;j++){
				if(y[j]==mn){k=1;break;}
			}break;
		}
	}
	if(!k){sb2=1;}
	
	k=1;
	for(i=0;i<=n;i++){
		if(y[i]==mn){k=0;
			if(!i||y[i-1]==mx){k=1;break;}
			for(j=i;j<=n;j++){
				if(y[j]==mx){k=1;break;}
			}break;
		}
	}
	if(!k){sb2=1;}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s+1;
		n=strlen(s+1);
		cx=cy=sb1=sb2=0;
		for(i=1;i<=n;i++){
			if(s[i]=='W'){cy--;}
			if(s[i]=='S'){cy++;}
			if(s[i]=='A'){cx--;}
			if(s[i]=='D'){cx++;}
			x[i]=cx;y[i]=cy;
		}
		mn=0;mx=0;
		for(i=1;i<=n;i++){
			mx=max(mx,x[i]);
			mn=min(mn,x[i]);
		}
		rx=mx-mn+1;
		if(rx>1){chkx();}
		
		mn=0;mx=0;
		for(i=1;i<=n;i++){
			mx=max(mx,y[i]);
			mn=min(mn,y[i]);
		}
		ry=mx-mn+1;
		if(ry>1){chky();}
		
		cout<<min((rx-sb1)*(ry),(rx)*(ry-sb2))<<endl;
	}
}