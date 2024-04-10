#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n,m,q;
char s[M];
ll l[M],r[M];
void work(){
	cin>>n>>m>>q>>s+1;
	for(int i=1;i<=m;++i){
		cin>>l[i]>>r[i];
	}
	for(int i=1;i<=q;++i){
		ll k;
		cin>>k;
		while(k>n){
			ll x=n;
			for(int j=1;j<=m;++j){
				ll y=x+r[j]-l[j]+1;
				if(k<=y&&k>x){
					k=k-x+l[j]-1;
					break;
				}
				x=y;
			}
		}
		putchar(s[k]);
		puts("");
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
4 3 2
mark
1 4
5 7
3 8
1
10
*/