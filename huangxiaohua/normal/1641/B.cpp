#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1050],b[1050],it,p[1050];
map<int,int> mp;
vector<pair<int,int> >r1;
vector<int> r2;

void swp(int l,int r){
	//printf("NMSL%d %d\n",l,r);
	r2.push_back((r-l+1)*2);
	int i,j;
	for(i=r;i>=l;i--){
		r1.push_back({(r-i)+l-1,a[i]});
	}
	while(l<r){
		swap(a[l],a[r]);l++;r--;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		int sb=0;
		mp.clear();
		for(i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i];
			mp[a[i]]++;
		}
		for(auto [i,j]:mp){
			if(j&1){
				cout<<"-1\n";goto aaa;
			}
		}
		it=0;
		sort(b+1,b+n+1);
		for(i=1;i<=n;i+=2){
			p[++it]=b[i];
		}
		for(i=2;i<=n;i+=2){
			p[++it]=b[i];
		}
		r1.clear();r2.clear();
		for(i=1;i<=n;i++){
			if(a[i]==p[i])continue;
			for(j=i+1;j<=n;j++){
				if(a[j]==p[i]){
					swp(j,n);
					swp(i,n);
					goto bbb;
				}
			}
			return 1;
			bbb:;
		}
		r2.push_back(n);
		
		cout<<r1.size()<<'\n';
		for(auto [x,y]:r1){
			cout<<x<<' '<<y<<'\n';
		}cout<<'\n';
		
		reverse(r2.begin(),r2.end());
		cout<<r2.size()<<'\n';
		for(auto i:r2){
			cout<<i<<' ';
		}cout<<'\n';
		aaa:;
	}
}