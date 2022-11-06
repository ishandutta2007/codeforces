#include<bits/stdc++.h>
#define ri register int
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
	#undef gc
}
const int N=3e5+5;
int n;
typedef pair<int,int> pii;
struct Node{int x,y,id;};
vector<Node>a,b;
inline bool cmp(const Node&a,const Node&b){return a.y>b.y;}
int main(){
	n=read();
	for(ri i=1,x,y;i<=n;++i){
		x=read(),y=read();
		if(x<y)a.push_back((Node){x,y,i});
		else b.push_back((Node){y,x,i});
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	reverse(b.begin(),b.end());
	if(a.size()>=b.size()){
		cout<<a.size()<<'\n';
		for(ri i=0;i<a.size();++i)cout<<a[i].id<<' ';
		return 0;
	}
	else{
		cout<<b.size()<<'\n';
		for(ri i=0;i<b.size();++i)cout<<b[i].id<<' ';
		return 0;
	}
	return 0;
}