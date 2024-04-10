#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s;
		k=0;
		map<char,int> mp;
		for(auto i:s){
			mp[i]=1;
			if(mp.size()==4){
				mp.clear();mp[i]=1;
				k++;
			}
		}
		cout<<k+1<<endl;
	}
}