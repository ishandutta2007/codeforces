#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,t,p[110000],q[110000];
char Getchar(){
    static char now[1<<20],*S,*T;
    if (T==S){
        T=(S=now)+fread(now,1,1<<20,stdin);
        if (T==S) return EOF;
    }
    return *S++;
}
int read(){
    int x=0,f=1;
    char ch=Getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=Getchar();
    }
    while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
    return x*f;
}
bool isprime(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0) return false;
	return true;
}
ll qpow(ll x,ll a,int Mod){
    ll res=1;
    while (a){
        if (a&1) res=res*x%Mod;
        x=x*x%Mod; a>>=1;
    }
    return res;
}

int getroot(int x){
	int tmp=x-1,tot=0;
	for (int i=2;i*i<=tmp;i++)
		if (tmp%i==0){
			q[++tot]=i;
			while (tmp%i==0) tmp/=i;
		}
	if (tmp>1) q[++tot]=tmp;
	int i;
	for (int g=2;g<=x-1;g++){
		for (i=1;i<=tot;i++)
			if (qpow(g,(x-1)/q[i],x)==1) break;
		if (i==tot+1) return g;
	}
	return -1;
}

//bool vis[110000];
void solve(bool flag){
	if (flag){
		if (n==2){
			puts("YES");
			puts("1 2");
			return;
		}
		if (n==4){
			puts("YES");
			puts("1 3 2 4");
			return;
		}
		if (!isprime(n)){
			puts("NO");
			return;
		}
		n--;
	}
	if (n&1){
		puts("NO");
		return;
	} else{
		p[1]=n;
		for (int i=1;i<n;i++)
			if (i&1) p[i+1]=i;
			else p[i+1]=n-i;
	}
	if (flag){
		n++; p[n]=n;
		int g=getroot(n);
		q[0]=1; for (int i=1;i<n;i++) q[i]=1ll*q[i-1]*g%n;
		for (int i=1;i<n;i++) p[i]=q[p[i]%n];
//		ll mul=1;
//		for (int i=1;i<n;i++){
//			mul=mul*p[i]%n;
//			assert(!vis[p[i]]);
//			vis[p[i]]=true;
//			printf("%d ",mul);
//		}
//		puts("");
	}
	puts("YES");
	for (int i=1;i<n;i++) printf("%d ",p[i]);
	printf("%d\n",p[n]);
}
int main(){
    n=read(); //t=read();
    if (n==1){
        puts("YES");
        puts("1"); return 0;
    }
    solve(true);
	return 0;
}