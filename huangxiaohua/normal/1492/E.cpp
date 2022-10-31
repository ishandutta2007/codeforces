#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)
unordered_map<int,unordered_map<int,int> >a;

int i,j,n,k,res[300050],pos[300500],t1,t2,m,b[10],q;

void yes(){
	puts("Yes");for(i=1;i<=m;i++){printf("%d ",res[i]);}exit(0);
}

bool chk(){
	int i,j,k;
	for(i=1;i<=n;i++){
		k=0;
		for(j=1;j<=m;j++){
			if(a[i][j]!=res[j]){k++;}
		}
		if(k>2){return 0;}
	}
	return 1;
}

bool chk2(int x){
	int i,j,k,l=0;
	for(i=1;i<=n;i++){
		k=0;
		for(j=1;j<=m;j++){
			if(!l&&j==x){continue;}
			if(a[i][j]!=res[j]){k++;}
		}
		if(k>2){return 0;}
		if(k==2&&!l){l=1;res[x]=a[i][x];}
	}
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=m;i++){
		res[i]=a[1][i];
	}
	for(i=2;i<=n;i++){
		k=0;
		for(j=1;j<=m;j++){
			if(a[i][j]!=res[j]){
				k++;
			}
		}
		if(k>4){puts("No");return 0;}
		if(k>t1){t1=k;t2=i;}
	}
	if(t1<=2){
		yes();
	}
	if(t1==3){
		for(i=1;i<=m;i++){
			if(a[t2][i]!=res[i]){
				b[++q]=i;
			}
		}
		res[b[1]]=a[1][b[1]];
		res[b[2]]=a[t2][b[2]];
		//res[b[3]]=a[t2][b[3]];
		if(chk2(b[3])){
			yes();
		}
		res[b[1]]=a[t2][b[1]];
		res[b[2]]=a[1][b[2]];
		//res[b[3]]=a[t2][b[3]];
		if(chk2(b[3])){
			yes();
		}
		res[b[1]]=a[t2][b[1]];
		//res[b[2]]=a[t2][b[2]];
		res[b[3]]=a[1][b[3]];
		if(chk2(b[2])){
			yes();
		}
		res[b[1]]=a[1][b[1]];
		//res[b[2]]=a[1][b[2]];
		res[b[3]]=a[t2][b[3]];
		if(chk2(b[2])){
			yes();
		}
		//res[b[1]]=a[1][b[1]];
		res[b[2]]=a[t2][b[2]];
		res[b[3]]=a[1][b[3]];
		if(chk2(b[1])){
			yes();
		}
		//res[b[1]]=a[t2][b[1]];
		res[b[2]]=a[1][b[2]];
		res[b[3]]=a[t2][b[3]];
		if(chk2(b[1])){
			yes();
		}
		puts("No");return 0;
	}
	
	if(t1==4){
		for(i=1;i<=m;i++){
			if(a[t2][i]!=res[i]){
				b[++q]=i;
			}
		}
		res[b[1]]=a[1][b[1]];
		res[b[2]]=a[1][b[2]];
		res[b[3]]=a[t2][b[3]];
		res[b[4]]=a[t2][b[4]];
		if(chk()){
			yes();
		}
		res[b[1]]=a[1][b[1]];
		res[b[2]]=a[t2][b[2]];
		res[b[3]]=a[1][b[3]];
		res[b[4]]=a[t2][b[4]];
		if(chk()){
			yes();
		}
		res[b[1]]=a[1][b[1]];
		res[b[2]]=a[t2][b[2]];
		res[b[3]]=a[t2][b[3]];
		res[b[4]]=a[1][b[4]];
		if(chk()){
			yes();
		}
		res[b[1]]=a[t2][b[1]];
		res[b[2]]=a[1][b[2]];
		res[b[3]]=a[1][b[3]];
		res[b[4]]=a[t2][b[4]];
		if(chk()){
			yes();
		}
		res[b[1]]=a[t2][b[1]];
		res[b[2]]=a[1][b[2]];
		res[b[3]]=a[t2][b[3]];
		res[b[4]]=a[1][b[4]];
		if(chk()){
			yes();
		}
		res[b[1]]=a[t2][b[1]];
		res[b[2]]=a[t2][b[2]];
		res[b[3]]=a[1][b[3]];
		res[b[4]]=a[1][b[4]];
		if(chk()){
			yes();
		}

		puts("No");return 0;
	}
}