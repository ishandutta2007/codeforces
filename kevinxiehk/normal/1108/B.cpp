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
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n,cmp);
    int x=arr[0];
    stack<int>mul;
    for(int i=1;i<=x;i++){
        if(x%i==0)mul.push(i);
    }
    for(int i=0;i<n;i++){
        if(!mul.empty()&&mul.top()==arr[i])mul.pop();
        else{cout<<x<<" "<<arr[i]<<endl;return 0;}
    }
    return 0;
}