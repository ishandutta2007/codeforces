#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int a[1005],b[9][1005],n,m,i,j,k,l,dp[260][150][1055],t1,t2;
bool used[260][150][1055];
vector<int> v[9],tmp[9],chk;
 
int main(){
	scanf("%d",&n);
	for(j=1;j<=126;j++){used[0][j][0]=1;}
	for(i=0;i<256;i++){
		j=i;k=0;while(j){if(j&1){k++;}j>>=1;}
		tmp[k].push_back(i);
	}
	for(i=1;i<=8;i++){for(j=0;j<tmp[i].size();j++){chk.push_back(tmp[i][j]);}v[i].push_back(0);}
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
		for(j=1;j<=8;j++){
			b[j][i]=b[j][i-1];
		}b[a[i]][i]++;
	}
	for(int ii=0;ii<chk.size();ii++){
		i=chk[ii];
		for(j=1;j<=8;j++){
			if(i&(1<<(j-1))){t1=i-(1<<(j-1));}else{continue;}
			for(k=1;k<=n/8+1;k++){
				for(l=n;l>=k;l--){
					if(!used[t1][k][l-k]){continue;}
					t2=b[j][dp[t1][k][l-k]]+k;
					if(t2>=v[j].size()){continue;}
					if(!used[i][k][l]){used[i][k][l]=1;dp[i][k][l]=v[j][t2];}
					else{dp[i][k][l]=min(v[j][t2],dp[i][k][l]);}
					//printf("%d %d %d %d\n",i,k,l,dp[i][k][l]);
				}
				for(l=n;l>=k-1;l--){
					if(!used[t1][k][l-k+1]){continue;}
					t2=b[j][dp[t1][k][l-k+1]]+k-1;
					if(t2>=v[j].size()){continue;}
					
					if(!used[i][k][l]){used[i][k][l]=1;dp[i][k][l]=v[j][t2];}
					else{dp[i][k][l]=min(v[j][t2],dp[i][k][l]);}
					//printf("%d %d %d %d\n",i,k,l,dp[i][k][l]);
				}
			}
		}
	}
	
	for(j=n;j>=0;j--){
		for(i=1;i<=125;i++){if(used[255][i][j]){printf("%d",j);return 0;}}
	}
}