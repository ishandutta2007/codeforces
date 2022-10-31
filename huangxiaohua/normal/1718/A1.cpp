#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,sb;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
    	map<int,int> mp;
        cin>>n;
        res=sb=0;
        for(i=1;i<=n;i++){
        	cin>>k;
        	if(!k){
        		sb=0;
				mp.clear();
				continue;
			}
			res++;
			
			sb^=k;
			if(!sb||mp.count(sb)){
				mp.clear();
				res--;sb=0;continue;
			}
			mp[sb]=1;
		}
		cout<<res<<'\n';
    }
}