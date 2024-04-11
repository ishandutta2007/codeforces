#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
const int N=3e6+99;
int n,t,t2,p1=-1,a[N],k,ans,mx;
string s2;
set<pair<int,int> > s;
vector<int> v[N];
 
void change(int x,int o){
	pair<int,int> p=*s.begin();
	swap(s2[p.S],s2[p.S+1]);
	s.erase(p);
	if(p.S+1<n-1 && s2[p.S+2]=='L'){
		s.insert(mp(x+1,p.S+1));
	}
	if(p.S>=1 && s2[p.S-1]=='R') {
		s.insert(mp(x+1,p.S-1));
	}
}
int main(){
	cin>>n>>k;
	cin>>s2;
	f(i,0,n){
		if(s2[i]=='R' && p1==-1) p1=i;
		t+=(s2[i]=='R');
		if(s2[i]=='L') mx+=t;
		if(i>0 && s2[i]=='L' && s2[i-1]=='R') s.insert(mp(0,i-1));
	}
	if(mx<k) return cout<<-1,0;
	
	f(i,0,k){
		pair<int,int> g=*s.begin();
		while(g.first<=i && mx>=k-i){
			t++;
			v[i].pb(g.S);
			change(i,t);
			mx--;
			g=*s.begin();
		}
	}
	if(mx) return cout<<-1,0;
	f(i,0,k){
		printf("%d%s",v[i].size()," ");
		f(j,0,v[i].size()) printf("%d%s",v[i][j]+1," ");
		printf("\n");
	}
}