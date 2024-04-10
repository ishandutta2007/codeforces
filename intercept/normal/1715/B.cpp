#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
ll a[M];
void work(){
	ll n,k,s,b;
	cin>>n>>k>>b>>s;
	if(k*b<=s&&s<=k*b+(k-1)*n){
		s-=k*b;
		for(int i=1;i<=n;++i){
			a[i]=min(s,k-1);
			s-=min(s,k-1);
		}
		a[1]+=k*b;
		for(int i=1;i<=n;++i)cout<<a[i]<<" ";
		puts("");
	}
	else puts("-1");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 6 3 19
*/