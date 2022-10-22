#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    int a,b,c,d,e;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>e;
        int flag = 0;
        int ans1 , ans2;
        if(a%c == 0){
            ans1 = a/c;
        }else{
            ans1 = a/c + 1;
        }

        if(b%d == 0){
            ans2 = b/d;
        }else{
            ans2 = b/d + 1;
        }
        if(ans1 + ans2  <= e){
            cout<<ans1<<" "<<ans2<<endl;
            continue ;
        }
        cout<<"-1"<<endl;


    }


    return 0;
}