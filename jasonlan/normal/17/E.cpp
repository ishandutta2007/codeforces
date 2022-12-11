#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=4010000,mod=51123987;
int n;
char s[maxn];
int f[maxn];
int bgtag[maxn],edtag[maxn],ans;
int qmod(int x){
	return x>=mod?x-mod:x;
}
void reset(){
	for(register int i=n;i;--i){
		s[i<<1]=s[i];
		s[(i<<1)-1]='|';
	}
	s[(n<<1)+1]='|';
	s[0]='~';
}
void manacher(){
	for(register int i=1,maxr=0,mid=0;i<=(n<<1)+1;++i){
		if(i<=maxr)f[i]=min(f[mid*2-i],maxr-i+1);
		else f[i]=1;
		while(s[i-f[i]]==s[i+f[i]])++f[i];
		if(i+f[i]-1>maxr){
			maxr=i+f[i]-1;
			mid=i;
		}
		++bgtag[i-f[i]+1];// 
		--bgtag[i+1];
		++edtag[i];//
		--edtag[i+f[i]];
	}
}
int main(){
	scanf("%d%s",&n,s+1);
	reset();manacher();
	for(register int i=1,cnt=0;i<=(n<<1)+1;++i){
		bgtag[i]+=bgtag[i-1];
		edtag[i]+=edtag[i-1];
		if(s[i]>='a'&&s[i]<='z'){
			cnt=qmod(cnt+bgtag[i]);
			ans=qmod(ans+1ll*cnt*edtag[i]%mod);
			ans=qmod(ans-1ll*edtag[i]*(edtag[i]+1)/2%mod+mod);
			cnt=qmod(cnt-edtag[i]+mod);
		}
	}
	printf("%d\n",ans);
	return 0;
}