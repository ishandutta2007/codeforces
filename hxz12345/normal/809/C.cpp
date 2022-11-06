#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
/*
0:
1:
2: 
*/
long long MOD,Testing,valA,valB,valC,i,K,tagA,tagB,tagC,f[33][3][3][3],e[33][3][3][3],Xa,Xb,Ya,Yb,lst1,lst2,now1,now2,lst3,A,B,C,tot;
long long Va(long long x,long long y){if (x==y) return 1;if (x<y) return 0;return 2; } 
long long Vb(long long x,long long y,long long z){
	if ((x<y)) return 0;if (x>y) return 2;return z;
}
long long calc(long long n,long long m){
	if ((n<0)||(m<0)) return 0;
	for (i=0;i<=30;i++) for (A=0;A<=2;A++) for (B=0;B<=2;B++) for (C=0;C<=2;C++) f[i][A][B][C]=e[i][A][B][C]=0;
    for (A=0;A<=1;A++)
       for (B=0;B<=1;B++)
           f[0][Va(A,n&1)][Va(B,m&1)][Va(A^B,K&1)]+=A^B,e[0][Va(A,n&1)][Va(B,m&1)][Va(A^B,K&1)]++;
	for (i=1;i<=30;i++)
        for (lst1=0;lst1<=2;lst1++)
           for (lst2=0;lst2<=2;lst2++)
             for (lst3=0;lst3<=2;lst3++)
                for (now1=0;now1<=1;now1++)
                   for (now2=0;now2<=1;now2++){
                   	   tagA=((n&(1ll<<i))>0);tagB=((m&(1ll<<i))>0);tagC=((K&(1ll<<i))>0);
                   	   valA=Vb(now1,tagA,lst1);valB=Vb(now2,tagB,lst2);valC=Vb(now1^now2,tagC,lst3);
                   	   f[i][valA][valB][valC]+=((now1^now2)*(1ll<<i)*e[i-1][lst1][lst2][lst3])+f[i-1][lst1][lst2][lst3];
                   	   f[i][valA][valB][valC]%=MOD;
                   	   e[i][valA][valB][valC]+=e[i-1][lst1][lst2][lst3];
                   	   e[i][valA][valB][valC]%=MOD;
				   }
	long long tot=0;
	for (lst1=0;lst1<=1;lst1++)
	   for (lst2=0;lst2<=1;lst2++)
	      for (lst3=0;lst3<=1;lst3++)
	        tot=(tot+f[30][lst1][lst2][lst3]+e[30][lst1][lst2][lst3]) % MOD;
	return tot;
}
void Main(){
	Xa=read();Ya=read();Xb=read();Yb=read();K=read();
	Xa--;Ya--;Xb--;Yb--;K--;
	tot=calc(Xb,Yb)-calc(Xa-1,Yb)-calc(Xb,Ya-1)+calc(Xa-1,Ya-1);
	tot=(tot % MOD+MOD) % MOD;
	printf("%lld\n",tot);     
	return ;
}
int main()
{//a[i][j]=(i-1)^(j-1)+1
Testing=read();MOD=1e9+7;
for (;Testing;Testing--) Main();
return 0;
}