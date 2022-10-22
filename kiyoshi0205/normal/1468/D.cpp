#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int N,M,A,B;cin>>N>>M>>A>>B;
        if(A>B){
            A=N+1-A;
            B=N+1-B;
        }
        vector<int> v(M);
        rep(i,M)cin>>v[i];
        sort(v.begin(),v.end());
        M=min(M,B-A-1);
        v.resize(M);
        reverse(v.begin(),v.end());
        int ans=0;
        B-=2;int i=0;
        v.emplace_back(-1);
        while(i<M){
            while(v[i]>B)++i;
            if(i==M)break;
            ans++;
            ++i;
            --B;
        }
        cout<<ans<<endl;
    }
}