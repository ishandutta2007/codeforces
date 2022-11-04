#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s;
const int N=200100;
int sl[N],sr[N],cursm[N];

main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,m;cin>>n>>m;cin>>s;
		int sm=0;
		sl[n]=sr[n]=cursm[n]=0;
		for(int i=n-1;i>=0;--i){
			if(s[i]=='+')++sm;
			if(s[i]=='-')--sm;
			sl[i]=min(sm,sl[i+1]);
			sr[i]=max(sm,sr[i+1]);
			cursm[i]=sm;
		}
		int curl=0,curr=0;sm=0;
		vector<tuple<int,int,int>>qs(m);
		for(int i=0;i<m;++i){
			int a,b;cin>>a>>b;
			qs[i]={a,b,i};
		}
		sort(qs.begin(),qs.end());
		vector<int>res(m);
		int cp=0;
		for(int i=0;i<n;++i){
			while(cp<m&&get<0>(qs[cp])==i+1){
				int r=get<1>(qs[cp]);
				int d1=(cursm[r]-sl[r]),d2=(sr[r]-cursm[r]);
				int mn=min(curl,sm-d2);
				int mx=max(curr,sm+d1);
				res[get<2>(qs[cp])]=mx-mn+1;
				++cp;
			}
			if(s[i]=='+')++sm;
			if(s[i]=='-')--sm;
			curl=min(sm,curl);
			curr=max(sm,curr);
		}
		for(auto r:res)cout<<r<<endl;
	}
}