#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		bool done=false;
		for(int i=0;!done&&i*3<=n;++i)
			for(int j=0;!done&&j*5+i*3<=n;++j)
				if((n-i*3-j*5)%7==0){
					cout<<i<<" "<<j<<" "<<(n-i*3-j*5)/7<<endl;
					done=true;
				}
		if(!done)cout<<-1<<endl;
	}
}