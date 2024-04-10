#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,l,r,cur;
ll f[1000500],lst,s[1000500],t2;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		l=1e6;res=0;
		for(i=1;i<=n;i++){
			cin>>s[i];f[i-1]=llabs(s[i]-s[i-1]);
		}
		t2=0;
		for(i=1;i<n;i++){
			t2=__gcd(t2,f[i]);
			while(l<=cur){
				if(__gcd(s[l],t2)==1)l++;
				else break;
			}
			if(l>cur){
				cur=l=i;t2=0;
				s[l+1]=0;
				while(1){
					s[l]=__gcd(s[l+1],f[l]);
					if(l<1||s[l]==1){l++;break;}
					l--;
				}
			}
			res=max(res,i-l+1);
		}
		cout<<res+1<<'\n';
	}
}