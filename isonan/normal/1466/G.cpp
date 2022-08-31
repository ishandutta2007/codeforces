#include <cstdio>
#include <algorithm>
#include <cstring>

int n,q;
const int P=1000000007;
	inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
	inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
	inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
	int qsm(int a,int b){
		int ans=1;
		while(b){
			if(b&1)ans=mul(ans,a);
			a=mul(a,a);
			b>>=1;
		}
		return ans;
	}
char s[101],t[1000001],T[1000001];
int stk[100001],top,Pow[500001];
int Sum[100001][26],nxt[100001][26],last[100001];
int checksame(int l,int r,int top){
		int p=T[l]==stk[1]?std::min(last[l]-1,r):l-1;
		int ans=0;
		if((p-l+1)>25||((1ll<<(p-l+1))-top>=0))ans=add(ans,mul(Pow[r-p],sub(Pow[p-l+1],top)));
		int tem=mul(Pow[r],sub(Sum[r][stk[1]-'a'],p>=0?Sum[p][stk[1]-'a']:0));
		if((p-l+1)>25||((1ll<<(p-l+1))-top>=0))ans=sub(ans,mul(2*tem,sub(Pow[p-l+1],top)));
		++p;
		if((p-l+1)>25||((1ll<<(p-l+1))-top>=0))ans=add(ans,mul(tem,sub(Pow[p-l+1],top)));
//		printf("%d\n",ans);
		return ans;
	
}
int check(int l,int r,int top){
	if((r-l+1)<=20&&(1ll<<(r-l+1))-1<top)return 0;
	bool b1=1,b2=1;
	for(int i=1;i<=top;i+=2)
		b1&=(stk[i]==T[l]);
	for(int i=2;i<=top;i+=2)
		b2&=(stk[i]==T[l]);
//	printf("check %d %d %d %d %d\n",l,r,top,b1,b2);
	if(b1&&b2){
		return checksame(l,r,top);
	}
	else if(b1){
		for(int i=2;i<=top;i+=2)
			stk[i>>1]=stk[i];
		return check(l+1,r,top>>1);
	}
	else if(b2){
		for(int i=1;i<=top;i+=2)
			stk[(i+1)>>1]=stk[i];
		return check(l+1,r,(top+1)>>1);
	}
	else return 0;
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&q);
	scanf("%s%s",s,T);
	Pow[0]=1;
	for(int i=1;i<=100000;i++)Pow[i]=add(Pow[i-1],Pow[i-1]);
	int m=strlen(s)+1;
	for(int i=0;i<n;i++){
		Sum[i][T[i]-'a']=add(Sum[i][T[i]-'a'],qsm(Pow[i],P-2));
		for(int j=0;j<26;j++)
			Sum[i+1][j]=Sum[i][j];
	}
	for(int i=0;i<26;i++)nxt[n-1][i]=n;
	for(int i=n-2;~i;i--){
		for(int j=0;j<26;j++)nxt[i][j]=nxt[i+1][j];
		nxt[i][T[i]-'a']=i;
	}
	last[n-1]=n;
	for(int i=n-2;~i;--i){
		if(T[i]==T[i+1])last[i]=last[i+1];
		else last[i]=i+1;
	}
	for(int i=1,k;i<=q;i++){
//		if(i%1000==0)fprintf(stderr,"%d\n",i);
		k=read();
		scanf("%s",t+1);
		int nl=strlen(t+1);
	int ans=0;
		bool same=1;
		int p=0;
		for(int j=1;j<=nl;j++){
			same&=(j+m>nl||t[j]==t[j+m]);
			if(!((j+m>nl||t[j]==t[j+m]))){
				if(!p||p%m==j%m)p=j;
				else p=-1;
			}
		}
//		printf("%d\n",p);
		if(p!=-1){
		for(int j=0;j<m;j++){
			bool good=1;
			top=0;
			for(int k=1,This=j;k<=nl;k++,(This==m-1)?This=0:(++This)){
				good&=(This==m-1||t[k]==s[This]);
				if(This==m-1)stk[++top]=t[k];
				if(This!=m-1&&p&&k%m==p%m)good=0;
				if(!good)break;
			}
			if(good){
//				printf("%d %d\n",j,top);
				if(!top)ans=add(ans,Pow[k]);
				else if(k){
					if(same)ans=add(ans,checksame(0,k-1,top));
					else ans=add(ans,check(0,k-1,top));
				}
			}
		}
		}
		write(ans);
		putchar('\n');
	}
}