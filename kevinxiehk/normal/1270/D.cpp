#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
int n,k;
void ask(int a,int b){
    cout<<"?";
    for(int i=a;i<=b;i++)cout<<" "<<(i%n)+1;
    cout<<endl;
    fflush(stdout);
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    n=k+1;
    int x,y;int arr[n+5];
    for(int i=0;i<n;i++){
        ask(i,i+k-1);
        cin>>x>>y;
        arr[i]=y;
    }
    sort(arr,arr+n);
    int cnt=0;
    while(arr[cnt]==arr[0])cnt++;
    cout<<"! "<<n-cnt<<endl;
}