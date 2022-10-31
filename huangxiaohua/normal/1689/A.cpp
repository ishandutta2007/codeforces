#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y;
char s1[1050],s2[1050];

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n>>m>>k>>s1+1>>s2+1;
    	sort(s1+1,s1+n+1);
    	sort(s2+1,s2+m+1);
    	string res;
    	i=j=1;
    	x=y=0;
    	while(i<=n&&j<=m){
    		if(x==k){
    			x=0;y=1;
    			res+=s2[j];j++;continue;
			}
			if(y==k){
    			y=0;x=1;
    			res+=s1[i];i++;continue;
			}
    		if(s1[i]<s2[j]){
    			x++;y=0;
    			res+=s1[i];i++;continue;
			}
			else{
				y++;x=0;
				res+=s2[j];j++;continue;
			}
		}
		cout<<res<<endl;
	}
}