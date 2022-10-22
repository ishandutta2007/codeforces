#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll p1=1e9+7,p2=1e9+9;
ll po1[mn],po2[mn];
ll h1[mn],h2[mn],rh1[mn],rh2[mn];
const ll m=rng();
int n;
vector<int>manacher(string S){
    string s="$";
    for(char c:S)s.push_back(c),s.push_back('$');
    int n=s.size();
    vector<int>v(n);
    for(int m=0,l=0,r=0,cl=0,cr=0;m<n;){
        while(l-1>=0&&r+1<n&&s[l-1]==s[r+1])l--,r++;
        v[m]=r-m;
        cl=m-1,cr=m+1;
        while(cr<=r){
            v[cr]=min(r-cr,v[cl]);
            if(v[cr]==r-cr)break;
            cr++,cl--;
        }
        m=cr;
        //r=max(r,cr);
        l=2*m-r;
    }
    return v;
}
int main(){
 
    int tc;
    po1[0]=po2[0]=1;
    for(int i=1;i<mn;i++)po1[i]=po1[i-1]*m%p1,po2[i]=po2[i-1]*m%p2;
    scanf("%d",&tc);
    while(tc--){
        string s;
        cin>>s;
        n=s.size();
        for(int i=0;i<=n+1;i++)h1[i]=h2[i]=rh1[i]=rh2[i]=0;
        s=" "+s;
        for(int i=1;i<=n;i++)h1[i]=(h1[i-1]*m+s[i])%p1,h2[i]=(h2[i-1]*m+s[i])%p2;
        for(int i=n;i;i--)rh1[i]=(rh1[i+1]*m+s[i])%p1,rh2[i]=(rh2[i+1]*m+s[i])%p2;
        int fr=0;
        for(int i=0;i<n;i++){
            if(s[1+i]==s[n-i])fr++;
            else break;
        }
        if(fr==n){
            printf("%s\n",s.c_str()+1);
            continue;
        }
        int bes=fr*2,pl=2,pr=1,ee=fr;
        vector<int>v=manacher(s);
        for(int i=1;i<=n;i++){
            int kaka=v[2*i+1];
            int l=i-kaka/2,r=i+kaka/2;
            int ex=min(min(l-1,n-r),fr);
            if(ex+1!=l&&n-ex!=r)continue;
            int len=r-l+1+2*ex;
            if(len>bes){
                pl=l,pr=r,ee=ex,bes=len;
            }
        }
        for(int i=1;i<n;i++){
            int kaka=v[2*i+2];
            int l=i-kaka/2+1,r=i+kaka/2;
            int ex=min(min(l-1,n-r),fr);
            if(ex+1!=l&&n-ex!=r)continue;
            int len=r-l+1+2*ex;
            if(len>bes){
                pl=l,pr=r,ee=ex,bes=len;
            }
        }
        for(int i=1;i<=ee;i++)printf("%c",s[i]);
        for(int i=pl;i<=pr;i++)printf("%c",s[i]);
        for(int i=n+1-ee;i<=n;i++)printf("%c",s[i]);
        printf("\n");
    }
}