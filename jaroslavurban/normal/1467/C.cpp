#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=300100;
int n;
vector<int>a[3];

main(){
	int n[3];
	for(int i=0;i<3;++i)cin>>n[i];
	for(int i=0;i<3;++i){
		a[i].resize(n[i]);
		for(int j=0;j<n[i];++j)
			cin>>a[i][j];
	}
	for(int i=0;i<3;++i)sort(a[i].begin(),a[i].end());
	ll sm[3]={};
	for(int i=0;i<3;++i)sm[i]=accumulate(a[i].begin(),a[i].end(),0ll);
	ll res=-1e18;
	for(int j=0;j<1;++j){
		for(int i=0;i<3;++i){
			if(j)sort(a[i].rbegin(),a[i].rend());
			for(int k=0;k<3;++k)
				if(k!=i)
					for(int t=0;t<3;++t)
						if(t!=k&&t!=i){
							ll sm1=a[k][0]-(sm[i]-a[i][0])-(sm[t]-a[t][0]);
							ll sm2=a[t][0]-(sm[k]-a[k][0]);
							if(sm1<=0||sm2<=0)res=max(res,a[i][0]+abs(sm1)+abs(sm2));
							else res=max({res,a[i][0]+abs(sm1-sm2),sm1+abs(a[i][0]-sm2),sm2+abs(a[i][0]-sm1)});
						}
			if(j)sort(a[i].begin(),a[i].end());
		}
	}
	cout<<res<<endl;
}