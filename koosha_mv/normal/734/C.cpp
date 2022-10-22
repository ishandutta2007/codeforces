#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll n,m,k,x,s,sefr=0;
pair <ll,ll> p1[200009],p2[200009];
int main(){
	cin>>n>>m>>k>>x>>s;
	f(i,1,m+1) cin>>p1[i].second;
	f(i,1,m+1) cin>>p1[i].first;
	f(i,1,k+1) cin>>p2[i].second;
	f(i,1,k+1) cin>>p2[i].first;
	sort(p1,p1+m+1);
	p1[0].first=0;p1[0].second=x;
	p2[0].first=0;p2[0].second=0;
	f(i,1,m+1){
		p1[i].second=min(p1[i].second,p1[i-1].second);
	}
	ll po1=0,po2=k,mnt=9e18;
	while(po1<=m && po2>=0){
		if(p1[po1].first>s)
			break;
		if(p1[po1].first+p2[po2].first<=s){
			mnt=min(mnt,max(n-p2[po2].second,sefr)*p1[po1].second);
			po1++;
		}
		else if(po2>0) po2--;
	}
	cout<<mnt;
}