#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int a[N],curt,cury;
bool used[N];
int x[3*N],y[3*N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	vector<int>onex,twox,trex;
	bool pos=true;
	for(int i=n-1;i>=0;--i){
		if(a[i]==1)onex.push_back(i);
		if(a[i]==2&&onex.empty())pos=false;
		if(a[i]==2&&onex.size()){
			x[curt]=i;y[curt]=cury;++curt;
			x[curt]=onex.back();y[curt]=cury;++cury;++curt;
			twox.push_back(i);
			onex.pop_back();
		}
	}
	sort(onex.begin(),onex.end());
	sort(twox.begin(),twox.end());
	for(int i=n-1;i>=0;--i)
		if(a[i]==3){
			if(onex.size()&&onex.back()>i){
				x[curt]=i;y[curt]=cury+1;++curt;
				x[curt]=onex.back();y[curt]=cury+1;++curt;
				x[curt]=onex.back();y[curt]=cury;cury+=2;++curt;
				onex.pop_back();
				trex.push_back(i);
			}else if(twox.size()&&twox.back()>i){
				x[curt]=i;y[curt]=cury;++curt;
				x[curt]=twox.back();y[curt]=cury;++curt;++cury;
				twox.pop_back();
				trex.push_back(i);
			}else if(trex.size()&&trex.back()>i){
				x[curt]=i;y[curt]=cury;++curt;
				x[curt]=trex.back();y[curt]=cury;++curt;++cury;
				trex.pop_back();
				trex.push_back(i);
			}else pos=false;
		}
	for(auto xx:onex){
		x[curt]=xx;y[curt]=cury;++curt;++cury;
	}
	if(!pos){cout<<-1<<endl;return 0;}
	cout<<curt<<endl;
	for(int i=0;i<curt;++i)cout<<n-y[i]<<" "<<x[i]+1<<endl;
}