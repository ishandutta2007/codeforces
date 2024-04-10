#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,sb[10],n,m,t,r[10],l[10],s[10],f[3050][3050],f2[3050][3050],f3[3050][3050];

bool chk(int x,int y,int z){
	int i,j,k,t1,t2,t0,l1,l2,r1,r2,s1[10]={0},res[10]={0},s2[10]={0};
	
	for(i=1;i<=7;i++){
		s1[i]=sb[i];
	}
	
	for(i=0;i<=s[x];i++){
		for(j=0;j<=s[y];j++){
			t0=min({i,j,sb[x|y]});
			t1=i-t0;t2=j-t0;
			f[i][j]=0;
			if(t1<=sb[x]&&t2<=sb[y]){f[i][j]=1;}
		}
	}
	
	for(i=0;i<=s[x];i++){
		for(j=0;j<=s[y];j++){
			f3[i][j]=f[i][j] + ((i>0)?f3[i-1][j]:0) + ((j>0)?f3[i][j-1]:0) - ((i>0&&j>0)?f3[i-1][j-1]:0);
		}
	}
	
	for(i=0;i<=s[x];i++){
		for(j=0;j<=s[y];j++){
			f2[i][j]=0;
			t0=min({i,j,sb[7]});
			if( i-t0>sb[x|z] || j-t0>sb[y|z] ){continue;}
			t1=i+j-t0;
			t0=max({0,i-sb[x|z],j-sb[y|z]});
			if(t0>sb[7]){continue;}
			t2=i+j+sb[z]-t0;
			if(l[z]<=t1&&t1<=r[z]){f2[i][j]=1;}
			if(l[z]<=t2&&t2<=r[z]){f2[i][j]=1;}
			if(t1<=l[z]&&l[z]<=t2){f2[i][j]=1;}
			if(t1<=r[z]&&r[z]<=t2){f2[i][j]=1;}
		}
	}
	
	for(i=0;i<=s[x];i++){
		for(j=0;j<=s[y];j++){
			if(!f2[i][j]){continue;}
			l1=max(0,l[x]-i);r1=min(s[x],r[x]-i);
			l2=max(0,l[y]-j);r2=min(s[y],r[y]-j);
			if(r1<0||r2<0){continue;}
			t0=f3[r1][r2];
			if(l1){t0-=f3[l1-1][r2];}
			if(l2){t0-=f3[r1][l2-1];}
			if(l1&&l2){t0+=f3[l1-1][l2-1];}
			if(t0){
				while(s1[7]&&i&&j){
					s1[7]--;res[7]++;
					s2[x]++;s2[y]++;s2[z]++;
					i--;j--;
				}
				while(i){
					s1[x|z]--;res[x|z]++;
					s2[x]++;s2[z]++;
					i--;
				}
				while(j){
					s1[y|z]--;res[y|z]++;
					s2[y]++;s2[z]++;
					j--;
				}
				while(s1[z]&&s2[z]<l[z]){
					s1[z]--;res[z]++;
					s2[z]++;
				}
				while(s2[z]<l[z]){
					s1[7]++;res[7]--;
					s1[x|z]--;res[x|z]++;
					s1[y|z]--;res[y|z]++;
					s2[z]++;
				}
				goto aaa;
			}
		}
	}
	return 0;
	
	aaa:;
	for(i=0;i<=s[x];i++){
		for(j=0;j<=s[y];j++){
			if(!f[i][j]){continue;}
			if( (l[x]<=i+s2[x]&&i+s2[x]<=r[x]) && (l[y]<=j+s2[y]&&j+s2[y]<=r[y]) ){
				while(s1[x|y]&&i&&j){
					s1[x|y]--;res[x|y]++;
					s2[x]++;s2[y]++;
					i--;j--;
				}
				while(i){
					s1[x]--;res[x]++;
					s2[x]++;
					i--;
				}
				while(j){
					s1[y]--;res[y]++;
					s2[y]++;
					j--;
				}
				goto bbb;
			}
		}
	}
	
	
	bbb:;
	
	for(i=7;i>=1;i--){
		printf("%d ",res[i]);
	}puts("");
	return 1;
}

int main(){
	scanf("%d",&t);
	while(t--){
		s[1]=s[2]=s[4]=0;
		scanf("%d%d%d",&r[4],&r[2],&r[1]);
		scanf("%d%d%d",&l[4],&l[2],&l[1]);
		for(i=7;i>=1;i--){
			scanf("%d",&sb[i]);
			if(i&1){s[1]+=sb[i];}
			if(i&2){s[2]+=sb[i];}
			if(i&4){s[4]+=sb[i];}
		}
		for(i=1;i<=4;i++){
			l[i]=max(s[i]-l[i],0);
			if(l[i]>r[i]){puts("-1");goto aaa;}
		}
		if(chk(1,2,4)){goto aaa;}
		puts("-1");
		aaa:;
	}
}