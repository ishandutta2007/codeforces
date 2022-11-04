#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n,k;cin>>n>>k;
	vector<int>frpos(2*n,-1),freei(2*n);
	for(int i=0;i<k;++i){
		int x,y;cin>>x>>y;--x;--y;
		if(x>y)swap(x,y);
		frpos[x]=y;
		frpos[y]=x;
//		cerr<<x+1<<" "<<y+1<<endl;
	}
	int found=0;
	for(int i=0;i<2*n;++i)if(frpos[i]==-1){
//		cerr<<"solving "<<i+1<<endl;
		freei[found++]=i;
		if(found>=1+n-k){
//			cerr<<found-(n-k)<<endl;
			int j=freei[found-(n-k)-1];
//			cerr<<i+1<<" "<<j+1<<endl;
			frpos[i]=j;
			frpos[j]=i;
		}
	}
	int res=0;
	for(int i=0;i<2*n;++i)
		for(int j=i+1;j<frpos[i];++j){
//			cerr<<i+1<<" "<<j+1<<" "<<frpos[i]+1<<" "<<frpos[j]+1<<endl;
			res+=frpos[j]>frpos[i];
		}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}