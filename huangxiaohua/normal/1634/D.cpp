#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,mx,sb2,mn,a[100500],mx2,mn2,f[1050];
vector<tuple<int,int,int> >v;

int main() {
	//ios::sync_with_stdio(0);
	cin>>t;
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	
	while(t--){
		cin>>n;
		//n=5;	uniform_int_distribution<int>lim(1,n);m=lim(rng);for(i=1;i<=n;i++){a[i]=rng()%10+1;}a[m]=0;
		v.clear();
		sb=-1;mx=-1;
		for(i=3;i<=n;i++){
			cout<<"? "<<1<<' '<<2<<' '<<i<<endl;
			cin>>k;
			//k=max({a[1],a[2],a[i]})-min({a[1],a[2],a[i]});
			if(k>mx){
				mx=k;sb=i;
				v.clear();
				v.push_back({1,2,i});
			}
			else if(k==mx){
				v.push_back({1,2,i});
			}
		}
		
		for(i=2;i<=n;i++){
			if(i==sb)continue;
			cout<<"? "<<1<<' '<<sb<<' '<<i<<endl;
			//k=max({a[1],a[sb],a[i]})-min({a[1],a[sb],a[i]});
			cin>>k;
			if(k>mx){
				mx=k;
				v.clear();
				v.push_back({1,sb,i});
			}
			else if(k==mx){
				v.push_back({1,sb,i});
			}
		}
		//cout<<"!! "<<m<<endl;for(i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
		if(v.size()==1){
			auto [x,y,z]=v[0];
			//printf("nmsl%d %d %d\n",x,y,z);
			cout<<"! "<<y<<' '<<z<<endl;
			//if(z!=m&&y!=m)return 1;
		}
		else{
			memset(f,0,sizeof(f));
			for(auto [x,y,z]:v){
				//printf("NMSL%d %d %d\n",x,y,z);
				f[x]++;f[y]++;f[z]++;
			}
			priority_queue<pair<int,int> >q;
			for(i=1;i<=n;i++)q.push({f[i],i});
			auto [x,y]=q.top();q.pop();i=y;
			auto [xx,yy]=q.top();q.pop();j=yy;
			cout<<"! "<<i<<' '<<j<<endl;
			//if(i!=m&&j!=m)return 1;
		}
	}
}