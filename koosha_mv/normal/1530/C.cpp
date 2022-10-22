    #include <bits/stdc++.h>
    using namespace std;
    #define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
    #define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
    #define Get(x,y) scanf("%I64d%I64d",&x,&y);
    #define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
    #define eror(x) cout<<#x<<'='<<(x)<<endl;
    #define f_(i,a,b) for(int i=a;i>=b;i--)
    #define Gett(x,y) scanf("%d%d",&x,&y);
    #define f(i,a,b) for(int i=a;i<b;i++)
    #define get(x) scanf("%I64d",&x);
    #define gett(x) scanf("%d",&x);
    #define maxm(a,b) a=max(a,b);
    #define minm(a,b) a=min(a,b);
    #define Add(x,y) x=(x+y)%mod
    #define lst(x) x[x.size()-1]
    #define sz(x) int(x.size())
    #define mp make_pair
    #define ll long long
    #define pb push_back
    #define S second
    #define F first
     
    const int N=25;
     
    int n,m,a[N][N],t;
     
    int main(){
        cin>>t;
        while(t--){
            int ans=0;
            vector<int> v1,v2;
            cin>>n;
            f(i,0,n){
                int x;
                cin>>x;
                v1.pb(x);
            }
            f(i,0,n){
                int x;
                cin>>x;
                v2.pb(x);
            }
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            reverse(v1.begin(),v1.end());
            reverse(v2.begin(),v2.end());
            int p1=v1.size()-(v1.size()/4),p2=v2.size()-(v2.size()/4);
            f(i,0,p1) ans+=v1[i];
            f(i,0,p2) ans-=v2[i];
            int res=0;
            //cout<<ans<<endl;
            for(;ans<0;){
                res++;
                ans+=100;
                if((res+n)%4==0) ans-=v1[--p1];
                if((res+n)%4!=0 && p2!=n) ans-=v2[p2++];
              //  cout<<ans<<endl;
            }
            cout<<res<<endl;
        }
    }