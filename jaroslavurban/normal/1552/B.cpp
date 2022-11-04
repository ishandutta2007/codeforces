#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

struct A{
	array<int,5>ranks;
	int id;
	bool issup(A&a){
		int btr=0;
		for(int i=0;i<5;++i)btr+=ranks[i]<a.ranks[i];
		return btr>=3;
	}
};

void ProGamerMove(){
	int n;cin>>n;
	vector<A>a(n);
	for(int i=0;i<n;++i){
		a[i].id=i;
		for(int j=0;j<5;++j)
			cin>>a[i].ranks[j];
	}
  shuffle(a.begin(),a.end(),gen);
	vector<A>dones;
	while(a.size()){
		vector<A>na;
		auto ma=a.back();a.pop_back();
		bool good=true;
		for(auto&at:a)if(ma.issup(at))dones.push_back(at);
		else{
			good=false;
			na.push_back(at);
		}
		for(auto&at:dones){
			if(!good)break;
			if(at.issup(ma))good=false;
		}
		if(good){
			cout<<ma.id+1<<"\n";
			return;
		}
		swap(a,na);
	}
	cout<<-1<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}