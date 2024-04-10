#include <cstdio>
const int Maxn=200000;
const int Mod[3]={1000000007,998244353,1000000009};
const int eps=11;
const int Mod_len=3;
int ksm(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		a=1ll*a*a%Mod;
		b>>=1;
	}
	return ans;
}
int n,q;
char s[Maxn+5];
int a[Maxn+5];
int sum[2][Maxn+5];
int twice[Maxn+5];
int num[Mod_len][Maxn+5];
int nxt[Maxn+5];
void init(){
	for(int i=1;i<=n;i++){
		sum[0][i]=sum[0][i-1];
		sum[1][i]=sum[1][i-1];
		sum[a[i]][i]++;
		for(int l=0;l<Mod_len;l++){
			if(a[i]==1&&a[i-1]==1){
				if(twice[i-1]==twice[i-2]+1){
					twice[i]=twice[i-1];
					num[l][i]=(num[l][i-1]+ksm(eps,i,Mod[l]))%(Mod[l]);
				}
				else{
					twice[i]=twice[i-1]+1;
					num[l][i]=1ll*num[l][i-2]*eps%Mod[l]*eps%Mod[l];
				}
			}
			else if(a[i]==0){
				twice[i]=twice[i-1];
				num[l][i]=num[l][i-1];
			}
			else{
				twice[i]=twice[i-1];
				num[l][i]=(num[l][i-1]+ksm(eps,i,Mod[l]))%(Mod[l]);
			}
		}
	}
	for(int i=n;i>0;i--){
		nxt[i]=nxt[i+1];
		if(a[i+1]!=1){
			nxt[i]=i;
		}
	}
}
int get_hash(int l,int left,int right){
	if(a[left]==1){
		left=nxt[left]+1;
	}
	if(left>right){
		return 0;
	}
	if(left==1){
		return num[l][right];
	}
	int ans=num[l][right];
	ans=(ans-1ll*num[l][left-1]*ksm(eps*eps,twice[right]-twice[left-1],Mod[l])%Mod[l]+Mod[l])%Mod[l];
	return 1ll*ans*ksm(ksm(eps,left+((twice[right]-twice[left-1])<<1)-1,Mod[l]),Mod[l]-2,Mod[l])%Mod[l];
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d",&q);
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
	}
	init();
	int l,r,len;
	bool flag;
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&l,&r,&len);
		if(sum[0][l+len-1]-sum[0][l-1]!=sum[0][r+len-1]-sum[0][r-1]){
			puts("No");
			continue;
		}
		if(sum[1][l+len-1]-sum[1][l-1]!=sum[1][r+len-1]-sum[1][r-1]){
			puts("No");
			continue;
		}
		flag=1;
		for(int j=0;j<Mod_len;j++){
			if(get_hash(j,l,l+len-1)!=get_hash(j,r,r+len-1)){
				flag=0;
				break;
			}
		}
		if(flag){
			puts("Yes");
		}
		else{
			puts("No");
		}
	}
	return 0;
}
/*
15
110000010000011
1000
*/