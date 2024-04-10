#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
char In[1<<20],*Ss=In,*Tt=In;
//#define getchar() (Ss==Tt&&(Tt=(Ss=In)+fread(In,1,1<<20,stdin),Ss==Tt)?EOF:*Ss++)
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=2e5+10;
int a[N],m,n;
map<string,bool>vis;
string rev(string s){string t=s;reverse(t.begin(),t.end());return t;}
string s[N];
int main(){
	int T=read();
	while(T--){
		n=read();
		vis.clear();
		rep(i,n)cin>>s[i];
		bool ans=false;
		rep(i,n){
			string t=rev(s[i]);
			if(ans)break;
			if(s[i]==t){ans=true;break;}
			if(vis[t]){ans=true;break;}
			if(s[i].size()==2)For(j,'a','z')if(vis[t+(char)j]){ans=true;break;}
			if(s[i].size()==3)if(vis[rev(s[i].substr(1,2))]){ans=true;break;}
			vis[s[i]]=true;
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}