#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,a[66],b[66];
string s;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		map<int,int> mp;
		res=0;
		
		for(i=1;i<=n;i++){
			cin>>k;
			mp[k]++;
		}
		for(i=1;i<=n;i++){
			cin>>k;
			if(mp[k])mp[k]--;
			else{
				if(k<10){
					b[k]++;
				}
				else{
					res++;
					s=to_string(k);
					b[s.size()]++;
				}
			}
		}
		for(auto [k,y]:mp){
			if(k<10){
				a[k]+=y;
			}
			else{
				res+=y;
				s=to_string(k);
				a[s.size()]+=y;
			}
		}
		for(i=2;i<=9;i++){
			//printf("NMSL%d %d %d\n",i,a[i],b[i]);
			res+=abs(a[i]-b[i]);
		}
		cout<<res<<'\n';
	}
}