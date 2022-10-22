#include<bits/stdc++.h>
using namespace std;
int T,n; string s;
bool vis[1100000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>T;
    while (T--){
        cin>>s; n=s.length();
        // cerr<<s<<'\n';
        s="x"+s; int tot=0;
        for (int i=1;i<=n;i++) tot+=(s[i]-'0');
        if (!tot){ cout<<"-1\n"; continue;}
        if (n==1){ cout<<"1\n1 1\n"; continue;}
        int x=1; while (x<tot) x<<=1;

        int l=0,r=0;
        for (int i=1;i<=n;i++)
            if (s[i]=='1'){ r=i; if (!l) l=i;}
        if (r-l+1==tot){
            cout<<2+(r!=1&&r!=n)<<'\n';
            if (r!=1) cout<<1<<' '<<r-1<<'\n';
            cout<<r<<' '<<r<<'\n';
            if (r!=n) cout<<r+1<<' '<<n<<'\n';
            continue;
        }
        for (int i=1;i<=n;i++) vis[i]=true;
        if (tot==5){//k=3
            for (int i=1;i<=n;i++){
                assert(i<n);
                if (s[i]=='1'&&s[i+1]=='0'){
                    assert(i+2<=n);
                    vis[i]=false; vis[i+1]=false;// Merge(i,i+1,i+2);
                    break;
                }
            }
        } else{
            int k=x-tot;
            for (int i=1;i<=n&&k;i++){
                assert(i<n);
                vis[i]=false;
                if (s[i]=='1'){
                    if (i+2<=n){
                        if (s[i+1]=='0'&&k>=3){ k-=3; vis[i+1]=false; i+=2; continue;}// Merge(i,i+1,i+2)
                        if (s[i+1]=='1'&&k>=4){ k-=4; vis[i+1]=false; i+=2; continue;}// Merge(i,i+1,i+2)
                    }
                    k-=1; i+=1;// Merge(i,i+1);
                }
            }
            assert(!k);
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            if (vis[i]) ans++;
        cout<<ans<<'\n'; int lst=0,sum=0;
        for (int i=1;i<=n;i++)
            if (vis[i]){
                int t=0; for (int j=lst+1;j<=i;j++) t=((t<<1)|(s[j]-'0')); sum+=t;
                cout<<lst+1<<' '<<i<<'\n'; lst=i;
            }
        assert(sum==x);
    }
    return 0;
}