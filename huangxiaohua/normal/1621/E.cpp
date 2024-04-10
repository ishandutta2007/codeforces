#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,res[1000500],it,p1[1000500],p2[1000500],p3[1000500];
ll a[1000500],pre[1000500];
vector<pair<int,int> >v[1000500];

struct sb{
	ll su,siz,id;
	bool operator< (const sb x)const{
		return su*x.siz<siz*x.su;
	}
}s[100500],tmp;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		it=0;
		for(i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(i=1;i<=m;i++){
			a[i]=a[i-m+n];
		}
		
		for(i=1;i<=m;i++){
			s[i].su=0;
			s[i].id=i;
			v[i].clear();
			cin>>s[i].siz;
			for(j=1;j<=s[i].siz;j++){
				cin>>k;
				v[i].push_back({++it,k});
				s[i].su+=k;
			}
		}
		sort(s+1,s+m+1);
		
		for(i=1;i<=m;i++){
			p1[i]=p1[i-1]; if(s[i].su>a[i-1]*s[i].siz)p1[i]++;
			p2[i]=p2[i-1]; if(s[i].su>a[i]*s[i].siz)p2[i]++;
			p3[i]=p3[i-1]; if(s[i].su>a[i+1]*s[i].siz)p3[i]++;
		}
		memset(res,0,it*4+50);
		//cout<<p2[1]<<' '<<p2[2]<<endl;
		for(i=1;i<=m;i++){
			tmp=s[i];
			for(auto [id,w]:v[tmp.id]){
				tmp.siz--;
				tmp.su-=w;
				
				int rnk=upper_bound(s+1,s+m+1,tmp)-s-1;
				if(tmp<s[i]){
					//printf("nmsl%d\n",id);
					rnk++;
					if(tmp.su<=tmp.siz*a[rnk]&&!(p2[rnk-1])&&!(p2[m]-p2[i])&&!(p3[i-1]-p3[rnk-1])){
						res[id]=1;
					}
				}
				else{
					//printf("nmsl%d %d\n",id,rnk);
					if(tmp.su<=tmp.siz*a[rnk]&&!(p2[i-1])&&!(p2[m]-p2[rnk])&&!(p1[rnk]-p1[i])){
						res[id]=1;
					}
				}
				tmp.siz++;
				tmp.su+=w;
			}
		}
		
		for(i=1;i<=it;i++){
			cout<<res[i];
		}cout<<'\n';
	}
}