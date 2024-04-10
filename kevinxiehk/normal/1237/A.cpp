#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
int main(){
    int n;
    cin>>n;
    bool a=0;
    bool neg=0;
    int t;
    int d=0;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        if(arr[i]<0)neg=1;
        else neg=0;
        if(arr[i]%2==0)cout<<arr[i]/2<<endl;
        else if((a&&neg)||(!a&&!neg)){cout<<arr[i]/2<<endl;if(a==1)a=0;else a=1;}
        else{
            if(neg)cout<<(arr[i]/2)-1<<endl;
            else cout<<(arr[i]/2)+1<<endl;
            if(a==1)a=0;else a=1;
        }
    }
    return 0;
}