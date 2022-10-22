#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
char In[1<<20],*Ss=In,*Tt=In;
#define getchar() (Ss==Tt&&(Tt=(Ss=In)+fread(In,1,1<<20,stdin),Ss==Tt)?EOF:*Ss++)
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
set<int>s[maxn];
int main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=0;i<=n;++i)set<int>().swap(s[i]);
		for(int i=1;i<=n;++i)a[i]=read(),s[a[i]].insert(i);
		vector<int>ans;
		for(int i=1;i<=n;){
			int j=i;
			for(int k=0;k<=n;++k){
				if(s[k].lower_bound(i)==s[k].end()){
					ans.push_back(k);
					break;
				}
				chmx(j,*s[k].lower_bound(i));
			}
			i=j+1;
		}
		printf("%d\n",ans.size());
		for(int i:ans)printf("%d ",i);
		printf("\n");
	}
	return 0;
}