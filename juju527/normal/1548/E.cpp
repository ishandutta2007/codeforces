#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,maxm=2e5+5,inf=0x3f3f3f3f;
int n,m,wa,wb;
int a[maxn],b[maxm];
int mx[maxn],mxa[maxn],mxb[maxm];
stack<int>st;
vector<int>I[maxm],D[maxm];
vector<pair<int,int> >Q[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int lowbit[maxn],t[maxn];
void update(int x,int v){while(x<=wa)t[x]+=v,x+=lowbit[x];return ;}
int query(int x){int res=0;while(x)res+=t[x],x-=lowbit[x];return res;}
int main(){
    int x;
    n=read();m=read();x=read();
    for(int i=1;i<=n;i++)a[i]=read(),wa=max(wa,a[i]);
    for(int j=1;j<=m;j++)b[j]=read(),wb=max(wb,b[j]);
//    for(int i=1;i<=n;i++,cout<<endl)for(int j=1;j<=m;j++)cout<<min(a[i]+b[j],7)<<" ";
    for(int i=1;i<=n;i++){
        while(!st.empty()&&a[st.top()]>=a[i])mx[i]=max(mx[i],mx[st.top()]),st.pop();
        st.push(i);mx[i]=max(mx[i],a[i]);mxa[i]=mx[i];
        if(st.size()==1)mxa[i]=x;
    }
    while(!st.empty())st.pop();
    memset(mx,0,sizeof(mx));
    for(int i=1;i<=m;i++){
        while(!st.empty()&&b[st.top()]>=b[i])mx[i]=max(mx[i],mx[st.top()]),st.pop();
        st.push(i);mx[i]=max(mx[i],b[i]);mxb[i]=mx[i];
        if(st.size()==1)mxb[i]=x;
    }
    while(!st.empty())st.pop();
    memset(mx,0,sizeof(mx));
    for(int i=n;i>=1;i--){
        while(!st.empty()&&a[st.top()]>a[i])mx[i]=max(mx[i],mx[st.top()]),st.pop();
        st.push(i);mx[i]=max(mx[i],a[i]);
        if(st.size()>1)mxa[i]=min(mxa[i],mx[i]);
    }
    while(!st.empty())st.pop();
    memset(mx,0,sizeof(mx));
    for(int i=m;i>=1;i--){
        while(!st.empty()&&b[st.top()]>b[i])mx[i]=max(mx[i],mx[st.top()]),st.pop();
        st.push(i);mx[i]=max(mx[i],b[i]);
        if(st.size()>1)mxb[i]=min(mxb[i],mx[i]);
    }
    a[0]=b[0]=a[n+1]=b[m+1]=inf;
//    for(int i=1;i<=n;i++)cout<<mxa[i]<<" ";cout<<endl;
//    for(int i=1;i<=m;i++)cout<<mxb[i]<<" ";cout<<endl;
//    for(int i=1;i<=n;i++)cout<<bana[i]<<" ";cout<<endl;
//    for(int i=1;i<=m;i++)cout<<banb[i]<<" ";cout<<endl;
    for(int i=1;i<=m;i++){
        if(b[i]>=x)continue;
        Q[b[i]].push_back(make_pair(x-mxb[i],x-b[i]));
    }
    for(int i=1;i<=n;i++){
        if(a[i]>=x)continue;
        if(max(x-mxa[i]+1,1)>x-a[i])continue;
        I[max(x-mxa[i]+1,1)].push_back(a[i]);
        D[x-a[i]].push_back(a[i]);
//        cout<<"*"<<i<<" "<<max(x-mxa[i]+1,1)<<" "<<x-a[i]<<endl;
    }
    for(int i=1;i<=wa;i++)lowbit[i]=(i&-i);
    ll res=0;
    for(int i=1;i<=wb;i++){
        for(int j=0;j<I[i].size();j++)update(I[i][j],1)/*,cout<<"+"<<i<<" "<<I[i][j]<<endl*/;
        for(int j=0;j<Q[i].size();j++){
            int l=Q[i][j].first,r=Q[i][j].second;
            l=max(l,0);r=min(r,wa);
            if(l>r)continue;
            //cout<<i<<" "<<l+1<<" "<<r<<endl;
            res+=query(r)-query(l);
        }
        for(int j=0;j<D[i].size();j++)update(D[i][j],-1)/*,cout<<"-"<<i<<" "<<D[i][j]<<endl*/;
    }
    printf("%lld\n",res);
    return 0;
}