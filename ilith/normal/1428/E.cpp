#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[100010];
long long ct(long long x,long long c){
	long long zc1=x%c;
	long long zc=c-zc1;
	long long base=x/c;
	return base*base*zc+(base+1)*(base+1)*zc1;
}
struct node{
	long long id,cnt;
	bool operator < (const node & kk) const {
        return ct(a[id],cnt)-ct(a[id],cnt+1)<ct(a[kk.id],kk.cnt)-ct(a[kk.id],kk.cnt+1);
    }
};
priority_queue<node>q;
long long ans;
int main(){
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i]*a[i];
		q.push(node{i,1}); 
	}
	k-=n;
	while(!q.empty()&&(k--)){
		node now=q.top();
		ans-=ct(a[now.id],now.cnt)-ct(a[now.id],now.cnt+1);
		q.pop();
		now.cnt++;
		q.push(now);
	}
	cout<<ans;
	return 0;
}