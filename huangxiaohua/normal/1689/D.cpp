#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,mx1,mn1,mx2,mn2,rx,ry;
char s[1050][1050];

int dis(int i,int j){
	int x=i+j,y=i-j;
	return max({abs(x-mx1),abs(x-mn1),abs(y-mx2),abs(y-mn2)});
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	mx1=mx2=-1e9;
    	mn1=mn2=1e9;
    	rx=ry=-1e7;
    	for(i=1;i<=n;i++){
    		cin>>s[i]+1;
    		for(j=1;j<=m;j++){
    			if(s[i][j]=='B'){
    				mx1=max(mx1,i+j);mn1=min(mn1,i+j);
    				mx2=max(mx2,i-j);mn2=min(mn2,i-j);
				}
			}
		}
		for(i=1;i<=n;i++)for(j=1;j<=m;j++){
			if(dis(i,j)<=dis(rx,ry)){rx=i;ry=j;}
		}
		cout<<rx<<' '<<ry<<'\n';
	}
}