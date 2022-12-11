#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int w1,w5,n,K,t[210000];
long long A[210000];
priority_queue<long long>Q;
long long solve(int k1){
	while (!Q.empty()) Q.pop();
	long long ans=1e18,tot=0;
	for (int now=1;now<=n;now++){
		int a=t[now]%5,b=t[now]/5; long long w=0;
		if (k1>=a)
			w=-1ll*b*w5+1ll*(k1-a)*w1;
		else w=-1ll*(b+1)*w5+1ll*(k1-a+5)*w1;
	//	if (k1==2) cout<<"fa "<<now<<" "<<w<<" "<<a<<" "<<b<<endl;
		if (Q.size()<K) Q.push(w),tot+=w;
		else if (Q.top()>w){
			tot-=Q.top(); tot+=w; Q.pop(); Q.push(w);
		}
		if (Q.size()==K){
			if (a>k1) b++;
			long long kk=1ll*b*K*w5+tot;
		//	if (k1==2) cout<<"now "<<kk<<" "<<tot<<endl;
			ans=min(ans,kk);
		}
	}
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&K,&w5,&w1);
	for (int i=1;i<=n;i++){
		scanf("%d",&t[i]); t[i]+=1e9;
	}
	sort(t+1,t+n+1);
	if (w5>=w1*5){
		for (int i=1;i<=n;i++) A[i]=A[i-1]+t[i];
		long long ans=1e18;
		for (int i=K;i<=n;i++) ans=min(ans,(1ll*K*t[i]-(A[i]-A[i-K]))*w1);
		cout<<ans<<endl; return 0;
	}
	long long ans=1e18;
	for (int i=0;i<5;i++) ans=min(ans,solve(i));
	cout<<ans<<endl; return 0;
}