#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
inline int qinv(int x){return qpow(x,mod-2);}
/* math */
typedef vector<int> poly;

poly mul(poly a,poly b){
	poly ret(a.size()+b.size()-1,0);
	for(size_t i=0;i<a.size();i++)for(size_t j=0;j<b.size();j++)
		ret[i+j]=add(ret[i+j],mul(a[i],b[j]));
	return ret;
}
poly add(poly a,poly b){
	a.resize(max(a.size(),b.size()));
	for(size_t i=0;i<b.size();i++){
		a[i]=add(a[i],b[i]);
	}
	return a;
}
poly Mod(poly a,poly b){
	// for(size_t i=0;i<a.size();i++)cout << a[i] << " ";puts(">>");
	int inv=qinv(b[b.size()-1]);
	for(size_t i=a.size()-1;i+1>=b.size();i--)if(a[i]!=0){
		int t=mul(a[i],inv);
		for(int d=(int)b.size()-1,pos=i;~d;d--,pos--){
			a[pos]=sub(a[pos],mul(b[d],t));
		}
	}
	// for(size_t i=0;i<a.size();i++)cout << a[i] << " ";puts("<<");
	a.resize(b.size()-1);
	return a;
}
int F,B;ll n;
int A[20];
int b[2010];
int Mx = 0;
poly Final;
int main()
{
	cin >> F >> B >> n;
	for(int i=1;i<=F;i++)scanf("%d",&A[i]);
	for(int i=1;i<=B;i++){
		scanf("%d",&b[i]);
		Mx=max(b[i],Mx);
	}
	vector<int> M(Mx+1,0);M[Mx]=1;
	for(int i=1;i<=B;i++)M[Mx-b[i]]=sub(M[Mx-b[i]],1);
	// for(int i=0;i<=Mx;i++)cout << M[i] << " ";puts("");
	for(int i=1;i<=F;i++){
		poly temp=poly(2,0);temp[1]=1;
		poly cur=poly(1,1);
		while(A[i]){
			if(A[i]&1){
				cur=mul(cur,temp);
				cur=Mod(cur,M);
			}
			A[i]>>=1;
			temp=mul(temp,temp);
			temp=Mod(temp,M);
		}
		Final=add(Final,cur);
	}
	Final.resize(Mx);
	poly cur=poly(1,1);
	poly temp=Final;
	// for(int i=0;i<Mx;i++)cout << Final[i] << " ";puts("");
	while(n){
		if(n&1){
			cur=mul(cur,temp);
			cur=Mod(cur,M);
		}
		n>>=1;
		temp=mul(temp,temp);
		temp=Mod(temp,M);
	}
	Final=cur;
	// for(int i=0;i<Mx;i++)cout << Final[i] << " ";puts("");
	for(int i=Mx-1;i;i--){
		for(int d=1;d<=B;d++){
			if(i-b[d]>=0)Final[i-b[d]]=add(Final[i-b[d]],Final[i]);
		}
	}
	cout << Final[0] << endl;
}