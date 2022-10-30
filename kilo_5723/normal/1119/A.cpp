#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=3e5+5,inf=1e7;
int a[maxn],b[maxn],c[maxn];
multiset<int> st;
int main(){
    int i,n;
    int ans;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    fill(b,b+n+1,inf); memset(c,-1,sizeof(c));
    for (i=n-1;i>=0;i--) b[a[i]]=i;
    for (i=0;i<n;i++) c[a[i]]=i;
    for (i=1;i<=n;i++) st.insert(b[i]);
    ans=0;
    for (i=1;i<=n;i++){
        if (c[i]!=-1){
            st.erase(st.find(b[i]));
            ans=max(ans,c[i]-(*st.begin()));
            st.insert(b[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}