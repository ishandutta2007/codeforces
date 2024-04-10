#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxx = 200005;
map<int,int> mp;
queue<int> q;
int a[maxx];
int main()
{
    int n,k,x;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(q.size() < k)
        {
            if(mp[x] == 0){
                q.push(x);
                mp[x] = 1;
            }
            else{
                continue ;
            }
        }
        else{
            if(mp[x] == 0){
                mp[x] = 1;
                int now = q.front();
                mp[now] = 0;
                q.pop();
                q.push(x);
            }
            else{
                continue ;
            }
        }
    }
    int cnt = 0;
    while(!q.empty()){
        a[++cnt] = q.front();
        q.pop();
    }
    cout<<cnt<<endl;
    for(int i=cnt;i>=1;i--){
        cout<<a[i]<<" ";
    }



    return 0;
}