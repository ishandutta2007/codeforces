#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
		if(x1==x2){
			cout<<abs(y1-y2)<<endl;
			continue;
		}
		if(y1==y2){
			cout<<abs(x1-x2)<<endl;
			continue;
		}
		cout<<abs(x1-x2)+abs(y1-y2)+2<<endl;
	}
}