#include <bits/stdc++.h>

using namespace std;

#define DIM 107
#define INF 1000000007
long long n,arr[DIM],res=0;

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    for (int i  = 0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for (int i = 0;i<n;i+=2){
        int to = arr[i+1]-arr[i];
        res+=to;
        arr[i]+=to;
    }
    cout<<res;
}