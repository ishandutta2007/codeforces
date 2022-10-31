#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
int f[15][15][15][15],res[15][15];
queue<int> q;
char s[2005000];
void chk(int a,int b,int c){
	int used[20]={0};
	int i,j,k;
	
	k=(c+a)%10;
	used[k]=1;
	f[a][b][c][k]=1;
	q.push(k);
	
	k=(c+b)%10;
	if(!used[k]){
		used[k]=1;
		f[a][b][c][k]=1;
		q.push(k);
	}
	
	while(!q.empty()){
		k=q.front();
		k=(k+a)%10;
		if(!used[k]){q.push(k);used[k]=1;}
		f[a][b][c][k]=min(f[a][b][c][k],f[a][b][c][q.front()]+1);
		k=q.front();
		k=(k+b)%10;
		if(!used[k]){q.push(k);used[k]=1;}
		f[a][b][c][k]=min(f[a][b][c][k],f[a][b][c][q.front()]+1);
		q.pop();
	}
}

int main(){
	memset(f,1,sizeof(f));
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			for(k=0;k<=9;k++){
				chk(i,j,k);
			}
		}
	}
	gets(s+1);n=strlen(s+1);
	s[1]-='0';
	for(i=2;i<=n;i++){
		s[i]-='0';
		for(j=0;j<=9;j++){
			for(k=0;k<=9;k++){
				if(res[j][k]==-1){continue;}
				if(f[j][k][s[i-1]][s[i]]>100){res[j][k]=-1;}
				else{res[j][k]+=f[j][k][s[i-1]][s[i]]-1;}
			}
		}
	}
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			printf("%d ",res[i][j]);
		}puts("");
	}
}