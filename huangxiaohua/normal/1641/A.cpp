#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=0;
		multiset<int> s;
		for(i=1;i<=n;i++){
			cin>>k;s.insert(k);
		}
		while(!s.empty()){
			auto k=*s.begin();
			//cout<<k<<endl;
			s.erase(s.find(k));
			if(s.empty()||(1ll*k*m)>1000000000){
				res++;break;
			}
			if(s.find(k*m)==s.end()){
				//puts("NMSL");
				res++;
			}
			else{
				s.erase(s.find(k*m));
			}
		}
		cout<<s.size()+res<<'\n';
	}
}