#include <cstdio>
#include <algorithm>

int n,k,pmx[100001][2],pmn[100001][2],bmx[100010][2],bmn[100010][2];
bool mat[100001];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%1d",mat+i);
	pmn[0][0]=pmn[0][1]=bmn[n+1][0]=bmn[n+1][1]=n+1;
	for(int i=1;i<=n;i++){
		pmx[i][0]=pmx[i-1][0];
		pmx[i][1]=pmx[i-1][1];
		pmn[i][0]=pmn[i-1][0];
		pmn[i][1]=pmn[i-1][1];
		if(mat[i]){
			pmx[i][1]=i;
			pmn[i][1]=(pmn[i][1]==n+1)?i:pmn[i][1];
		}
		else{
			pmx[i][0]=i;
			pmn[i][0]=(pmn[i][0]==n+1)?i:pmn[i][0];
		}
	}
	for(int i=n;i;--i){
		bmx[i][0]=bmx[i+1][0];
		bmx[i][1]=bmx[i+1][1];
		bmn[i][0]=bmn[i+1][0];
		bmn[i][1]=bmn[i+1][1];
		if(mat[i]){
			bmn[i][1]=i;
			bmx[i][1]=(!bmx[i][1])?i:bmx[i][1];
		}
		else{
			bmn[i][0]=i;
			bmx[i][0]=(!bmx[i][0])?i:bmx[i][0];
		}
	}
	if(pmx[n][0]-pmn[n][0]+1<=k||pmx[n][1]-pmn[n][1]+1<=k){
		puts("tokitsukaze");
		return 0;
	}
	for(int i=1;i+k-1<=n;i++){
		int mn,mx,l1,l2,l3,l4;
		mn=std::min(pmn[i-1][0],bmn[i+k][0]);
		mx=std::max(pmx[i-1][0],bmx[i+k][0]);
		l1=std::max(mx,i+k-1)-std::min(mn,i)+1;
		l2=mx-mn+1;
		mn=std::min(pmn[i-1][1],bmn[i+k][1]);
		mx=std::max(pmx[i-1][1],bmx[i+k][1]);
		l3=std::max(mx,i+k-1)-std::min(mn,i)+1;
		l4=mx-mn+1;
		if((l1>k&&l4>k)||(l2>k&&l3>k)){
			puts("once again");
			return 0;
		}
	}
	puts("quailty");
}