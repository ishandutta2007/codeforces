#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mn=2e5+10;

int a[mn],o[mn],ro[mn];
string s;
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>s;
    iota(o,o+n,0);
    sort(o,o+n,[](int i,int j){
        if(s[i]!=s[j])return s[i]<s[j];
        return a[i]<a[j];
    });
    for(int i=0;i<n;i++){
        ro[o[i]]=i;
    }
    for(int i=0;i<n;i++)printf("%d ",ro[i]+1);
    printf("\n");
}

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}