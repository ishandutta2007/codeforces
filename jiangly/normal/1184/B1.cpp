// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>x(n);
    for(int i=0;i<n;++i){
        cin>>x[i];
    }
    vector<pair<int,int>>y(m);
    vector<int>sum(m+1);
    for(int i=0;i<m;++i){
        cin>>y[i].first>>y[i].second;
    }
    sort(y.begin(),y.end());
    for(int i=0;i<m;++i){
        sum[i+1]=sum[i]+y[i].second;
    }
    for(int i=0;i<n;++i){
        int c=upper_bound(y.begin(),y.end(),make_pair(x[i],inf))-y.begin();
        cout<<sum[c]<<' ';
    }
    cout<<endl;
    return 0;
}