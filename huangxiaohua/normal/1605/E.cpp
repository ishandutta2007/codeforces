#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m;
ll a[1000500],b[1000500],c[1000500],op[3][1005000],cur;
ll res[1005000],ans;
priority_queue<ll> q_jian,q_jia;

int main(){
	cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)cin>>b[i];
	for(t=1;t<=2;t++){
		memcpy(c,a,sizeof(a));
		b[1]=t;
		for(i=1;i<=n;i++){
			k=b[i]-c[i];
			op[t][i]=k;
			for(j=i;j<=n;j+=i){
				c[j]+=k;
			}
		}
	}
	for(i=1;i<=n;i++){
		ans+=abs(op[1][i]);
		if(op[1][i]==op[2][i]){
			continue;
		}
		if((op[1][i]+1)==op[2][i]){
			if(op[1][i]>=0){cur++;}
			else{q_jia.push(op[1][i]);}
			continue;
		}
		if((op[1][i]-1)==op[2][i]){
			if(op[1][i]<=0){cur++;}
			else{q_jian.push(-op[1][i]);}
			continue;
		}
		return 1;
	}
	res[1]=ans;
	for(i=2;i<=1000000;i++){
		ans+=cur;
		ans-=q_jia.size();
		ans-=q_jian.size();
		res[i]=ans;
		while(!q_jia.empty() && (q_jia.top()+i-1)==0){cur++;q_jia.pop();}
		while(!q_jian.empty() && (q_jian.top()+i-1)==0){cur++;q_jian.pop();}
	}
	cin>>t;
	while(t--){
		cin>>k;
		cout<<res[k]<<'\n';
	}
}