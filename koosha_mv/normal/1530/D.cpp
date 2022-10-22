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
     
    const int N=1e6+99;
     
    int n,t,tek,res,m,a[N],ans[N],mark[N],vis[N];
     
    int main(){
        cin>>t;
        while(t--){
            vector<int> v;
            int lst=0;
            tek=res=m=0;
            cin>>n;
            f(i,1,n+1){ cin>>a[i]; res+=(mark[a[i]]==0); mark[a[i]]++; }
            f(i,1,n+1){
                if(vis[a[i]]==0)
                    ans[i]=a[i],vis[a[i]]=1;
                else 
                    ans[i]=0,lst=i,tek++;
            }
            f(i,1,n+1)
                if(ans[i]==0 && tek==1 && vis[i]==0){
                    int u;
                    f(j,1,i)
                        if(a[j]==a[i])
                            u=j;
                    swap(ans[i],ans[u]);
                    break;
                }
            f(i,1,n+1)
                if(!vis[i])
                    v.pb(i);
            f(i,1,n+1){
                if(ans[i]==0){
                    if(v.size()>1 && v[v.size()-1]==lst)
                        ans[i]=v[v.size()-1],v.pop_back();
                    else{
                        if((v.size()>1 && v[v.size()-2]==lst) || v[v.size()-1]==i){
                            int u=v[v.size()-1];
                            v.pop_back();
                            ans[i]=v[v.size()-1];
                            v.pop_back();
                            v.pb(u);
                        }
                        else{
                            ans[i]=v[v.size()-1],v.pop_back();
                        }
                    }
                }
            }
            cout<<res<<endl;
            f(i,1,n+1) cout<<ans[i]<<" ";
            cout<<endl;
            f(i,1,n+1) mark[i]=vis[i]=0;
        }
    }