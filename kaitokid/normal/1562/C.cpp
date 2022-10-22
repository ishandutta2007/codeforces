    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    string s;
    int n;
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin>>t;
        while(t--)
        {
            cin>>n>>s;
            bool ans=false;
            for(int i=n/2;i<n;i++)
            {
                if(s[i]=='0'){cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<endl;ans=true;break;}
            }
            if(ans)continue;
            for(int i=0;i<(n/2);i++)
            {
                if(s[i]=='0'){cout<<i+1<<" "<<n<<" "<<i+2<<" "<<n<<endl;ans=true;break;}
            }

            if(ans)continue;
            cout<<1<<" "<<((n/2)*2)<<" "<<1<<" "<<(n/2)<<endl;

        }
    return 0;
    }