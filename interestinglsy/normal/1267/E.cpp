#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=105;

int vl[maxn][maxn];
int n,m;
pair<int,int> g[maxn];
bool ok[maxn];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){cin>>vl[i][j];}
    }
    vector<int> ans;
    bool gt=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            g[j]=make_pair(vl[j][n]-vl[j][i],j);
        }
        sort(g+1,g+1+m);
        vector<int> cur;
        int sm=0;
        for(int i=1;i<=m;i++){
            sm+=g[i].first;
            if(sm<=0)cur.push_back(g[i].second);
        }
        if(cur.size()>ans.size()) ans=cur;
    }
    for(int i=0;i<ans.size();i++){ok[ans[i]]=1;}
    cout<<m-ans.size()<<endl;
    for(int i=1;i<=m;i++){if(!ok[i])cout<<i<<' ';}
    return 0;
}