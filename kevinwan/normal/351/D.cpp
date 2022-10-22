#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=4e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct BIT{
	int bit[mn];
	void upd(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
	int qu(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
};
struct query{
	int l,r,i;
};
int a[mn],ans[mn];
BIT bs,av;
int lv[mn],lav[mn];
int lv2[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
   	int n;
   	cin>>n;
   	for(int i=1;i<=n;i++)cin>>a[i];
   	int q;
   	cin>>q;
   	vector<query>v;
   	for(int i=0;i<mn;i++)lv[i]=lv2[i]=lav[i]=n+1;
   	for(int i=0;i<q;i++){
   		int l,r;
   		cin>>l>>r;
   		v.push_back({l,r,i});
   	}
   	sort(v.begin(),v.end(),[](auto a,auto b){return a.l>b.l;});
   	int cl=n+1;
   	for(query q:v){
   		while(cl>q.l){
   			cerr<<cl-1<<endl;
   			cl--;
   			bs.upd(cl,1);
   			bs.upd(lv[a[cl]],-1);
   			if(cl-lv[a[cl]]!=lv[a[cl]]-lv2[a[cl]]){
   				av.upd(lv2[a[cl]],1);
   				av.upd(lav[a[cl]],-1);
   				lav[a[cl]]=lv2[a[cl]];
   			}
   			lv2[a[cl]]=lv[a[cl]];
   			lv[a[cl]]=cl;
   		}
   		ans[q.i]=bs.qu(q.r)-(av.qu(q.r)<bs.qu(q.r));
   	}
   	for(int i=0;i<q;i++)printf("%d\n",ans[i]+1);
}