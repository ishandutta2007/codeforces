#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=2e5+10;
const LL INF=2e18;
char s[100]="What are you doing while sending \"";
char s2[100]="\"? Are you busy? Will you send \"";
char s3[100]="\"?";
char ss[100]="What are you doing at the end of the world? Are you busy? Will you save us?";
int len1,len2,len3,www;
void init(){
}

int n;
LL K;
LL F[100005];
void MAIN(){
	scanf("%d%lld",&n,&K);
	len1=strlen(s);len2=strlen(s2);len3=strlen(s3);www=strlen(ss);
	//cout<<len1<<" "<<len2<<" "<<len3<<" "<<www<<endl;
	F[0]=www;
	for(int i=1;i<=100000;++i){
		F[i]=len1+F[i-1]+len2+F[i-1]+len3;
		if(F[i]>INF) F[i]=INF;
	}
	//cout<<F[1]<<endl;
	if(F[n]<K){
		putchar('.');
		return;
	}
	for(int i=n;i>0;--i){
		if(K<=len1){
			putchar(s[K-1]);
			return;
		}
		K-=len1;
		if(K<=F[i-1]){
			continue;
		}
		K-=F[i-1];
		if(K<=len2){
			putchar(s2[K-1]);
			return;
		}
		K-=len2;
		if(K<=F[i-1]){
			continue;
		}
		K-=F[i-1];
		if(K<=len3){
			putchar(s3[K-1]);
			return;
		}
	}
	//cout<<K<<endl;
	putchar(ss[K-1]);
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}