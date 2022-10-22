    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin>>t;
        while(t--)
        {
            ll l,r;
            cin>>l>>r;
            ll u=max(r/2+1,l);
            cout<<(r%u)<<endl;
        }
    return 0;
    }