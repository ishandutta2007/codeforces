#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--) {
		int a,b,c;
		cin>>a>>b>>c;
		vector<int> x={a,b,c};
		sort(x.begin(),x.end());
		bool ans=(x[2]-x[1]-x[0])<=1;
		cout<<(ans?"Yes":"No")<<"\n";
	}
	return 0;
}