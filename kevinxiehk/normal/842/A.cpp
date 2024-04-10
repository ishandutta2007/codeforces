#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,r,x,y,k;
    cin>>l>>r>>x>>y>>k; 
    for(int i=l;i<=r;i++){
        if(i%k)continue;
        else{
            int a=i/k;
            if(a<=y&a>=x){cout<<"YES"<<endl;return 0;}
        }
    }
    cout<<"NO"<<endl;
    return 0;
}