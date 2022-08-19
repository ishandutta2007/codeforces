// luogu remote judge 23333
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>t;
    vector<bool>same(n);
    for(;m--;){
        int x,l,r;
        cin>>x>>l>>r;
        if(x==1){
            for(int i=l;i<r;++i){
                same[i]=true;
            }
        }else{
            t.push_back({l,r});
        }
    }
    for(auto &p:t){
        bool flag=true;
        for(int i=p.first;i<p.second;++i){
            flag&=same[i];
        }
        if(flag){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    vector<int>a(n);
    for(int i=n-1,j=1;i>=0;--i){
        a[i]=j;
        if(!same[i]){
            ++j;
        }
    }
    for(auto &i:a){
        cout<<i<<' ';
    }
    puts("");
    return 0;
}