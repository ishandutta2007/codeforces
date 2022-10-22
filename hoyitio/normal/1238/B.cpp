#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[100005];
map<int, int > mp;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,r,cnt = 0,k = 0,x;
        mp.clear();
        cin>>n>>r;
        cnt = n;
        for(int i=1;i<=n;i++){
            cin>>x;
            if(mp[x] == 0){
                mp[x] = 1;
                a[++k] = x;
            }
        }
        sort(a+1,a+1+k);
        int sum = 0;

        for(int i=k;i>=1;i--)
        {
            sum += r;
            //cout<<a[i]<<" "<<sum<<endl;
            if(a[i-1] - sum <= 0){
                cnt = k - i + 1;
                break;
            }
        }
        cout<<cnt<<endl;
    }
    return  0;
}