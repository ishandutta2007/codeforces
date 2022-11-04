#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define int ll

const int N=200100;
int s[N];

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,m,a,b;cin>>n>>m>>a>>b;
		for(int i=0;i<m;++i)cin>>s[i];
		int cmax=abs(a-b)-1;
		int totaltime=cmax;
		if(a<b)totaltime+=a-1;
		else totaltime+=n-a;
		sort(s,s+m);
		int last=0;
		int biggest=0;
		int res=0;
		for(int i=0;i<min(m,cmax);++i){
			if(i&&s[i]==s[i-1]){++last;++biggest;}
			else{
				last=s[i];
				biggest=max(last,++biggest);
			}
			if(biggest>totaltime)break;
			else ++res;
		}
		cout<<res<<endl;
	}
}