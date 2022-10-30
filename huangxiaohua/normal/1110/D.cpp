#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int f[1000500][5][5],n,i,j,k,res,it,a[1000500];
	
	void mx(int &a,int b){a=(a>b)?a:b;}
	
	void chk(int id,int x,int y,int z,int cur){
		if(x<0||y<0||z<0)return;
		if(z<=4)mx(f[id][y][z],cur);
		chk(id,x-3,y,z,cur+1);
		chk(id,x,y-3,z,cur+1);
		chk(id,x,y,z-3,cur+1);
		chk(id,x-1,y-1,z-1,cur+1);
	}
	
    int maxGroupNumber() {
		it=0;
		for(i=0;i<=n+1;i++){memset(f[i],-0x1f,sizeof(f[1]));}
		f[0][0][0]=0;
		for(i=1;i<=n;i++){
			for(j=0;j<=4;j++){
				for(k=0;k<=4;k++){
					for(int l=0;l<=6;l++){
						if(a[i]<l)continue;
						chk(i,j,k,l,f[i-1][j][k]+(a[i]-l)/3);
					}
				}
			}
            for(j=0;j<=4;j++){
				for(k=0;k<=4;k++){
					//printf("a%d %d %d %d\n",i,j,k,f[i][j][k]);
                    if(i==n)mx(res,f[i][j][k]);
				}
			}
		}
		return res;
    }
}so;

int i,j,k,n,m,t;

int main(){
	scanf("%d%d",&n,&m);
	so.n=m;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		so.a[k]++;
	}
	printf("%d",so.maxGroupNumber());
}