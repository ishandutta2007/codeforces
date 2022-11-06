#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=105;
int ans[N][N];
int n,m,x;
int b1[3][3],b2[3][3],res[3][3];
int d[N*N][2];
void solve(int i,int j){
	int x1,x2,x3,I=i,J=j;
	printf("? %d %d %d %d\n",i+1,j,i+2,j+1);cout.flush();
	cin>>x1;	
	printf("? %d %d %d %d\n",i,j+1,i+2,j+1);cout.flush();
	cin>>x2;
	printf("? %d %d %d %d\n",i,j+1,i+1,j+2);cout.flush();
	cin>>x3;
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++)
		b1[i][j]=b2[i][j]=ans[I+i][J+j];
	b1[1][0]=0;
	b2[1][0]=1;
	b1[2][1]=b1[1][0]^1^x1;
	b2[2][1]=b2[1][0]^1^x1;
	b1[0][1]=b1[2][1]^1^x2;
	b2[0][1]=b2[2][1]^1^x2;
	b1[1][2]=b1[0][1]^1^x3;
	b2[1][2]=b2[0][1]^1^x3;
	
	if (b1[2][0]==b1[2][1]||b1[2][1]==b1[1][1]||b1[1][1]==b1[1][2]){
		printf("? %d %d %d %d\n",i+1,j,i+2,j+2);cout.flush();
		cin>>x;
		if (x==1)memcpy(res,b1,sizeof res);
		else memcpy(res,b2,sizeof res);
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++){
		ans[i+I][j+J]=res[i][j];
	}
	return;
	}
	if (b1[0][1]==0){
		if (b1[1][1]==b1[1][2]||b1[1][1]==b1[2][1]||b1[1][2]==b1[0][2]){
			printf("? %d %d %d %d\n",i,j+1,i+2,j+2);cout.flush();
			cin>>x;
			if (x==1)memcpy(res,b1,sizeof res);
			else memcpy(res,b2,sizeof res);	
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++){
		ans[i+I][j+J]=res[i][j];
	}
	return;		
		}
	}
	else {
		if (b2[1][1]==b2[1][2]||b2[1][1]==b2[2][1]||b2[1][2]==b2[0][2]){
			printf("? %d %d %d %d\n",i,j+1,i+2,j+2);cout.flush();
			cin>>x;
			if (x==1)memcpy(res,b2,sizeof res);
			else memcpy(res,b1,sizeof res);		
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++){
		ans[i+I][j+J]=res[i][j];
	}
	return;	
		}
	}
	if (b1[1][2]==1){
		if (b1[1][0]==b1[1][1]||b1[1][1]==b1[0][1]||b1[0][1]==b1[0][2]){
			printf("? %d %d %d %d\n",i,j,i+1,j+2);cout.flush();
			cin>>x;
			if (x==1)memcpy(res,b1,sizeof res);
			else memcpy(res,b2,sizeof res);	
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++){
		ans[i+I][j+J]=res[i][j];
	}
	return;					
		}
	}
	else {
		if (b2[1][0]==b2[1][1]||b2[1][1]==b2[0][1]||b2[0][1]==b2[0][2]){
			printf("? %d %d %d %d\n",i,j,i+1,j+2);cout.flush();
			cin>>x;
			if (x==1)memcpy(res,b2,sizeof res);
			else memcpy(res,b1,sizeof res);	
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++){
		ans[i+I][j+J]=res[i][j];
	}
	return;					
		}		
	}
	if (b1[2][1]==1){
		if (b1[1][0]==b1[1][1]||b1[1][1]==b1[0][1]||b1[1][0]==b1[2][0]){
			printf("? %d %d %d %d\n",i,j,i+2,j+1);cout.flush();
			cin>>x;
			if (x==1)memcpy(res,b1,sizeof res);
			else memcpy(res,b2,sizeof res);	
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++){
		ans[i+I][j+J]=res[i][j];
	}
	return;								
		}
	}
	else {
		if (b2[1][0]==b2[1][1]||b2[1][1]==b2[0][1]||b2[1][0]==b2[2][0]){
			printf("? %d %d %d %d\n",i,j,i+2,j+1);cout.flush();
			cin>>x;
			if (x==1)memcpy(res,b2,sizeof res);
			else memcpy(res,b1,sizeof res);	
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++){
		ans[i+I][j+J]=res[i][j];
	}
	return;								
		}
	}
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++){
		ans[i+I][j+J]=res[i][j];
	}
	return;
}
int inmap(int x,int y){
	if (x<=0||y<=0||x>n||y>n)return 0;
	return 1;
}
int fx[3][2]={{2,0},{1,1},{0,2}};
int main(){
	cin>>n;
	memset(ans,255,sizeof ans);
	ans[1][1]=1;
	ans[n][n]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if ((i+j)%2==0){
				if (i>1&&j>1){
					printf("? %d %d %d %d\n",i-1,j-1,i,j);cout.flush();
					cin>>x;
					ans[i][j]=ans[i-1][j-1]^x^1;
				}
				else if (i>2){
					printf("? %d %d %d %d\n",i-2,j,i,j);cout.flush();
					cin>>x;					
					ans[i][j]=ans[i-2][j]^x^1;
				}
				else if (j>2){
					printf("? %d %d %d %d\n",i,j-2,i,j);cout.flush();
					cin>>x;					
					ans[i][j]=ans[i][j-2]^x^1;
				}
			}
		}
	}
	int fn=0,l=1,r=4;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if ((i+j)%2==0){
				if (ans[i][j]==1&&ans[i+2][j+2]==0){
					solve(i,j);
					fn=1;
					d[1][0]=i+1;
					d[1][1]=j;
					d[2][0]=i;
					d[2][1]=j+1;
					d[3][0]=i+2;
					d[3][1]=j+1;
					d[4][0]=i+1;
					d[4][1]=j+2;
					break;
				}
			}
		}
		if (fn)break;
	}
	int g1;
	while (l<r){
		l++;
		int x=d[l][0],y=d[l][1];
		for (int i=0;i<3;i++){
			int xx=x+fx[i][0],yy=y+fx[i][1];
			if (inmap(xx,yy)&&ans[xx][yy]==-1){
				printf("? %d %d %d %d\n",x,y,xx,yy);cout.flush();
				cin>>g1;
				ans[xx][yy]=ans[x][y]^1^g1;
				d[++r][0]=xx;
				d[r][1]=yy;
			}
			xx=x-fx[i][0],yy=y-fx[i][1];
			if (inmap(xx,yy)&&ans[xx][yy]==-1){				
				printf("? %d %d %d %d\n",xx,yy,x,y);cout.flush();
				cin>>g1;
				ans[xx][yy]=ans[x][y]^1^g1;
				d[++r][0]=xx;
				d[r][1]=yy;
			}
		}
	}
	cout<<"!"<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)putchar(ans[i][j]+'0');
		cout<<endl;
	}
}