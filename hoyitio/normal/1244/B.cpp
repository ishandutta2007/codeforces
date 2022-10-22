#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        int l = -1,r = -1;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                l = i;
                break ;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1'){
                r = n - i - 1;
                break;
            }
        }
        if(l == -1 && r == -1){
            cout<<n<<endl;
            continue ;
        }
        cout<<n*2 - 2*min(l,r)<<endl;



    }


    return 0;
}