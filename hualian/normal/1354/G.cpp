#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}string S;
int n,k,s,nt,T,id[100010];
void solve(int l,int r){
	while(l<=r){
		int mid=(l+r)>>1,len=mid-l+1;;
		printf("? %d %d\n",len,len);
		rep(i,len)printf("%d ",id[i]);puts("");
		For(i,l,mid)printf("%d ",id[i]);cout<<endl;
		cin>>S;if(S=="FIRST")r=mid-1;
		else l=mid+1;
	}
	cout<<"! "<<id[r+1]<<endl;
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	T=read();while(T--){
		n=read(),k=read();s=1;
		rep(i,20){
			do{nt=rand()%n+1;}while(nt==s);
			printf("? 1 1\n%d\n%d",s,nt);cout<<endl;
			cin>>S;if(S=="SECOND")s=nt;
		}//
		rep(i,n)id[i]=i;For(i,2,s)id[i]=i-1;id[1]=s;
		int len=1,f=1;
		while(1){
			if(len*2>n&&!f){
				cout<<"! "<<id[n]<<endl;
				break;
			}
			if(len*2>n&&f)len=n/2,f=0;
			printf("? %d %d\n",len,len);
			rep(i,len)cout<<id[i]<<" ";puts("");
			For(i,len+1,2*len)cout<<id[i]<<" ";cout<<endl;
			cin>>S;
			if(S=="FIRST"){solve(len+1,2*len);break;}
			len*=2;
		}
	}
	return 0;
}/////////////