// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
bool count(vector<int> &a,int x){
    auto i=lower_bound(a.begin(),a.end(),x);
    return i!=a.end()&&(*i)==x;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("CF1183F.in","r",stdin);
    freopen("CF1183F.out","w",stdout);
#endif
    int q;
    scanf("%d",&q);
    for(;q--;){
        int n;
        scanf("%d",&n);
        vector<int>a(n);
        for(auto &i:a){
            scanf("%d",&i);
        }
        sort(a.begin(),a.end());
        vector<int>b;
        for(int i=n-1;i>=0&&b.size()<3;--i){
            bool flag=true;
            for(auto &j:b){
                if(j%a[i]==0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                b.push_back(a[i]);
            }
        }
        int ans=0;
        for(auto &i:b){
            ans+=i;
        }
        int mx=a[n-1];
        if(mx%30==0&&count(a,mx/2)&&count(a,mx/3)&&count(a,mx/5)){
            ans=max(ans,mx*31/30);
        }
        printf("%d\n",ans);
    }
    return 0;
}