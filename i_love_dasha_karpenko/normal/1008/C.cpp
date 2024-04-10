#include <bits/stdc++.h>

using namespace std;

long long n,arr[100007],j,k=0;
queue<long> Q;
int main()
{
    cin>>n;
    for (int i = 0; i<n; i++) cin>>arr[i];
    sort(arr,arr+n);

    for (int i = 0;i<n;i++){
        if (Q.size()!=0 && Q.front()<arr[i]){
            k++;
            Q.pop();
        }
        Q.push(arr[i]);
    }
    cout<<k;

}