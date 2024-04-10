#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
const int N=4e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int max(int &x,int &y){return x>y?x:y;}
int n,m,idx;
int a[N];
map<int,int>mp;
vector<int>had[N];
vector<int>pos[N];
int last[N],pre[N],nt[N];
int mx[20][N];
multiset<int>s;
void clear(){
	mp.clear();idx=0;s.clear();
	For(i,0,n+1){
		had[i].clear();pos[i].clear();
		last[i]=0;
		pre[i]=nt[i]=0;
		mx[0][i]=0;
	}
}
void init(){
	rep(k,18)rep(i,n-(1<<k)+1)
		mx[k][i]=max(mx[k-1][i],mx[k-1][i+(1<<k-1)]);
}
int get(int l,int r){
	int k=__lg(r-l+1);
	return max(mx[k][l],mx[k][r-(1<<k)+1]);
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();while(T--){
		clear();n=read(),m=read();
		rep(i,n)pos[i].push_back(0);
		rep(i,n){
			a[i]=read();
			if(!mp.count(a[i]))mp[a[i]]=++idx;
			a[i]=mp[a[i]];pos[a[i]].push_back(i);
			pre[i]=last[a[i]];nt[last[a[i]]]=i;
			last[a[i]]=i;
		}nt[0]=0;
		rep(i,n)pos[i].push_back(n+1);
		rep(i,m){
			int l=read(),r=read();
			chmx(mx[0][l],r);
		}init();
		rep(i,n){
			// 
			int R=get(pre[i]+1,i);
			R=*--upper_bound(pos[a[i]].begin(),pos[a[i]].end(),R);
			if(R<i)continue;assert(a[R]==a[i]);
			if(R!=i)had[0].push_back(pre[R]),had[i+1].push_back(-pre[R]);
			if(!nt[i])continue;
			R=get(pre[i]+1,i);
			R=*--upper_bound(pos[a[i]].begin(),pos[a[i]].end(),R);
			if(R<nt[i])continue;assert(a[R]==a[i]);
			assert(R!=i);had[i+1].push_back(R);had[nt[i]+1].push_back(-R);
			
			had[nt[i]+1].push_back(1e9);
		}
		
		int ans=1e9;s.insert(0);
		For(i,0,n){
			for(int to:had[i]){
				if(to>0)s.insert(to);
				else{
					auto it=s.lower_bound(-to);
					assert(*it==-to);
					s.erase(it);
				}
		 	}
			if(i)chmn(ans,max((*--s.end())-i+1,0));
		}	cout<<ans<<endl;
	}
	return 0;
}