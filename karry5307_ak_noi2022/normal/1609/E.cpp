#include<bits/stdc++.h>
using namespace std;
struct Matrix{
	int val[4][4];
	Matrix(){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				val[i][j]=1e9;
			}
		}
	}
	Matrix(char c){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				val[i][j]=1e9;
			}
		}
		for(int i=0;i<4;i++){
			if(i==c-'a') val[i][i]=1;
			else val[i][i]=0;
		}
		for(int i=0;i<3;i++){
			if(i==c-'a') val[i][i+1]=0;
			else val[i][i+1]=1;
		} 
	}
	Matrix operator * (const Matrix &M) const& {
		Matrix Ans;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				for(int k=0;k<4;k++){
					Ans.val[i][j]=min(Ans.val[i][j],val[i][k]+M.val[k][j]);
				}
			}
		}return Ans;
	}
}M[400010];
int n,q;char s[100010];
void Build(int k,int l,int r){
	if(l==r){
		M[k]=Matrix(s[l]);
//		printf("%d %d %d\n",k,l,r);
//		for(int i=0;i<4;i++){
//			for(int j=0;j<4;j++) printf("%d ",M[k].val[i][j]);
//			puts("");
//		}
		return;
	}int mid=(l+r)>>1;
	Build(k<<1,l,mid);
	Build(k<<1|1,mid+1,r);
	M[k]=M[k<<1]*M[k<<1|1];
//			printf("%d %d %d\n",k,l,r);
//			for(int i=0;i<4;i++){
//				for(int j=0;j<4;j++) printf("%d ",M[k].val[i][j]);
//				puts("");
//			}
}
void Modify(int k,int l,int r,int x){
	if(l==r){
		M[k]=Matrix(s[l]);
		return;
	}int mid=(l+r)>>1;
	if(x<=mid) Modify(k<<1,l,mid,x);
	else Modify(k<<1|1,mid+1,r,x);
	M[k]=M[k<<1]*M[k<<1|1];
}
int main(){
	scanf("%d %d %s",&n,&q,s+1);Build(1,1,n);
	for(int i=1;i<=q;i++){
		int x;char c;scanf("%d %c",&x,&c);
		s[x]=c;Modify(1,1,n,x);
		printf("%d\n",min(min(M[1].val[0][0],M[1].val[0][1]),M[1].val[0][2]));
	}
	return 0;
}