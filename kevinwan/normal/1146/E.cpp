#include <bits/stdc++.h>
using namespace std;
const int mn=1<<17;
int seg[2*mn];
int add(int a,int b){
    if(a==-1)return b;
    if(a==0||a==1)return a;
    if(b==-1)return 2;
    if(b==2)return -1;
    return b^1;
}
void prop(int x){
    seg[x*2]=add(seg[x],seg[x*2]);
    seg[x*2+1]=add(seg[x],seg[x*2+1]);
    seg[x]=-1;
}
#define mid (l+r>>1)
void add(int x,int l,int r,int a,int b,int c){
    if(a==l&&b==r)seg[x]=add(c,seg[x]);
    else{
        prop(x);
        if(b<=mid)add(x*2,l,mid,a,b,c);
        else if(a>mid)add(x*2+1,mid+1,r,a,b,c);
        else add(x*2,l,mid,a,mid,c),add(x*2+1,mid+1,r,mid+1,b,c);
    }
}
int ans[mn],ians[mn];
int a[mn],x[mn];
string s[mn];
int main()
{
    memset(seg,-1,sizeof(seg));
    int n,q,i;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>q;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<q;i++)cin>>s[i]>>x[i];
    add(1,0,mn-1,0,mn-1,0);
    for(i=0;i<q;i++){
        if(s[i][0]=='>'){
            if(x[i]>=0){
                add(1,0,mn-1,x[i]+1,mn-1,1);
            }
            else{
                add(1,0,mn-1,0,-x[i]-1,2);
                add(1,0,mn-1,-x[i],mn-1,1);
            }
        }
        else{
            if(x[i]>0){
                add(1,0,mn-1,0,x[i]-1,2);
                add(1,0,mn-1,x[i],mn-1,0);
            }
            else{
                add(1,0,mn-1,-x[i]+1,mn-1,0);
            }
        }
    }
    for(i=1;i<mn;i++)prop(i);
    for(i=0;i<mn;i++)ans[i]=seg[mn+i];
    add(1,0,mn-1,0,mn-1,1);
    for(i=0;i<q;i++){
        if(s[i][0]=='>'){
            if(x[i]>=0){
                add(1,0,mn-1,x[i]+1,mn-1,1);
            }
            else{
                add(1,0,mn-1,0,-x[i]-1,2);
                add(1,0,mn-1,-x[i],mn-1,1);
            }
        }
        else{
            if(x[i]>0){
                add(1,0,mn-1,0,x[i]-1,2);
                add(1,0,mn-1,x[i],mn-1,0);
            }
            else{
                add(1,0,mn-1,-x[i]+1,mn-1,0);
            }
        }
    }
    for(i=1;i<mn;i++)prop(i);
    for(i=0;i<mn;i++)ians[i]=seg[mn+i];
    for(i=0;i<n;i++){
        if(a[i]>0)printf("%d ",a[i]*(ans[a[i]]?-1:1));
        else printf("%d ",-a[i]*(ians[-a[i]]?-1:1));
    }
}