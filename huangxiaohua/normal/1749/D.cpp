#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

ll i,j,k,n,m,t,res,sb,t1,p[1005000];

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    sb=1;
    t1=1;
    for(i=1;i<=n;i++){
    	sb=sb*(m%M)%M;
    	res=(res+sb)%M;
	}
	for(i=2;i<=n;i++){
		if(!p[i]){
			for(j=i;j<=n;j+=i)p[j]=i;
		}
	}
	sb=1;
    for(i=1;i<=n;i++){
    	if(p[i]==i){
    		sb=sb*i;
		}
		if(sb>m)break;
    	t1=t1*((m/sb)%M)%M;
    	//printf("NMSL%d %d %d\n",i,sb,t1);
    	res+=M-t1;res%=M;
	}
	cout<<res;
}