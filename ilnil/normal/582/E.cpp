#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ff(i,a,b)for(int i=a,_e=b;i<_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=(1<<16)+5,M=1<<16,mo=1e9+7;
int n,ds,f[100][N],g[N],op[100];
char c[505];
bool ex[100];
inline void up(int &x){x+=(x>>31)&mo;}
void fwt(int *a,int op){
	if(op==1){
		for(int i=1;i<M;i<<=1)for(int j=0;j<M;j+=i*2)
			ff(k,0,i)up(a[i+j+k]+=a[j+k]-mo);
	}else{
		for(int i=1;i<M;i<<=1)for(int j=0;j<M;j+=i*2)
			ff(k,0,i)up(a[j+k]+=a[i+j+k]-mo);
	}
}
void ifwt(int *a,int op){
	if(op==1){
		for(int i=1;i<M;i<<=1)for(int j=0;j<M;j+=i*2)
			ff(k,0,i)up(a[i+j+k]-=a[j+k]);
	}else{
		for(int i=1;i<M;i<<=1)for(int j=0;j<M;j+=i*2)
			ff(k,0,i)up(a[j+k]-=a[i+j+k]);
	}
}
void doit(int *h,int *f,int *g,int op){
	static int a[N],b[N];
	memcpy(a,f,sizeof a);
	memcpy(b,g,sizeof b);
	fwt(a,op);
	fwt(b,op);
	fo(i,0,65535)a[i]=(ll)a[i]*b[i]%mo;
	ifwt(a,op);
	fo(i,0,65535)up(h[i]+=a[i]-mo);
}
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	fo(i,1,n){
		if(c[i]=='('){
			++ds;ex[ds]=0;
			memset(f[ds],0,sizeof f[ds]);
			continue;
		}
		if(c[i]==')'){
			if(ex[ds-1]){
				memset(g,0,sizeof g);
				if(op[ds-1]&1)doit(g,f[ds-1],f[ds],1);
				if(op[ds-1]&2)doit(g,f[ds-1],f[ds],2);
				memcpy(f[ds-1],g,sizeof g);
			}else{
				memcpy(f[ds-1],f[ds],sizeof f[ds]);
				ex[ds-1]=1;
			}
			--ds;
			continue;
		}
		if(c[i]<='D'&&c[i]>='A'||c[i]<='d'&&c[i]>='a'){
			ex[ds]=1;
			int s=0,w=0,x=0;
			if(c[i]>='A'&&c[i]<='D')w=c[i]-'A';
			else w=c[i]-'a',x=1;
			fd(i,0,15)
				s=s*2+(((i&(1<<w))>0)^x);
			f[ds][s]=1;
			continue;
		}
		if(c[i]=='|'||c[i]=='&'){
			op[ds]=c[i]=='|'?1:2;
			continue;
		}
		if(ex[ds])op[ds]=3;else{
			ex[ds]=1;
			fo(w,0,3)fo(x,0,1){
				int s=0;
				fd(i,0,15)s=s*2+(((i&(1<<w))>0)^x);
				f[ds][s]=1;
			}
		}
	}
	int s=0,s2=0,a,b,c,d,e;ll ans=0;
	cin>>n;
	fo(i,1,n)cin>>a>>b>>c>>d>>e,s2^=1<<(d*8+c*4+b*2+a),s^=e?1<<(d*8+c*4+b*2+a):0;
	ff(i,0,M)if((i&s2)==s)ans+=f[0][i];
	cout<<ans%mo;
}