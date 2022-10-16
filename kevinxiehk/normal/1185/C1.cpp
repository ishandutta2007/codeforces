#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
bool cmp(int a,int b){return a>b;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int arr[n+5];
    int arr2[n+5];
    for(int i=0;i<n;i++){cin>>arr[i];arr2[i]=arr[i];}
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int cnt=0;
        if(sum>m){
            sort(arr2,arr2+i,cmp);
            int t=0;
            while(t<sum-m){cnt++;t+=arr2[cnt-1];}
        }
        cout<<cnt<<" ";
    }
    cout<<endl;
    return 0;
}