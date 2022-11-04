#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>a(n),res;
	for(int&v:a)cin>>v;
	auto reverse=[&](int mid){
		if(mid==1)return;
		assert(mid<=(n+1)/2);
//		cerr<<mid<<" "<<n<<endl;
		res.push_back(mid);
		for(int i=0;i<mid;++i)swap(a[i],a[2*mid-i-2]);
	};
	for(int i=1;i<n;i+=2){
		int pos=find(a.begin(),a.end(),i)-a.begin()+1;
		if((pos&1)!=(i&1)){
			cout<<"-1\n";return;
		}
		int mid=(pos+1)/2;
		reverse(mid);
		int pos2=find(a.begin(),a.end(),i+1)-a.begin();
		if((pos2&1)!=(i&1)){
			cout<<"-1\n";return;
		}
		int mid2=(pos2+1)/2;
		int mid3=(n-i+2)/2;
		reverse(mid2);
		reverse(mid3);
		pos=find(a.begin(),a.end(),i)-a.begin()+1;
		mid=(pos+1)/2;
		reverse(mid);
		reverse(mid3);
	}
	cout<<res.size()+1<<"\n";
	for(int r:res)cout<<2*r-1<<" ";cout<<"\n";
	cout<<n<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}