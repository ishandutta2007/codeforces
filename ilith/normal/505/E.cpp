#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,K,p,i,T,k;
long long l,r=6e12,x=1e9,t[N],h[N],a[N];
struct cmp{bool operator()(int x,int y){return t[x]/a[x]>t[y]/a[y];}};
int main(){
	cin>>n>>m>>K>>p;
	for(i=n;i;--i)cin>>h[i]>>a[i],h[i]+=a[i]*m;
	for(;r>l+1;x=(l+r)/2){
		priority_queue<int,vector<int>,cmp>s;
		for(i=n;i;--i)if(x<h[i])t[i]=x,s.push(i);
		for(T=1;T<=m;++T)for(i=K;i&&s.size();--i){
			if(t[k=s.top()]-T*a[k]<0)goto tag;
			s.pop();
			if((t[k]+=p)<h[k])s.push(k);
		}
		tag:s.size()?l=x:r=x;
	}cout<<r;
}