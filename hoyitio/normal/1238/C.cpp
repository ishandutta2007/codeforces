#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005];
int main()
{
    int t,h,n;
    cin>>t;
    while(t--)
    {
        int ans = 0;
        cin>>h>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        a[n+1] = 0;
        int now = a[1];
        for(int i=2;i<=n+1;i++){
            //cout<<now<<" "<<a[i]<<" "<<ans<<endl;
            if(now == 1){
                break;
            }
            if(now - a[i] >= 2){
                now = a[i] + 1;
            }
            if(now == 1){
                break;
            }
            //cout<<now<<" "<<a[i]<<" "<<ans<<endl;
            if(now - a[i] == 1){
                if(a[i] - a[i+1] == 1){
                    now = a[i + 1];
                    i++;
                    continue ;
                }
                now = a[i] - 1;
                ans++;
                continue ;
            }
        }
        cout<<ans<<endl;
    }
    return  0;
}