#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n , m , t;
string s;
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>m>>s;
        ll j = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '0'){
                ll minn = min(1ll*(i-j) , m);
                swap(s[i] , s[i - minn]);
                j++;
                m -= minn;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}