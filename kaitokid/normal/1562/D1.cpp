    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    string s;
    int n,pr[300009],q;
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin>>t;
        while(t--)
        {
            cin>>n>>q>>s;
            pr[0]=0;
            for(int i=1;i<=n;i++)
                {
                    int f;
                    if(s[i-1]=='+')f=1;
                    else f=-1;
                    if(i%2)pr[i]=pr[i-1]+f;
                    else pr[i]=pr[i-1]-f;}
            for(int i=0;i<q;i++)
            {
                int l,r;
                cin>>l>>r;
                int u=pr[r]-pr[l-1];
                u=abs(u);
                if(u==0){cout<<0<<endl;continue;}
                if(u%2){cout<<1<<endl;}
                else cout<<2<<endl;
            }

        }
    return 0;
    }