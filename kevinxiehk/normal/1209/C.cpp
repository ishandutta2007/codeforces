#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int freq[11];
        int arr[n+5];
        int ans[n+5];
        for(int i=0;i<=10;i++)freq[i]=0;
        int done=0;
        int m=10,mpos;
        for(int i=0;i<n;i++){
            arr[i]=s[i]-'0';
            freq[arr[i]]++;
            if(arr[i]<m){
                m=arr[i];
                mpos=i;
            }
        }
        int now=m;
        for(int i=mpos;i<n;i++){
            if(arr[i]==now){
                ans[i]=1;
                freq[now]--;
                done++;
                arr[i]=10;
                while(freq[now]==0)now++;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==now){
                ans[i]=2;
                freq[now]--;
                done++;
                while(freq[now]==0)now++;
            }
        }
        if(done==n)for(int i=0;i<n;i++)cout<<ans[i];
        else cout<<"-";
        cout<<endl;
    }
    return 0;
}