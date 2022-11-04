#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>a(n);
	int sm=0;
	for(int&v:a)cin>>v,sm+=(v=v&1);
	if(sm!=n/2&&sm!=(n+1)/2){cout<<"-1\n";return;}
	if(n&1){
		int more=sm==(n+1)/2;
		int last=0,res=0;
		auto good=[&](int i){
			return ((i&1)&&a[i]!=more)||(!(i&1)&&a[i]==more);
		};
		for(int i=0;i<n;++i){
			while(last<i&&good(last))++last;
			if(((last&1)&&a[i]!=more)||(!(last&1)&&a[i]==more)){
				res+=i-last;
				swap(a[i],a[last]);
			}
		}
		cout<<res<<"\n";
	}else{
		int rres=INT_MAX;
		auto ta=a;
		for(int it=0;it<2;++it){
			a=ta;
			int res=0;
			int more=it;
			int last=0;
			auto good=[&](int i){
				return ((i&1)&&a[i]!=more)||(!(i&1)&&a[i]==more);
			};
			for(int i=0;i<n;++i){
				while(last<i&&good(last))++last;
				if(((last&1)&&a[i]!=more)||(!(last&1)&&a[i]==more)){
					res+=i-last;
					swap(a[i],a[last]);
				}
			}
			rres=min(rres,res);
		}
		cout<<rres<<"\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}