#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair<int,int>pii;
const int mn=2e5+10;
typedef complex<double> C;
const double pi=acos(-1);
vector<C>w;
vector<int>ord;
void getroots(int n){
    if(w.size()>=n)return;
    if(!w.size())w={0,1};
    int len=w.size();
    w.resize(n);
    for(;len<n;len<<=1){
        C ang=polar(1.,pi/len);
        for(int i=0;i<len;i++){
            if(i&1)w[len+i]=w[len+i-1]*ang;
            else w[len+i]=w[(len+i)>>1];
        }
    }
}
void reorder(vector<C>&a){
    int n=a.size();
    if(ord.size()!=n){
        ord.assign(n,0);
        for(int i=1;i<n;i++)ord[i]=(ord[i>>1]>>1)|((i&1)?n>>1:0);
    }
    for(int i=1;i<n;i++)if(ord[i]<i)swap(a[i],a[ord[i]]);
}
void fft(vector<C>&a){
    int n=a.size();
    getroots(n),reorder(a);
    for(int len=1;len<n;len<<=1)for(int i=0;i<n;i+=len<<1)for(int j=0;j<len;j++){
        C u=a[i+j],v=a[i+j+len]*w[j+len];
        a[i+j]=u+v,a[i+j+len]=u-v;
    }
}
vector<ll> convolve(vector<ll>a,vector<ll>b){
    int n=a.size()+b.size();
    n=1<<(32-__builtin_clz(n-1));
    vector<C>c(n);
    for(int i=0;i<a.size();i++)c[i].real(a[i]);
    for(int i=0;i<b.size();i++)c[i].imag(b[i]);
    fft(c);
    C r={0,-0.5/n};
    reverse(c.begin()+1,c.end());
    for(int i=0;i<n;i++)c[i]*=c[i],c[i]*=r;
    fft(c);
    vector<ll>ret(a.size()+b.size()-1);
    for(int i=0;i<ret.size();i++)ret[i]=c[i].real()+.5;
    return ret;
}
int ls[mn];
vector<ll>ss[4];
vector<ll>tt[4];
vector<ll>c[4];
vector<ll>ans;
int toi[256];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    string s,t;
    cin>>s>>t;
    toi['C']=1,toi['G']=2,toi['T']=3;
    for(int i=0;i<4;i++)ss[i].resize(n),tt[i].resize(m);
    ls[0]=ls[1]=ls[2]=ls[3]=-0x3f3f3f3f;
    for(int i=0;i<n;i++){
        ls[toi[s[i]]]=i;
        for(int j=0;j<4;j++)if(i-ls[j]<=k)ss[j][i]=1;
    }
    ls[0]=ls[1]=ls[2]=ls[3]=0x3f3f3f3f;
    for(int i=n-1;i>=0;i--){
        ls[toi[s[i]]]=i;
        for(int j=0;j<4;j++)if(ls[j]-i<=k)ss[j][i]=1;
    }
    for(int i=0;i<m;i++)tt[toi[t[i]]][i]=1;
    for(int i=0;i<4;i++){
        reverse(tt[i].begin(),tt[i].end());
        c[i]=convolve(ss[i],tt[i]);
        ans.resize(c[i].size());
        for(int j=0;j<ans.size();j++)ans[j]+=c[i][j];
    }
    int hail=0;
    for(int i=0;i<n;i++)hail+=(ans[i+m-1]==m);
    printf("%d",hail);
}