#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m,t,num[105000],a[66],cl[100500][11],cr[100500][11];
bool vis[1005000];
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
int main() {
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		num[i]=1;
		s1.id=i;
		for(j=1;j<=m;j++){
			cin>>a[j];
			s1.l[j]=s1.r[j]=a[j];
		}
		while(1){
			auto it=s.upper_bound(s1);
			if(it==s.end()){
				break;
			}
			s2=(*it);
			for(j=1;j<=m;j++){
				if(s1.r[j]>=s2.l[j]){
					num[i]+=num[s2.id];
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
		auto it=s.end();
		it--;
		cout<<num[(*it).id]<<'\n';
	}
}