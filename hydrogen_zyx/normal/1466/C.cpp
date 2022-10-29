#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

char c[N];
int main(){
    int t;
    cin>>t;
    while(t--){
        int cnt=0;
        cin>>(c+1);
        int n=strlen(c+1);
        for(int i=2;i<=n;i++){
            bool f=0;
            if(c[i]==c[i-1]||c[i]==c[i-2]){
                cnt++;
                c[i]=0;
            }
        }
        cout<<cnt<<endl;
    }
}