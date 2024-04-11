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
#define pi pair<int,int>
 
const int N=2e5+9,base=1e9,M=4;
 
int n,op,SS[N],RR[N];
pi s[N];
vector<int> ans;
vector<pair<pair<int,int> ,int >> v,cht;
map<pair<int,int>,int> mark;

vector<int> B(int x){
     vector<int> v;
     f(i,0,M-2) v.pb(x%base),x/=base;
     return v;
}
vector<int> mul(vector<int> a,vector<int> b){
    vector<int> ans(M);
    f(i,0,M-2)
        f(j,0,M-2)
            ans[i+j]+=(a[i]*b[j]);
    f(i,0,M-1)
        ans[i+1]+=ans[i]/base,ans[i]%=base;
    return ans;
}
bool is(vector<int> a,vector<int> b){
    f_(i,M-1,0){
        if(a[i]<b[i]) return 1;
        if(b[i]<a[i]) return 0;
    }
    return 0;
}
pi F1(pi a,pi b){
    return mp(b.S-a.S,a.S*b.S);
}
pi F2(pi a,pi b){
    op=0;
    a=mp(a.F*b.S,a.S*b.F);
    if((a.F<0 && 0<a.S) || (a.S<0 && 0<a.F) || a.F==0) a.F=0,a.S=1,op=1;
    return a;
}
pi tagh(pi b1,pi b2,pi c1,pi c2){
	return F2(F1(b2,c2),F1(c1,b1));
}
bool F3 (pi a,pi b){
    vector<int> af=B(a.F),
                as=B(a.S),
                bf=B(b.F),
                bs=B(b.S);
    return is(mul(af,bs),mul(bf,as));
    return ((1.0*a.F*b.S)<(1.0*b.F*a.S));
}
 
main(){
    cin>>n;
    f(i,1,n+1){
        int r,s;
        cin>>s>>r;
        SS[i]=s,RR[i]=r;
        v.pb(mp(mp(r,s),i));
    }
    sort(v.begin(),v.end());
    f(i,0,v.size()){
        int sz=cht.size()-1;
        while(cht.size() && (cht[sz].F.F==v[i].F.F || F3(tagh(mp(1,v[i].F.F),mp(1,v[i].F.S),mp(1,cht[sz].F.F),mp(1,cht[sz].F.S)),s[sz]))){
            cht.pop_back();
            sz=cht.size()-1;
        }
        if(cht.size())
            s[cht.size()]=tagh(mp(1,v[i].F.F),mp(1,v[i].F.S),mp(1,cht[sz].F.F),mp(1,cht[sz].F.S));
        cht.pb(v[i]);
    }
    f_(i,cht.size()-1,0){
        mark[cht[i].F]=1;
        if(i){
            tagh(mp(1,cht[i].F.F),mp(1,cht[i].F.S),mp(1,cht[i-1].F.F),mp(1,cht[i-1].F.S));
            if(op) break;
        }
    }
    f(i,1,n+1)
        if(mark[mp(RR[i],SS[i])])
            cout<<i<<" ";
}