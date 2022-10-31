#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 nmsl1
#define x2 nmsl2
#define y1 nmsl3
#define y2 nmsl4

int i,j,k,n,m,t,a[505][505],f[505][505];
char c[505][505];

struct sb{
	int id,x1,y1,x2,y2,res;
}s[300500];

void chk(int x,int y,int z){
	int i,j,k;
	if(!x||!y){return;}
	for(i=y;i<=y+z-1;i++){
		if(c[x][i]!='R'){return;}
	}
	for(i=x;i<=x+z-1;i++){
		if(c[i][y]!='R'){return;}
	}
	
	for(i=y+z;i<=y+z+z-1;i++){
		if(c[x][i]!='G'){return;}
	}
	for(i=x;i<=x+z-1;i++){
		if(c[i][y+z+z-1]!='G'){return;}
	}
	
	
	for(i=y;i<=y+z-1;i++){
		if(c[x+z+z-1][i]!='Y'){return;}
	}
	for(i=x+z;i<=x+z+z-1;i++){
		if(c[i][y]!='Y'){return;}
	}
	
	for(i=x+z;i<=x+z+z-1;i++){
		if(c[i][y+z+z-1]!='B'){return;}
	}
	for(i=y+z;i<=y+z+z-1;i++){
		if(c[x+z+z-1][i]!='B'){return;}
	}
	a[x][y]=z;
	chk(x-1,y-1,z+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>t;
	for(i=1;i<=n;i++){
		cin>>c[i]+1;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			chk(i,j,1);
		}
	}
	for(i=1;i<=t;i++){
		cin>>s[i].x1>>s[i].y1>>s[i].x2>>s[i].y2;
	}
	for(i=250;i>=1;i--){
		memset(f,0,sizeof(f));
		for(j=1;j<=n;j++){
			for(k=1;k<=m;k++){
				f[j][k]=f[j-1][k]+f[j][k-1]-f[j-1][k-1]+(a[j][k]==i);
			}
		}
		for(j=1;j<=t;j++){
			if(s[j].res){continue;}
			if((s[j].x2-s[j].x1+1)<i*2||(s[j].y2-s[j].y1+1)<i*2){
				continue;
			}
			k=f[s[j].x2-i-i+1][s[j].y2-i-i+1]-f[s[j].x1-1][s[j].y2-i-i+1]-f[s[j].x2-i-i+1][s[j].y1-1]+f[s[j].x1-1][s[j].y1-1];
			if(k>0){
				s[j].res=i*i*4;
			}
		}
	}
	for(j=1;j<=t;j++){
		cout<<s[j].res<<'\n';
	}
}