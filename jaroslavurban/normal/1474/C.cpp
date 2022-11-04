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

const int N=1010;
int a[2*N];
map<int,int>s;
int n;

vector<pair<int,int>>ops;
int simulate(int sum){
	ops.clear();
	map<int,int>st=s;
	for(int i=0;i<n;++i){
		int a=prev(st.end())->first;
		if(st[a]>1)--st[a];
		else st.erase(a);
		int b=sum-a;
		if(st.count(b)){
			if(st[b]>1)--st[b];
			else st.erase(b);
			ops.push_back({a,b});
			sum=a;
		}else return false;
	}
	return true;
}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		s.clear();
		cin>>n;
		for(int i=0;i<2*n;++i)cin>>a[i];
		sort(a,a+2*n);
		reverse(a,a+2*n);
		for(int i=0;i<2*n;++i)++s[a[i]];
		bool pos=false;
		int sum=0;
		sum=21;
		for(int i=1;i<2*n;++i){
			sum=a[0]+a[i];
			if(simulate(sum)){pos=true;break;}
		}
		if(pos){
			cout<<"YES\n";
			cout<<sum<<endl;
			for(int i=0;i<ops.size();++i)cout<<ops[i].first<<" "<<ops[i].second<<endl;
		}
		else cout<<"NO\n";
	}
}