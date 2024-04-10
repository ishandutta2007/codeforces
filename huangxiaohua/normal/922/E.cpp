#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t;

struct sb{
	int id,lim;
	ll cur;
	bool operator<(const sb x)const{return cur<x.cur;}
}s[10050],s1;
ll f[10050],m,mp,mp1,mp2,a[1050],c[1050],num;
priority_queue<struct sb> q;
bool f2[10050];
ll get(ll x,ll y,ll z){
	if(y<=0){return x;}
	return min(x,z/y);
}

int main(){
	scanf("%d%lld%lld%lld",&n,&m,&mp1,&mp2);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		num+=a[i];
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	s[0].lim=get(a[1],c[1],m);
	s[0].cur=m-num*c[1];
	
	f2[0]=1;
	for(i=1;i<=n;i++){
		while(!q.empty()){q.pop();}
		memset(f,-1,sizeof(f));
		for(j=0;j<=num;j++){
			if(f2[j]){
				q.push(s[j]);
			}
			while(!q.empty()&&q.top().lim<j){q.pop();}
			if(q.empty()){break;}
			s1=q.top();
			f[j]=s1.cur+(num-j)*c[i];
		}
		memset(f2,0,sizeof(f2));
		for(j=0;j<=num;j++){
			if(f[j]==-1){break;}
			if(f[j]<-1){
				return 1;
			}
			f2[j]=1;
			s[j].id=j;
			s[j].cur=min(m+j*mp1,mp2+f[j]);
			
			s[j].lim=j+get(a[i+1],c[i+1],s[j].cur);
			s[j].cur-=(num-j)*c[i+1];
		}
	}
	for(i=num;;i--){
		if(f2[i]){
			printf("%d",i);return 0;
		}
	}
}