    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    string s;
    bool pr[1000009];
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        pr[1]=true;
        for(int i=2;i<1000;i++)
            if(!pr[i])
            for(int j=i*i;j<=1000000;j+=i)pr[j]=true;
        int t;
        cin>>t;
        while(t--)
        {
            int n;
        cin>>n>>s;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            int u=s[i]-'0';
            if(pr[u]){ans=u;break;}
        }
        if(ans!=-1){cout<<1<<endl<<ans<<endl;continue;}
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {

            int u=(s[i]-'0')*10 +(s[j]-'0');
            if(pr[u]){ans=u;break;}
        }
        if(ans!=-1){cout<<2<<endl<<ans<<endl;continue;}
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        for(int q=j+1;q<n;q++)
        {

            int u=(s[i]-'0')*100 +(s[j]-'0')*10 +(s[q]-'0');
            if(pr[u]){ans=u;break;}
        }
        if(ans!=-1){cout<<3<<endl<<ans<<endl;continue;}



        }
    return 0;
    }