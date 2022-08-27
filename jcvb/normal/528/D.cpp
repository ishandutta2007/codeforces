#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;


int n,m,k;
char S[200005];
char T[200005];
int ans[4][200005];


struct prz{
	int id,sg;	
}po[666666];int ptot;
int cmp(const prz&a,const prz&b){

	return a.id<b.id;
}
int xxx[200005];
#include<cmath>
#define pi 3.14159265358979323846264338327950288
using namespace std;
struct cp{
       double a,b;
       cp operator+(const cp&x)const{return (cp){a+x.a,b+x.b};}
       cp operator-(const cp&x)const{return (cp){a-x.a,b-x.b};}
       cp operator*(const cp&x)const{return (cp){a*x.a-b*x.b,a*x.b+b*x.a};}
};
void rev(cp *a,int n){
    int i,j,k;
    for (i=1,j=n>>1;i<n-1;i++){
        if(i<j)swap(a[i],a[j]);                                 
        for (k=n>>1;j>=k;j-=k,k>>=1);j+=k;
    }
}
void dft(cp *a,int n,int flag=1){
     rev(a,n);
     for (int m=2;m<=n;m<<=1){
         cp wm;
	 wm=(cp){cos(flag*2*pi/m),sin(flag*2*pi/m)};
         for (int k=0;k<n;k+=m){
             cp w;w=(cp){1.0,0.0};
             for (int j=k;j<k+(m>>1);j++,w=w*wm){
                 cp u=a[j],v=a[j+(m>>1)]*w;
                 a[j]=u+v;
                 a[j+(m>>1)]=u-v;
             }
         }
     }     
}
void mul(cp *a,cp *b,int n){
     dft(a,n);dft(b,n);
     for (int i=0;i<n;i++)a[i]=a[i]*b[i];
     dft(a,n,-1);for (int i=0;i<n;i++)a[i].a/=n;
}
cp s1[555555],s2[555555];
int N;
void work(int *ans,char c){

	ptot=0;
	for (int i=1;i<=n;i++)if(S[i]==c){
		int l=max(1,i-k),r=min(n,i+k);
		po[++ptot]=(prz){l,1};
		po[++ptot]=(prz){r+1,-1};
	}
	sort(po+1,po+1+ptot,cmp);
	int s=0;
	for (int i=1,cur=1;i<=n;i++){
		while(cur<=ptot && po[cur].id==i)s+=po[cur++].sg;
		if(s==0)xxx[i]=0;
		else xxx[i]=1;
	}
	for (int i=0;i<2*N;i++)s1[i]=s2[i]=(cp){0.0,0.0};
	for (int i=1;i<=n;i++)if(xxx[i])s1[i]=(cp){1.0,0.0};
	int cnt=0;
	for (int i=1;i<=m;i++)if(T[i]==c)s2[m-i]=(cp){1.0,0.0},cnt++;
	mul(s1,s2,2*N);
	for (int i=1;i<=n;i++){
		int xx=int(s1[i].a+0.5);
		if(xx==cnt)ans[i]=1;
		else ans[i]=0;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	N=1;
	while(n+3>=N)N<<=1;
	scanf("%s",S+1);
	scanf("%s",T+1);
	work(ans[0],'A');
	work(ans[1],'T');
	work(ans[2],'G');
	work(ans[3],'C');
	int su=0;
	for (int i=1;i<=n;i++){
		int t=1;
		for (int j=0;j<4;j++)t=t&&ans[j][i];
		su+=t;
	}
	printf("%d\n",su);
	return 0;
}