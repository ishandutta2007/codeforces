#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int n,q;
int a[N];
pair<int,int>res[N];
int res2[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>q;
	for(int i=0;i<n;++i)cin>>a[i];
	queue<int>que;
	for(int i=0;i<n;++i)que.push(a[i]);
	int cur=-1;
	for(int i=0;i<n-1;++i){
		int a=que.front();que.pop();
		if(cur==-1){
			int b=que.front();que.pop();
			res[i]={a,b};
			if(a>b){
				cur=a;
				a=b;
			}else cur=b;
		}
		else res[i]={cur,a};
		if(cur<a)swap(cur,a);
		res2[i]=a;
		que.push(a);
	}
	while(q--){
		ll qq;cin>>qq;--qq;
		if(qq>=n-1)cout<<cur<<" "<<res2[qq%(n-1)]<<endl;
		else cout<<res[qq].first<<" "<<res[qq].second<<endl;
	}
}