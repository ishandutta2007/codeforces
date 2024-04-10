#include<iostream>
#include<set>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
typedef long long ll;
const int m=3e6;
int n;
bool s[m+1];
int bit[m+1];
vector<int>pf[m+1];
void update(int id,int v){
	for(int i=id; i<=m ;i+=i&-i){
		bit[i]+=v;
	}
}
int query(int id){
	int ans=0;
	for(int i=id; i>=1 ;i-=i&-i){
		ans+=bit[i];
	}
	return ans;
}
inline void remove(int tmp){
	for(int i=tmp; i<=m ;i+=tmp){
		if(s[i]) update(i,-1);
		s[i]=false;
	}
}
int nxt(int x){
	int cur=0;
	for(int i=21; i>=0 ;i--){
		if(cur+(1<<i)<=m && bit[cur+(1<<i)]<=x){
			x-=bit[cur+(1<<i)];
			cur+=(1<<i);
		}
	}
	return cur+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=2; i<=m ;i++){
		update(i,1);
		s[i]=true;
		if(!pf[i].empty()) continue;
		for(int j=i; j<=m ;j+=i){
			pf[j].emplace_back(i);
		}
	}
	int a;
	bool need=true;
	for(int i=1; i<=n ;i++){
		cin >> a;
		int tmp;
		if(!need) tmp=nxt(0);
		else tmp=nxt(query(a-1));
		cout << tmp << ' ';
		if(tmp!=a) need=false;
		for(int j=0; j<pf[tmp].size() ;j++) remove(pf[tmp][j]);
	}
}