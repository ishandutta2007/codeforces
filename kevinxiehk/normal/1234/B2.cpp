#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    map<int,bool>inlist;
    int cnt=0;
    int lst[n+5];
    int id=0;
    for(int i=0;i<n;i++){
        if(!inlist[arr[i]]){
            lst[id]=arr[i];
            id++;
            inlist[arr[i]]=true;
            if(cnt==k){
                inlist[lst[id-k-1]]=false;
            }
            else cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout<<lst[id-1-i];
        if(i==cnt-1)cout<<endl;
        else cout<<" ";
    }
    return 0;
}