#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxx = 100005;
int a[maxx],b[maxx];
map<int,int> mp;
int main()
{
    int n,ans = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int j = 1;
    for(int i=1;i<=n;i++){
        while(mp[a[i]] != 0){
            i++;
            if(i > n){
                break;
            }
        }
        if(i > n){
            break;
        }
        int k = i;

        for( ;j<=n;j++){
            mp[b[j]] = 1;
            if(b[j] == a[k]){
                j++;
                //ans += (j - k);
                //cout<<j<<" "<<i<<endl;
                break ;
            }else{
                //cout<<j<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;




    return 0;
}