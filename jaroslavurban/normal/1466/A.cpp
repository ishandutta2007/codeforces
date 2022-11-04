#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS=1e-5;

ld area(ld a, ld b, ld c){
	ld p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

bool eq(ld a, ld b) { return abs(a-b) <= abs(a+b) * EPS || abs(a-b) < EPS; }


main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		vector<int>a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		vector<ld>res;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j){
				bool in=false;
				ld ar=area(sqrt(a[i]*a[i]+1),sqrt(a[j]*a[j]+1),a[j]-a[i]);
				for(auto r:res)if(eq(r,ar))in=true;
				if(!in)res.push_back(ar);
			}
		cout<<res.size()<<endl;
	}
}