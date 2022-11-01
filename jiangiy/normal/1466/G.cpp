#include<bits/stdc++.h>
#define fi first
#define se second
#define ULL unsigned long long
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100005,M=1000005,MOD=1000000007;
int P;
struct hash{
	ULL a;
	int b;
	hash(){
		a=0,b=0;
	}
	hash(int x){
		a=x,b=x;
	}
	hash&operator+=(const hash&x){
		a+=x.a,b+=x.b;
		b>=P?b-=P:0;
		return*this;
	}
	hash&operator-=(const hash&x){
		a-=x.a,b-=x.b;
		b<0?b+=P:0;
		return*this;
	}
	hash&operator*=(const hash&x){
		a*=x.a,b=(LL)b*x.b%P;
		return*this;
	}
	hash operator+(const hash&x)const{
		hash t=*this;
		t+=x;
		return t;
	}
	hash operator-(const hash&x)const{
		hash t=*this;
		t-=x;
		return t;
	}
	hash operator*(const hash&x)const{
		hash t=*this;
		t*=x;
		return t;
	}
	bool operator==(const hash&x)const{
		return a==x.a&&b==x.b;
	}
	bool operator!=(const hash&x)const{
		return a!=x.a||b!=x.b;
	}
}
po[M*2],hs[M*2],sp[M*2],ss[M*2];
int n,m,tl,u,ql,po2[N],le[25],tcnt[26],cnt[N][26];
char a[N],s[25][M*2],qs[M];
bool match[M];
bool isprime(int x){
	for(int i=2;i*i<=x;i++) if(x%i==0)return 0;
	return 1;
}
int basic_qry(int x){
	if(le[x]<ql)return 0;
	int res=0;
	hash t(0);
	for(int i=1;i<=ql;i++)t=t*po[1]+(qs[i]-96);
	for(int i=ql;i<=le[x];i++){
		int p=i-ql;
		if(hs[i]-hs[p]*po[ql]==t)res++;
	}
	return res;
}
int main(){
	void*ttt=alloca(1);
	std::mt19937 ran(*(ULL*)&ttt^time(0));
	P=1000000000-ran()%100000000;
	while(!isprime(P))P++;
	po[1].a=ran()%10000000+27;
	while(!isprime(po[1].a))po[1].a++;
	po[1].b=ran()%10000000+27;
	while(!isprime(po[1].b))po[1].b++;
	po[0]=1;
	for(int i=2;i<=M*2-1;i++)po[i]=po[i-1]*po[1];
	po2[0]=1;
	for(int i=1;i<=N-1;i++)po2[i]=po2[i-1]*2%MOD;
	scanf("%d%d",&n,&m);
	memset(a,97,sizeof(a));
	scanf("%s%s",s[1]+1,a+1);
	tl=strlen(s[1]+1),u=1,le[1]=tl;
	while(tl<=1000000){
		for(int i=1;i<=tl;i++)s[u+1][i]=s[u][i];
		s[u+1][tl+1]=a[u];
		for(int i=1;i<=tl;i++)s[u+1][i+tl+1]=s[u][i];
		tl=tl*2+1;
		le[++u]=tl;
	}
	for(int i=u+1;i<=n+1;i++){
		for(int j=0;j<26;j++)cnt[i][j]=cnt[i-1][j]*2%MOD;
		cnt[i][a[i-1]-97]++;
	}
	for(int i=1;i<=tl;i++)hs[i]=hs[i-1]*po[1]+(s[u][i]-96);
	for(int i=1;i<=tl;i++)sp[i]=sp[i-1]+po[i-1]*(s[u][i]-96);
	for(int i=1;i<=tl;i++)ss[i]=ss[i-1]+po[i-1]*(s[u][tl+1-i]-96);
	while(m--){
		int x;
		scanf("%d%s",&x,qs+1);
		x++;
		ql=strlen(qs+1);
		int pos=1;
		while(le[pos]<ql)pos++;
		if(x<pos){
			puts("0");
			continue;
		}
		if(x==pos){
			printf("%d\n",basic_qry(x));
			continue;
		}
		for(int i=0;i<26;i++)tcnt[i]=cnt[x][i];
		for(int i=pos;i<=std::min(u,x)-1;i++)tcnt[a[i]-97]=(tcnt[a[i]-97]+po2[x-1-i])%MOD;
		int a1=basic_qry(pos),ans=(LL)a1*po2[x-pos]%MOD;
		hash t(0);
		for(int i=1;i<=ql;i++)match[i]=1;
		for(int i=1;i<=ql;i++){
			if(t!=ss[i-1])match[i]=0;
			t=t*po[1]+(qs[i]-96);
		}
		t=0;
		for(int i=ql;i;i--){
			if(t!=sp[ql-i])match[i]=0;
			t=t*po[1]+(qs[i]-96);
		}
		for(int i=1;i<=ql;i++) if(match[i])ans=(ans+tcnt[qs[i]-97])%MOD;
		printf("%d\n",ans);
	}
}