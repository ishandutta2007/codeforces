//https://codeforces.com/contest/1268/problem/A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}

const int N=200005;
int a[N],b[N];char s[N];int nn,kk,k1;
inline int judge(){
	int i;
	for(i=k1;i<=nn;++i)b[i]=b[i-kk];
//	for(i= 0;i<=nn;++i)printf("%d ",b[i]);printf("\n");
	for(i= 0;i<=nn;++i)if(a[i]!=b[i])return a[i]<b[i];
	return 1;
}
inline void chk(){
	if(judge()){
		printf("%d\n",nn+b[0]);
		if(b[0])putchar(b[0]^48);
		for(int i=1;i<=nn;++i)putchar(b[i]^48);
		exit(0);
	}
}
int main(){
	int n,k,i;
	scanf("%d%d%s",&n,&k,s+1);nn=n;k1=(kk=k)+1;
	for(i=1;i<=n;++i)a[i]=s[i  ]^48;
	for(i=1;i<=k;++i)b[i]=a[i  ];
	chk();
	for(i=k;  ~i;--i){
		if(b[i]==9)b[i]=0;
		else{++b[i];break;}
	}
	if(b[0])b[k]=1;
	chk();
	return 0;
}