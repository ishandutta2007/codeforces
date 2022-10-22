//Oshvleiki Svlaiyoska Ranasku sachi
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
int ps[mn],pt[mn],ns[mn],nt[mn];
int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    s=" "+s;
    t=" "+t;
    for(int i=1;i<=n;i++)ps[i]=ps[i-1]+(s[i]!='A');
    for(int i=1;i<=m;i++)pt[i]=pt[i-1]+(t[i]!='A');
    for(int i=1;i<=n;i++)if(s[i]=='A')ns[i]=ns[i-1]+1;
    for(int i=1;i<=m;i++)if(t[i]=='A')nt[i]=nt[i-1]+1;
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int nbcs=ps[b]-ps[a-1],nbct=pt[d]-pt[c-1];
        int aa=min(b-a+1,ns[b]);
        int bb=min(d-c+1,nt[d]);
        if(nbcs%2!=nbct%2)printf("0");
        else if(aa<bb)printf("0");
        else if(nbcs>nbct)printf("0");
        else if(nbcs==0&&aa==bb&&nbct>0)printf("0");
        else if(nbcs<nbct)printf("1");
        else{
            if(aa%3==bb%3)printf("1");
            else printf("0");
        }
    }
}