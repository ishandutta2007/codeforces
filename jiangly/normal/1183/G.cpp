// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    scanf("%d",&q);
    for(;q--;){
        int n;
        scanf("%d",&n);
        vector<int>c(n),x(n);
        for(int i=0;i<n;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            ++c[a-1];
            if(b==1){
                ++x[a-1];
            }
        }
        vector<vector<int>>f(n);
        for(int i=0;i<n;++i){
            if(c[i]>0){
                f[c[i]-1].push_back(x[i]);
            }
        }
        multiset<int>s;
        int sum=0,ans=0;
        for(int i=n;i>=1;--i){
            for(auto j:f[i-1]){
                s.insert(j);
            }
            if(!s.empty()){
                sum+=i;
                auto it=--s.end();
                ans+=min(i,(*it));
                s.erase(it);
            }
        }
        printf("%d %d\n",sum,ans);
    }
    return 0;
}