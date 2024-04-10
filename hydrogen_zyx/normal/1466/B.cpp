#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int a[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        int cnt=1;
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]) a[i]++;
            else if(a[i]==a[i-1]-1) a[i]=a[i-1];
            if(a[i]!=a[i-1]) cnt++;
        }
        cout<<cnt<<endl;
    }
}