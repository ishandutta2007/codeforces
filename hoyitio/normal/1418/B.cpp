#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[222222],b[222222];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int i;
        for(i=0;i<n;i++)cin>>a[i];
        for(i=0;i<n;i++)cin>>b[i];
        vector<int>temp;
        for(i=0;i<n;i++){
            if(!b[i])temp.push_back(a[i]);
        }
        sort(temp.rbegin(),temp.rend());
        vector<int>res;
        int j=0;
        for(i=0;i<n;i++){
            if(!b[i])res.push_back(temp[j]),j++;
            else res.push_back(a[i]);
        }
        for(i=0;i<n;i++)cout<<res[i]<<' ';
        cout<<endl;
    }
}