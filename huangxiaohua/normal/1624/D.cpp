#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,a[666],l,r,md,res,xx,yy;
string s;
int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>s;
		memset(a,0,sizeof(a));
		for(auto i:s){
			a[i]++;
		}
		int x=0,y=0;
		for(i='a';i<='z';i++){
			if(a[i]&1){
				x++;
			}
			y+=a[i]/2;
		}
		
		l=1,r=n;res=0;
		while(l<=r){
			md=(l+r)/2;
			xx=x;yy=y;
			
			if(md&1){
				while(xx<m&&yy){
					xx+=2;yy--;
				}
				sb=(xx>=m)+yy/m*2;
			}
			else{
				sb=yy/m*2;
			}
			if(sb>=md){
				res=max(res,md);
				l=md+1;
			}
			else r=md-1;
		}
		cout<<res<<'\n';
	}
}