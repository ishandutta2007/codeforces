#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn=200010;
int i,j,k,n,m,T;
int a[1000010],b[1000010],num[maxn];
priority_queue<int>Q;
map<int,int>M;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        if(m>=n)puts("0");
        else{M.clear();
            while(!Q.empty())Q.pop();
            sort(a+1,a+1+n);
            for(i=1;i<=n;i++)
                M[a[i]]++;
            int cnt=m,w=-1;
            for(i=0;i<=n+1;i++){
                // cerr<<i<<' '<<M[i]<<' '<<cnt<<endl;
                if(!M[i]){
                    if(!cnt)break;
                    --cnt;
                }w=i;
            }
            // cerr<<"w="<<w<<endl;
            int Ans=0;
            for(auto P:M){
                if(!P.second || P.first<=w)continue;
                i=P.second;
                // cerr<<"i="<<i<<' '<<P.first<<endl;
                Q.push(-i);Ans++;
            }
            // cerr<<Ans<<endl;
            while(!Q.empty()){
                if(m+Q.top()<0)break;
                m+=Q.top();Q.pop();
                Ans--;
            }
            cout<<Ans<<endl;
        }
    }
}