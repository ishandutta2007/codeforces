#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
int T,n,c,q,i,qwq,a[N];
ll l1[N],l2[N],r1[N],r2[N],ans;
string s,t;
int cal(int l,int r,int L,int R){
//	cout<<l<<" "<<r<<" "<<L<<" "<<R<<"\n";
	return abs(l-L)+abs(r-R);
}
int main(){
	ios::sync_with_stdio(0); 
	cin>>T;
	while(T--){
		cin>>n>>s>>t;ans=0;
		for(i=0;i<n;++i)s[i]-='0',t[i]-='0';
		if(s[0]!=t[0]||s[n-1]!=t[n-1])cout<<"-1\n";
		else {
			int c1=0,c2=0;
			for(i=0;i<n-1;++i)if(s[i]!=s[i+1])++c1;
			for(i=0;i<n-1;++i)if(t[i]!=t[i+1])++c2;
			if(c1!=c2)cout<<"-1\n";
			else{
				c1=c2=0;
				if(s[0]==1)l1[++c1]=l2[++c2]=0;
				for(i=0;i<n-1;++i){
					if(s[i]==0&&s[i+1]==1){
						l1[++c1]=i;
					}
					if(t[i]==0&&t[i+1]==1){
						l2[++c2]=i;
					}
					if(s[i]==1&&s[i+1]==0)
						r1[c1]=i;
					if(t[i]==1&&t[i+1]==0){
						r2[c2]=i;
					}
				}
				if(s[n-1]==1)r1[c1]=n-1;
				if(t[n-1]==1)r2[c2]=n-1;
				for(i=1;i<=c1;++i)ans+=cal(l1[i],r1[i],l2[i],r2[i]);
				cout<<ans<<"\n";
			}
		}
	}
}