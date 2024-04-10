#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,a[66],cl[100500][3],cr[100500][3],fa[100500],A[100500],B[100500];

struct sb{
	int id,l[11],r[11];
	bool operator<(const sb x)const{
		for(int i=1;i<=m;i++){
			if(l[i]<=x.r[i]){
				return 1;
			}
		}
		return 0;
	}
}s1,s2;
set<struct sb>s;

int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		m=2;
		s.clear();
		
		for(i=1;i<=n;i++)cin>>A[i];
		for(i=1;i<=n;i++)cin>>B[i];
		
		for(i=1;i<=n;i++){
			
			s1.id=i;fa[i]=i;
			
			s1.l[1]=s1.r[1]=A[i];
			s1.l[2]=s1.r[2]=B[i];
			
			while(1){
				auto it=s.upper_bound(s1);
				if(it==s.end()){
					break;
				}
				s2=(*it);
				for(j=1;j<=m;j++){
					if(s1.r[j]>=s2.l[j]){
						fa[find(s2.id)]=find(s1.id);
						//num[i]+=num[s2.id];
						for(k=1;k<=m;k++){
							s1.l[k]=min(s1.l[k],s2.l[k]);
							s1.r[k]=max(s1.r[k],s2.r[k]);
						}
						s.erase(it);
						goto aaa;
					}
				}
				break;
				aaa:;
			}
			s.insert(s1);
		}
		
		auto it=s.end();
		it--;
		ll ans=(*it).id;
		for(i=1;i<=n;i++){
			if(find(i)==ans){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		cout<<'\n';
	}
	
}