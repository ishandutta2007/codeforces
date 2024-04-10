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

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m>>k;
	if(k>4*(n-1)*(m-1)+2*(n+m-2)){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	vector<pair<int,string>>moves;
	for(int i=0;i<n-1;++i){
		if(m-1){
			moves.push_back({m-1,"R"});
			moves.push_back({m-1,"DUL"});
		}
		moves.push_back({1,"D"});
	}
	if(m-1){
		moves.push_back({m-1,"R"});
		moves.push_back({m-1,"L"});
	}
	if(n-1)moves.push_back({n-1,"U"});
	vector<pair<int,string>>res;
	for(int i=0,cnt=0;i<moves.size();++i)
		if(cnt+moves[i].first*moves[i].second.size()<=k){
			res.push_back(moves[i]);
			cnt+=moves[i].first*moves[i].second.size();
		}
		else{
			if((k-cnt)/moves[i].second.size()){
				res.push_back({(k-cnt)/moves[i].second.size(),moves[i].second});
				cnt+=(k-cnt)/moves[i].second.size()*moves[i].second.size();
			}
			if(k-cnt){
				res.push_back({1,string(1,moves[i].second[0])});
				++cnt;
			}
			if(k-cnt){
				res.push_back({1,string(1,moves[i].second[1])});
				++cnt;
			}
			if(k-cnt){
				res.push_back({1,string(1,moves[i].second[2])});
				++cnt;
			}
			break;
		}
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();++i)cout<<res[i].first<<" "<<res[i].second<<endl;
}