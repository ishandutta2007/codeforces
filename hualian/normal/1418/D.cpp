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
}
multiset<int>res;
set<int>A;
void ins(int x){
	if(!A.size()){A.insert(x);return;}
	if(x<(*A.begin())){
		res.insert((*A.begin())-x);
		A.insert(x);
		return;
	}
	if(x>(*--A.end())){
		res.insert(x-(*--A.end()));
		A.insert(x);
		return;
	}
	auto nt=A.lower_bound(x);
	auto pre=nt;--pre;
	res.erase(res.lower_bound((*nt)-(*pre)));
	res.insert((*nt)-x);res.insert(x-(*pre));
	A.insert(x);return;
}
void del(int x){
	if(A.size()==1){A.clear();return;}
	if(x==(*A.begin())){
		A.erase(A.begin());
		res.erase(res.lower_bound((*A.begin())-x));
		return;
	}
	if(x==(*--A.end())){
		A.erase(--A.end());
		res.erase(res.lower_bound(x-(*--A.end())));
		return;
	}
	auto it=A.lower_bound(x);
	auto pre=it,nt=it;--pre;++nt;
	res.erase(res.lower_bound((*it)-(*pre)));
	res.erase(res.lower_bound((*nt)-(*it)));
	res.insert((*nt)-(*pre));
	A.erase(A.lower_bound(x));return;
}
void out(){
	if(A.size()<=2)puts("0");
	else cout<<((*--A.end())-(*A.begin()))-(*--res.end())<<endl;
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int n=read(),q=read();
	rep(i,n)ins(read());
	out();
	while(q--){
		int op=read();
		if(op==1)ins(read());
		else del(read());
		out();
	}
	return 0;
}