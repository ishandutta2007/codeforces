#include <bits/stdc++.h>
using namespace std;
int n,k,a[100000];
vector<int> V;
int main(){
    cin>>n>>k;
    cin>>a[0];
    V.push_back(0);
    for(int i=1 ; i<n ; i++){
        cin>>a[i];
        if(a[i]==a[i-1])V.push_back(i);
    }
    V.push_back(n);
    int ans=0;
    for(int i=1 ; i<V.size() ; i++){
        ans =max(ans,V[i]-V[i-1]);
    }
    cout<<ans;
}