#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3510;
int a[mn];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        vector<int>v;
        for(int i=0;i+(n-m+1)-1<n;i++){
            v.push_back(max(a[i],a[i+n-m]));
        }
        int sz=v.size()-k;
        sz=max(sz,1);
        int ans=0xc0c0c0c0;
        for(int i=0;i+sz-1<v.size();i++){
            int hail=0x3f3f3f3f;
            for(int j=i;j<i+sz;j++)hail=min(hail,v[j]);
            ans=max(ans,hail);
        }
        printf("%d\n",ans);
    }
}