#include<bits/stdc++.h>
typedef int LL;
const LL maxn=1e6+9;
LL n,ans,az,al;
char s[maxn],s1[maxn],T[maxn];
LL hw[maxn],nxt[maxn],suf[maxn],sux[maxn],sua[maxn];
inline void Change1(){
	for(LL i=1;i<=n;++i){
		s1[i*2-1]=s[i];
		s1[i*2]='#';
	}
}
inline void Manacher(){
	hw[1]=1; LL mid=1,Maxr(1);
	for(LL i=2,N=n<<1;i<=N;++i){
		if(i<Maxr) hw[i]=std::min(hw[(mid<<1)-i],hw[mid]-(i-mid));
		else hw[i]=1;
		while(s1[i-hw[i]]==s1[i+hw[i]]) ++hw[i];
		if(i+hw[i]>Maxr){
			Maxr=i+hw[i]; mid=i;
		}
		
	}
	for(LL i=3;i<=(n<<1);i+=2){
		if(s1[i+hw[i]]=='#') hw[i]--;
		else hw[i]-=2;
		hw[(i>>1)+1]=hw[i]+1;
	}
}
inline void Change2(){
	for(LL i=1,up=n>>1;i<=up;++i) T[i]=s[n+1-i],T[n+1-i]=s[i];
	for(LL i=2,j=0;i<=n;++i){
		while(T[j+1]!=T[i] && j) j=nxt[j];
		if(T[j+1]==T[i]) ++j,nxt[i]=j;
		else nxt[i]=0;
	}
	for(LL i=1,j=0;i<=n;++i){
		while(T[j+1]!=s[i] && j) j=nxt[j];
		if(T[j+1]==s[i]) ++j,suf[i]=j;
		else suf[i]=0;
	}
}
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	Change1();
	Manacher();
	Change2();
	for(LL i=1;i<=n;++i){
		if(suf[i]>=sux[i-1]) sux[i]=suf[i],sua[i]=i;
		else sux[i]=sux[i-1],sua[i]=sua[i-1];
	}
	for(LL i=1;i<=n;++i){
		if(ans<hw[i]+(std::min((sux[i-(hw[i]>>1)-1]),n-(i+(hw[i]>>1)))<<1)){
			ans=hw[i]+(std::min((sux[i-(hw[i]>>1)-1]),n-(i+(hw[i]>>1)))<<1);
			az=i; al=sua[i-(hw[i]>>1)-1];
		}
	}
	if((n-(az+(hw[az]>>1))) && al && suf[al]){
		puts("3");
		LL len(std::min(suf[al],n-(az+(hw[az]>>1))));
		printf("%d %d\n",al-len+1,len);
		printf("%d %d\n",az-(hw[az]>>1),hw[az]);
		printf("%d %d\n",n-len+1,len);
	}else{
		puts("1");
		printf("%d %d",az-(hw[az]>>1),hw[az]);
	}
	return 0;;
}