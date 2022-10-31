#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#pragma GCC optimize(5)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
int n,i,j,good[2666][2],g,mp[55][55],x,y;
char s[55];
void check(int i,int j){
	mp[i][j]=4;
	if(mp[i-1][j]==0||mp[i-1][j]==2){check(i-1,j);}
	if(mp[i][j-1]==0||mp[i][j-1]==2){check(i,j-1);}
	if(mp[i+1][j]==0||mp[i+1][j]==2){check(i+1,j);}
	if(mp[i][j+1]==0||mp[i][j+1]==2){check(i,j+1);}
	return;
}
int main(){
	scanf("%d\n",&n);
	while(n--){
		scanf("%d%d\n",&x,&y);
		g=0;
		for(i=0;i<=x+1;i++){
			mp[i][0]=mp[i][y+1]=1;
		}
		for(i=0;i<=y+1;i++){
			mp[0][i]=mp[x+1][i]=1;
		}
		for(i=1;i<=x;i++){
			gets(s);
			for(j=1;j<=y;j++){
				if(s[j-1]=='.'){mp[i][j]=0;continue;}
				if(s[j-1]=='#'){mp[i][j]=1;continue;}
				if(s[j-1]=='G'){mp[i][j]=2;continue;}
				if(s[j-1]=='B'){mp[i][j]=3;}
			}
		}
		if(mp[x][y]==3){puts("No");continue;}
		for(i=1;i<=x;i++){
			for(j=1;j<=y;j++){
				if(mp[i][j]==3){
					if(mp[i-1][j]==2||mp[i][j-1]==2||mp[i][j+1]==2||mp[i+1][j]==2){puts("No");goto aaa;}
					if(mp[i-1][j]!=3){mp[i-1][j]=1;}
					if(mp[i][j-1]!=3){mp[i][j-1]=1;}
					if(mp[i+1][j]!=3){mp[i+1][j]=1;}
					if(mp[i][j+1]!=3){mp[i][j+1]=1;}
				}
				if(mp[i][j]==2){
					g++;
					good[g][0]=i;good[g][1]=j;
				}
			}
		}	
		if(mp[x][y]==1&&g>0){puts("No");continue;}
		if(mp[x][y]!=3&&g==0){puts("Yes");continue;}
		check(x,y);
		for(i=1;i<=g;i++){
			if(mp[good[i][0]][good[i][1]]!=4){puts("No");goto aaa;}
		}
		puts("Yes");
		aaa:continue;
	}
}