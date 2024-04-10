#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[300500],b[300500],mex[300500],it,cur;
vector<int> res;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(b,0,n*4+50);
		it=0;
		res.clear();
		for(i=n;i>=1;i--){
			b[a[i]]++;
			while(b[it])it++;
			mex[i]=it;
		}
		cur=0;
		for(i=1;i<=n;i++){
			cur=mex[i];
			res.push_back(cur);
			memset(b,0,cur*4+50);
			it=0;
			for(j=i;;j++){
				b[a[j]]++;
				while(b[it])it++;
				if(it==cur){
					i=j;break;
				}
			}
			//printf("NMSL%d %d\n",i,j);
		}
		
		cout<<res.size()<<'\n';
		for(auto i:res){
			cout<<i<<' ';
		}cout<<'\n';
	}
}