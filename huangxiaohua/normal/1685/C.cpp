#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//
int i,j,k,n,m,t,p[500500],p2[500500],pos,lst,st;
char s[500500];
vector<pair<int,int> >v;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		v.clear();
		cin>>n>>s+1;
		n*=2;
		lst=0;
		for(i=1;i<=n;i++){
			p[i]=p[i-1];
			if(s[i]=='(')p[i]++;
			else p[i]--;
			p2[i]=0;
			
			if(p[i]<0)lst=i;
		}
		if(!lst){
			cout<<"0\n";
			continue;
		}
		p2[n]=p[n];
		for(i=n-1;i>=1;i--){
			p2[i]=max(p2[i+1],p[i]);
		}
		st=0;
		for(i=1;i<=n;i++){
			if(p[i]>p[st])st=i;
			if(p[i]<0){
				for(j=n;;j--){
					if(p[j]==p2[st+1]){
						pos=j;break;
					}
				}
				
				int l,r,md,ans;
				l=pos,r=n;
				ans=0;
				while(l<=r){
					md=(l+r)/2;
					if(p[st]+p2[md]>=p2[pos]){
						ans=max(ans,md);l=md+1;
					}
					else r=md-1;
				}
				
				if(ans>=lst){
					v.push_back({st+1,ans});
				}
				else{
					v.push_back({st+1,pos});
					v.push_back({pos+1,n});
				}
				break;
			}
		}
		cout<<v.size()<<'\n';
		for(auto [x,y]:v){
			cout<<x<<' '<<y<<'\n';
		}
	}
}