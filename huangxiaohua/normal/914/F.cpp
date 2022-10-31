#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,w;
char s[100500],s2[100500];

bitset<100001> b[30],res;

int main(){
    cin.tie(0);
    cin>>s+1;
    n=strlen(s+1);
    for(i=1;i<=n;i++){
    	s[i]-='a'-1;
    	b[s[i]][i]=1;
	}
    cin>>t;
    int ty,l,r;
    while(t--){
    	cin>>ty;
    	if(ty==1){
    		cin>>l>>s2;
    		s2[0]-='a'-1;b[s[l]][l]=0;b[s2[0]][l]=1;s[l]=s2[0];
		}
		else{
			cin>>l>>r>>s2+1;n=strlen(s2+1);
			res.set();
			res>>=(100000+(n-1)-(r-l+1));res[0]=0;
			res<<=(l-1);
			for(i=1;i<=n;i++){
				res&=(b[s2[i]-'a'+1]>>(i-1));
			}
			cout<<res.count()<<'\n';
		}
	}
}