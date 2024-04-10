#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,p[105],l,r;

int main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	memset(p,0,sizeof(p));
    	for(i=1;i<=n;i++){
    		cin>>p[i];
		}
		sort(p+1,p+n+1);
		for(i=100;i>=0;i--){
			l=1;r=n;
			for(j=i;j>=1;j--){
				while(r>=l&&p[r]>j)r--;
				if(r<l){
					goto aaa;
				}
				r--;l++;
			}
			cout<<i<<'\n';break;
			aaa:;
		}
	}
}