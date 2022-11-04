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

int n,k;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>k;
	if(k%2==0){
		cout<<"YES\n";
		for(int j=0;j<4;++j,cout<<endl)
			for(int i=0;i<n;++i)
				if(i&&i<=k/2&&j&&j<3)cout<<'#';
				else cout<<'.';
	}
	else if(k>4){
		cout<<"YES\n";
		k-=4;
		for(int j=0;j<4;++j,cout<<endl)
			for(int i=0;i<n;++i)
				if(j&&j<3&&(i==1||i==2+(k+1)/2))cout<<'#';
				else if(i&&i<=1+k/2+(j==1)&&j&&j<3)cout<<'#';
				else cout<<'.';
	}	
	else if(k==n-2){
		cout<<"YES\n";
		for(int j=0;j<4;++j,cout<<endl)
			for(int i=0;i<n;++i)
				if(i&&j&&k){cout<<'#';--k;}
				else cout<<'.';
	}
	else if(k==3||k==1){
		cout<<"YES\n";
		int l=(n-k-k/2)/2;
		for(int j=0;j<4;++j,cout<<endl)
			for(int i=0;i<n;++i)
				if(i>=l&&(i%2)==(l%2)&&j&&k){cout<<'#';--k;}
				else cout<<'.';
	}
	else cout<<"NO\n";
}