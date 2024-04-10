#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,l,r;
ll jc[1005000],inv[1005000],res,len,sb1,sb2,sb[200500],pre,tmp;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}



int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&l,&r);
		
		map<int,vector<pair<int,int> >>mp;
		set<int> s;
		res=0;
		len=n;sb1=sb2=0;
		
		for(i=1;i<=n;i++){
			s.insert(r-i+1);
			s.insert(i-l+1);
			mp[r-i+1].push_back({i,1});
			mp[i-l+1].push_back({i,-1});
			sb[i]=0;
		}
		
		pre=1;
		for(auto i:s){
			if(i>=1){
				tmp=i-pre;
				//printf("a%d %d %d\n",i,len,sb1);
				if(n&1){
					res+=c(len,n/2-sb1)*tmp%M;
					res+=c(len,n/2+1-sb1)*tmp%M;
					res%=M;
				}
				else{
					//printf("c%d %d %d\n",i,len,n/2-sb1);
					res+=c(len,n/2-sb1)*tmp%M;
					res%=M;
				}
				pre=i;
			}
			for(auto [x,y]:mp[i]){
				if(sb[x]){goto aaa;}
				sb[x]=1;len--;
				if(y==1){sb1++;}
				else{sb2++;}
			}
		}
		aaa:;
		printf("%lld\n",res);
	}
	
}