#include <cstdio>
const int Maxn=200000;
char s[Maxn+5];
int n,q;
int sum[Maxn+5][26];
int sz[26];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			sum[i][j]=sum[i-1][j];
		}
		sum[i][s[i]-'a']++;
	}
	scanf("%d",&q);
	int l,r;
	int num;
	int S,maxn;
	int pos;
	while(q--){
		scanf("%d%d",&l,&r);
		if(l==r){
			puts("Yes");
			continue;
		}
		num=0;
		for(int i=0;i<26;i++){
			sz[i]=sum[r][i]-sum[l-1][i];
			if(sum[r][i]-sum[l-1][i]>0){
				num++;
			}
		}
		if(num==1){
			puts("No");
		}
		else{
			if(num==2&&r-l+1>2){
				S=0;
				maxn=0;
				for(int i=0;i<26;i++){
					S+=sz[i];
					if(sz[i]>maxn){
						pos=i;
					}
					maxn=mx(maxn,sz[i]);
				}
				if(s[l]==s[r]){
					puts("No");
					continue;
				}
			}
			puts("Yes");
		}
	}
	return 0;
}