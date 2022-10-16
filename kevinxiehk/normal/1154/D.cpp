#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n>>a>>b;
    int bb=b;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        if(a<=0&&b<=0){cout<<i<<endl;return 0;}
        if(a<=0||b==bb||arr[i]==0){
            if(b<=0){a--;}
            else b--;
        }
        else{a--;b++;}
    }
    cout<<n<<endl;
    return 0;
}