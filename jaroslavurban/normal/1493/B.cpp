#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int rf[10]={0,1,5,-1,-1,2,-1,-1,8,-1};

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int h,m;cin>>h>>m;
		vector<int>isrf(h*m+m,-1);
		for(int i=0;i<h;++i)
			for(int j=0;j<m;++j)
				if(~rf[i%10]&&~rf[i/10]&&~rf[j%10]&&~rf[j/10])
					if((rf[j%10]*10+rf[j/10])<h&&10*rf[i%10]+rf[i/10]<m){
						isrf[i*m+j]=i*m+j;
					}
		for(int i=3*isrf.size();i>=0;--i)if(isrf[i%isrf.size()]==-1)isrf[i%isrf.size()]=isrf[(i+1)%isrf.size()];
		char c;
		int ch,cm;cin>>ch>>c>>cm;
		cout<<setw(2)<<setfill('0')<<isrf[ch*m+cm]/m<<":"<<setw(2)<<isrf[ch*m+cm]%m<<endl;
	}
}