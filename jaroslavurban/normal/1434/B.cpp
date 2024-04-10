#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int ord[2*N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<2*n;++i){
		int num;
		char c;cin>>c;
		if(c=='+')continue;
		cin>>num;
		ord[i]=num;
	}
	vector<int>sold,res;
	bool pos=true;
	for(int i=2*n-1;i>=0;--i){
		if(!ord[i]&&sold.empty()){pos=false;break;}
		if(!ord[i]){res.push_back(sold.back());sold.pop_back();}
		if(ord[i]&&sold.size()&&ord[i]>sold.back()){pos=false;break;}
		if(ord[i])sold.push_back(ord[i]);
	}
	if(!pos){cout<<"NO\n";return 0;}
	reverse(res.begin(),res.end());
	if(pos)cout<<"YES\n";
	for(auto r:res)cout<<r<<" ";cout<<endl;
}