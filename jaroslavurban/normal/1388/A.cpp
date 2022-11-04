#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		set<int>pos={6,10,14,15,21,22,33,35};
		int m=pos.size();
		bool w=true;;
		for(int i=0;i<m&&w;++i)
			for(int j=i+1;j<m&&w;++j)
				for(int k=j+1;k<m&&w;++k){
					int a,b,c,d;
					a=*next(pos.begin(),i);
					b=*next(pos.begin(),j);
					c=*next(pos.begin(),k);
					d=n-a-b-c;
					if(!pos.count(d)&&d>0){
						cerr<<n<<endl;
						cout<<"YES\n"<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
						w=false;
					}
				}
		if(w)cout<<"NO\n";
	}
}