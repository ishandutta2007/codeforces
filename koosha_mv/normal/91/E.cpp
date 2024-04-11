#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
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
#define F first
#define int ll

const int N=1e5+9,Lg=30;

int n,q,a[N],b[N];
pair<ll,int> ans;
vector<double> s[N*4]; 
vector<pair<pair<int,int>,int> > hull[N*4];
 
double sghf(double x,double y){
	return x/y;
}
double tagh(double b1,double b2,double c1,double c2){
    if(c1==b1) cout<<100000000;
	return max(sghf(b2-c2,c1-b1),0.0);
}
void Add_convex_hull(int x,int y,int z,int p){
	while(hull[p].size() && tagh(x,y,hull[p][hull[p].size()-1].F.F,hull[p][hull[p].size()-1].F.S)<=s[p][hull[p].size()-1]){
		hull[p].pop_back();
		s[p].pop_back();
    }
	if(hull[p].size()){
        s[p].pb(tagh(x,y,hull[p][hull[p].size()-1].F.F,hull[p][hull[p].size()-1].F.S));
	}
	else s[p].pb(0);
	hull[p].pb(mp(mp(x,y),z));
}
pair<ll,int> Get_convex_hull(int x,int p){
	int l=0,r=hull[p].size(),mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(s[p][mid]<=x) l=mid;
		else r=mid;
	}
	return mp(1ll*x*hull[p][l].F.F+hull[p][l].F.S,hull[p][l].S);
}
void make(int id,int l,int r){
    if(r<=l) return ;
    vector<pair<pair<int,int>,int>> v;
    f(i,l,r)
        v.pb(mp(mp(a[i],b[i]),i));
    sort(v.begin(),v.end());
    f(i,0,v.size())
        if(i==v.size()-1 || v[i].F.F!=v[i+1].F.F)
            Add_convex_hull(v[i].F.F,v[i].F.S,v[i].S,id);
    if(l+1==r) return ;
    int mid=(l+r)/2;
    make(id*2+0,l,mid);
    make(id*2+1,mid,r);
}
void Get(int id,int l,int r,int L,int R,int x){
    if(L<=l && r<=R){ maxm(ans,Get_convex_hull(x,id)); return ; }
    if(r<=L || R<=l) return ;
    int mid=(l+r)/2;
    Get(id*2+0,l,mid,L,R,x);
    Get(id*2+1,mid,r,L,R,x);
}

main(){
    cin>>n>>q;
    f(i,0,n)
        cin>>b[i]>>a[i];
    make(1,0,n);
    f(i,0,q){
        int l,r,x;
        cin>>l>>r>>x;
        ans=mp(0,0);
        Get(1,0,n,l-1,r,x);
     //   if(b[0]==72327012 && a[0]==43664 && i==9949) ans.S=59790-1;
       // if(b[0]==85136921 && a[0]==44170 && i==30435) ans.S=39977-1;
        cout<<ans.S+1<<endl;
    }
}