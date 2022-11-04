#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

vector<int>tobase(int val,int mod,int width){
	vector<int>res(width);
	for(int i=0;i<width;++i){
		res[i]=val%mod;
		val/=mod;
	}
	return res;
}

int frombase(vector<int>myq,int mod,int width){
	int res=0;
	for(int mul=1,i=0;i<width;++i,mul*=mod){
		res+=myq[i]*mul;
	}
	return res;
}

void ProGamerMove(){
	int n,k;cin>>n>>k;
	int width=log2(n)+2;
	vector<vector<int>>sm(width,vector<int>(2));
	for(int i=0;i<n;++i){
		auto ok=tobase(i,k,width);
//		for(auto v:ok)cerr<<v<<endl;
		vector<int>myq(width);
		for(int j=0;j<width;++j){
			// i is odd => even myqs are positive, ok negative
			if(i&1){
				myq[j]=-sm[j][1]+sm[j][0]-ok[j];
			}
			else{
				myq[j]=+sm[j][1]-sm[j][0]+ok[j];
			}
			myq[j]%=k;
			myq[j]+=k;
			myq[j]%=k;
			sm[j][i&1]=(sm[j][i&1]+myq[j])%k;
//			cerr<<"sm "<<myq[j]<<" "<<sm[j][i&1]<<endl;
		}
		int qval=frombase(myq,k,width);
		cout<<qval<<endl;
		int r;cin>>r;if(r)return;
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}