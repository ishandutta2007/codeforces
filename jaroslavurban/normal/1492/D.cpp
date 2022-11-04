#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

int a,b,k,n;

string add(string a,string b){
	string res=string(n,'0');
	int over=0;
	for(int i=n-1;i>=0;--i){
		int total=over+(a[i]=='1')+(b[i]=='1');
		res[i]=(total&1)+'0';
		over=total>1;
	}
	return res;
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>a>>b>>k;
//	while(cin>>a>>b>>k){
//	cout<<a<<" "<<b<<" "<<k<<endl;
	if(a==0||b==1){
		if(k==0){
			cout<<"YES\n";
			cout<<string(b,'1')<<string(a,'0')<<endl;
			cout<<string(b,'1')<<string(a,'0')<<endl;
		}
		else cout<<"NO\n";
//		continue;
		return 0;
	}
	n=a+b;
	if(k+2<=n){
		cout<<"YES\n";
		string y=string(n,'0');;
		for(int i=0;i<min(b-1,k);++i)y[n-i-1]='1';
		for(int i=0;i<max(b-k,1);++i)y[i]='1';
		string ks=string(n,'0');
		for(int i=0;i<k;++i)ks[n-i-1]='1';
		string x=add(y,ks);
		x[0]='1';
		assert(count(x.begin(),x.end(),'1')==b);
		cout<<x<<endl;
		cout<<y<<endl;
	}
	else cout<<"NO\n";
//	}
}