#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=100+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
char s[N],t[N];
int last[26],j;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	while(n--){
		scanf("%s%s",s+1,t+1);
		memset(last,0,sizeof last);
		int l1=strlen(s+1);
		int l2=strlen(t+1);
		rep(i,l2)last[t[i]-'A']++;
		j=l2;int f=1;
		Rof(i,l1,1){
			if(last[s[i]-'A']){
				last[s[i]-'A']--;
				if(t[j]!=s[i]){f=0;break;}
				j--;if(j==0)break;
			}
		}if(j!=0)f=0;
		puts(f?"YES":"NO");
	}
	return 0;
}