#include<bits/stdc++.h>
using namespace std;
const int sed=2;
const int mod1=1e9+7;
const int mod2=1e9+87;
const int M=1e6+9;
int n,k;
char s[M],t[M];
struct Hash{
	int x1,x2;
	Hash(int t1=0,int t2=0):x1(t1),x2(t2){}
	bool operator <  (const Hash&o)const{return x1==o.x1?x2<o.x2:x1<o.x1;}
	Hash operator +  (const Hash&o)const{return Hash((x1+o.x1)%mod1,(x2+o.x2)%mod2);}
	Hash operator -  (const Hash&o)const{return Hash((x1-o.x1+mod1)%mod1,(x2-o.x2+mod2)%mod2);}
	Hash operator +  (const int&o)const{return Hash((x1+o)%mod1,(x2+o)%mod2);}
	Hash operator *  (const int&o)const{return Hash(1ll*x1*o%mod1,1ll*x2*o%mod2);}
};
void work(){
	set<Hash>in;
	scanf("%d%d%s",&n,&k,s+1);
	Hash ha,pw=Hash{1,1};
	for(int i=1;i<=n;++i)s[i]=(s[i]-'0')?'0':'1'; 
	for(int i=1;i<=k;++i)pw=pw*sed;
	for(int i=n;i>=1;--i){
		ha=ha*sed+(s[i]-'0');
		if(n>=k+i)ha=ha-pw*(s[i+k]-'0');
		if(n-i+1>=k)in.insert(ha);
	}
	for(int i=0;i<=n;++i){
		Hash h;
		for(int j=1,x=i;j<=k;++j,x>>=1)
			h=h*sed+x%2;
		if(in.find(h)==in.end()){
			printf("YES\n");
			vector<int>g;
			for(int j=1,x=i;j<=k;++j,x>>=1)g.push_back(x%2);
			for(int j=k-1;j>=0;--j)printf("%d",g[j]);
			break;
		}
		if(k<31&&i>(1<<k)){
			printf("NO\n");
			break;
		}
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
11 10
11111111110
*/