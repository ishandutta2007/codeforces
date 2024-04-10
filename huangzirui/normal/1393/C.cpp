#include<bits/stdc++.h>
#define Mid (L+R>>1)
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=1e5+5;
struct node{
	int s,id,S;
	bool operator<(const node& a) const{
		return a.s>s;
	}
}s[maxn];
int i,j,k,n,m,a[maxn];
priority_queue<node>Q;
int use[maxn];
bool check(int h){
	for(i=1;i<=n;i++)if(s[i].s)Q.push(s[i]);
//	cout<<"h="<<h<<endl;
	for(i=1;i<=n;i++){
		if(i>h && s[use[i-h]].s)Q.push(s[use[i-h]]);
		if(Q.empty())return 0;
		use[i]=Q.top().id;
		s[use[i]].s--;
		Q.pop();
//		cout<<use[i]<<endl;
	}return 1;
}
int main(){
	int T=read();
	while(T--){
		n=read();
		for(i=1;i<=n;i++)s[i]={0,i};
		for(i=1;i<=n;i++)a[i]=read(),s[a[i]].s++,s[a[i]].S++;
		int L=1,R=n;
		while(L<=R){
			for(i=1;i<=n;i++)s[i].s=s[i].S; 
			if(check(Mid))L=Mid+1;
			else R=Mid-1;
		}printf("%d\n",L-2);
	}
	return 0;
}