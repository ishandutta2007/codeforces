#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;;
int n;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	int rev=n%2,ssplit=0;
	vector<vector<int>>qq(n);
	int qs=0;
	while(ssplit<n){
		vector<int>tmpa(n);
		int idx=0;
		for(int i=0;i<n;++i)if(a[i]==ssplit+1)idx=i;
//		for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
		if(!rev){
			for(int i=0;i<ssplit;++i)qq[qs].push_back(1);
			qq[qs].push_back((idx+1)-ssplit);
			if(n-(idx+1))qq[qs].push_back(n-(idx+1));
			for(int i=0;i<ssplit;++i)tmpa[n-i-1]=a[i];
			for(int i=0;i<idx-ssplit+1;++i)tmpa[n-(idx+1)+i]=a[i+ssplit];
			for(int i=idx+1;i<n;++i)tmpa[i-(idx+1)]=a[i];
		}else{
			if(idx)qq[qs].push_back(idx);
			qq[qs].push_back(n-ssplit-idx); // size with idx
			for(int i=0;i<ssplit;++i)qq[qs].push_back(1);
			for(int i=0;i<ssplit;++i)tmpa[i]=a[n-i-1];
			for(int i=0;i<n-ssplit-idx;++i)tmpa[ssplit+i]=a[i+idx];
			for(int i=0;i<idx;++i)tmpa[n-idx+i]=a[i];
		}
		swap(tmpa,a);
		++ssplit;
		++qs;
		rev=!rev;
	}
	int cntop=0;
	for(int i=0;i<qs;++i)if(qq[i].size()!=1)++cntop;
	cout<<cntop<<endl;
	for(int i=0;i<qq.size();++i)
		if(qq[i].size()>1){
			cout<<qq[i].size();
			for(int j=0;j<qq[i].size();++j)cout<<" "<<qq[i][j];cout<<endl;
		}
}