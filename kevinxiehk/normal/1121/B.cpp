#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    priority_queue<int>aaa;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            aaa.push(arr[i]+arr[j]);
        }
    }
    int ans=0;
    int lst=-1;
    int now=0;
    int cnt=0;
    while(!aaa.empty()){
        now=aaa.top();
        if(now!=lst){
            cnt=1;
        }
        else cnt++;
        ans=max(ans,cnt);
        lst=now;
        aaa.pop();
    }
    cout<<ans<<endl;
    return 0;
}