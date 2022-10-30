#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,t,n,m,a[666],sb;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1;
		n=s1.size();
		memset(a,0,sizeof(a));
		for(auto i:s1)a[i]++;
		sb=0;
		for(auto i:s1){
			if(a[i]==1){
				sb=1;
			}
			a[i]--;
			if(sb)s2+=i;
		}
		cout<<s2<<'\n';
	}
}