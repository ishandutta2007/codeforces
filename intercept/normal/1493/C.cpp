#include<bits/stdc++.h>
using namespace std;
const int M=100009;
int n,m;
int a[M],b[M],f[M][27][18];
int bol=0,sum,cnt[29];
char s[M];
int Min(int x,int y){
	if(x==1)return 1;
	if(x==0)return y;
	return -1;
}
int cmp(int l,int len,int c){
	if(len==0)return 0;
	int r=l+len-1,k=log2(r-l+1);
	return Min(f[l][c][k],f[r-(1<<k)+1][c][k]);
}
int C(int x,int y){ 
	if(x> y)return 1;
	if(x==y)return 0;
	if(x< y)return -1;
}
bool check(int l){
	int k=cmp(l,sum,26);
	if(k==1)return 1;
	l=l+sum;
	for(int j=26;j>=1;--j){
		k=cmp(l,cnt[j],j);
		if(k== 1)return 1;
		if(k==-1)return 0;
		l=l+cnt[j];
		
	}
	return 1;
}
void work(){
	bol=0;
	scanf("%d%d%s",&n,&m,s+1);
	if(n%m){printf("-1\n");return;}
	for(int i=1;i<=n;++i)a[i]=s[i]-'a'+1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=26;++j){
			f[i][j][0]=C(j,a[i]);
		}
	}
	for(int k=1;k<=17;++k){
		for(int j=1;j<=26;++j){
			for(int i=1;i+(1<<k)-1<=n;++i){
				f[i][j][k]=Min(f[i][j][k-1],f[i+(1<<k-1)][j][k-1]);
			}
		}
	}
	sum=n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=26;++j){
			if(!bol&&j<a[i])continue;
			if(a[i]==j&&!bol){
				if(cnt[j]){
					cnt[j]--;
					if(check(i+1)){b[i]=j;break;}
					cnt[j]++;
				}
				else if(sum){
					cnt[j]+=m-1;
					sum-=m;
					if(check(i+1)){b[i]=j;break;}
					sum+=m;
					cnt[j]-=m-1;
				}
				continue;
			}
			bol=1;
			if(cnt[j]){
				b[i]=j,cnt[j]--;
				break;
			}
			else if(sum){
				b[i]=j,cnt[j]+=m-1,sum-=m;
				break;
			}
		}
		char t=b[i]+'a'-1;
		printf("%c",t);
	}
	printf("\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
6 3
abbbbc
*/