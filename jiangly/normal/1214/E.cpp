
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,int>> d(n);
    for(int i=0;i<n;++i){
        cin>>d[i].first;
        d[i].second=i*2;
    }
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    for(int i=0;i<n;++i){
        if(d[i].first+i==d.size()){
            d.emplace_back(0,d[i].second+1);
        }else{
            cout<<d[i+d[i].first-1].second+1<<' '<<d[i].second+2<<endl;
        }
    }
    for(int i=0;i+1<d.size();++i){
        cout<<d[i].second+1<<' '<<d[i+1].second+1<<endl;
    }
    return 0;
}