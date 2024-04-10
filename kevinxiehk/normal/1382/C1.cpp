#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[2][n+5];
    char c;
    for(int i=0;i<=1;i++){
        for(int j=0;j<n;j++){
            cin>>c;
            if(c=='0')arr[i][j]=0;
            else arr[i][j]=1;
        }
    }
    queue<int>ans;
    bool ahh=false;
    for(int i=n-1;i>=0;i--){
        if(arr[0][i]!=arr[1][i]){
            ahh=false;
            if(arr[0][0]!=arr[0][i]){ahh=true;arr[0][0]=(arr[0][0]+1)%2;}
            if(ahh)ans.push(1);
            ans.push(i+1);
            for(int j=0;j<=i/2;j++){
                if(arr[0][j]==arr[0][i-j]){
                    int t=arr[0][j]+1;
                    t%=2;
                    arr[0][j]=t;
                    arr[0][i-j]=t;
                }
            }
        }
    }
    cout<<ans.size();
    while(!ans.empty()){cout<<" "<<ans.front();ans.pop();}
    cout<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}