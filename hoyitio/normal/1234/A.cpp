#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int cnt = 0,x;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>x;
            cnt += x;
        }
        if(cnt%n == 0){
            cout<<cnt/n<<endl;
            continue ;
        }
        cout<<cnt/n + 1<<endl;
    }


    return 0;
}