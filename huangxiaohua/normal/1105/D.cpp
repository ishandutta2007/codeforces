#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define chk(i,a,b) if(!used[a][b]){yes=1;res[i]++;used[a][b]=1;xxx.push(a);yyy.push(b);}
 
int t,n,i,j,k,m,p,a[10],res[10],yes=1,x,y,ed[10];
char sb[1005][1005];
bool used[1005][1005];
queue<int> xx[10],yy[10],xxx,yyy;
 
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=p;i++){
		scanf("%d",&a[i]);
	}getchar();
	for(i=0;i<=n+1;i++){used[i][0]=used[i][m+1]=1;}
	for(i=0;i<=m+1;i++){used[0][i]=used[n+1][i]=1;}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			sb[i][j]=getchar();
			if(sb[i][j]=='#'){used[i][j]=1;continue;}
			if(sb[i][j]!='.'){used[i][j]=1;res[sb[i][j]-'0']++;xx[sb[i][j]-'0'].push(i);yy[sb[i][j]-'0'].push(j);}
		}getchar();
	}
	while(yes){
		yes=0;
		for(i=1;i<=p;i++){
			if(ed[i]){continue;}
			t=a[i];
			while(t--){
				while(!xx[i].empty()){
					x=xx[i].front();xx[i].pop();y=yy[i].front();yy[i].pop();
					chk(i,x-1,y);chk(i,x+1,y);chk(i,x,y-1);chk(i,x,y+1);
				}
				swap(xx[i],xxx);swap(yy[i],yyy);
				if(xx[i].empty()){break;}
			}
			if(!yes){ed[i]=1;}
		}
	}
	
	for(i=1;i<=p;i++){
		printf("%d ",res[i]);
	}
}