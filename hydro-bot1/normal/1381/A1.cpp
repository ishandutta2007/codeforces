// Hydro submission #630b525e94a82b94c13b20b0@1661686366648
#include<bits/stdc++.h>
using namespace std;
int t,n;
string a,b;
int main(){//
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		int f=0,x=0;
		vector<int> vec;
		for(int i=n-1;i>=0;i--){
			if(f^(a[x]==b[i]))
				vec.push_back(1);
			vec.push_back(i+1);
			if(f) x-=i;
			else x+=i;
			f^=1;
		}
		cout<<vec.size()<<" ";
		for(int i=0;i<vec.size();i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
	return 0;
}//