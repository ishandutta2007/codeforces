#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t;
ll res,cur;

int main() {
	ios_base::sync_with_stdio(0);
	cin>>n;
	cur=2;
	for(i=1;i<=n;i++){
		__int128 sb=i*(i+1);
		sb=sb*sb;
		sb=(sb-cur)/i;
		cout<<(ll(sb))<<'\n';
		cur=i*(i+1);
	}
}