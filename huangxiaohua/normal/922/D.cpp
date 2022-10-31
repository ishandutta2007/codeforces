#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t;
ll res,it;
struct sb{
	ll s,h;
	bool operator<(const sb x)const{
		return (s*x.h)>(h*x.s);
	}
}s[100500];
string st;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>st;
		for(auto j:st){
			if(j=='s'){
				s[i].s++;
			}
			else{
				res+=s[i].s;
				s[i].h++;
			}
		}
	}
	sort(s+1,s+n+1);
	for(i=1;i<=n;i++){
		res+=it*s[i].h;
		it+=s[i].s;
	}
	cout<<res;
}