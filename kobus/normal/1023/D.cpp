#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF INT_MAX/2
#define MOD 1000000007
#define p 41
#define LOGMAXN 20


int n;
int v[MAXN];
int st[MAXN][LOGMAXN];

int fst[MAXN];
int lst[MAXN];

void prep(){
    for(int i=n-1;i>=0;i--){
        st[i][0]=v[i];
        for(int j=1;j<=LOGMAXN;j++)
            st[i][j]=min(st[i][j-1],st[min(i+(1<<(j-1)),n-1)][j-1]);       
    }
}

int query(int i, int j){
    int m=j-i+1;
    if(m==1)return v[i];
    m=(31-__builtin_clz(m));
    return min(st[i][m],st[j-(1<<m)+1][m]);
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);

    int q;
    cin>>n>>q;
    bool isq=0;
    bool isz=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==q)isq=1;
        if(v[i]==0)isz=1;
        if(v[i]>q){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(!isq&&!isz){
        cout<<"NO"<<endl;
        return 0;
    }
    //cout<<"AAAA"<<endl;
    for(int i=1;i<=q;i++){
        fst[i]=-1;
        lst[i]=-1;
    }
    for(int i=0;i<n;i++){
        if(v[i]==0&&isq==0){
            v[i]=q;
            isq=1;
        }
        else if(v[i]==0&&i==0){
            v[i]=1;
        }
        else if(v[i]==0){
            v[i]=v[i-1];
        }
    }
    //for(int i=0;i<n;i++)cout<<v[i]<<" ";
    //cout<<endl;
    for(int i=0;i<n;i++){
        if(fst[v[i]]==-1)fst[v[i]]=i;
        lst[v[i]]=i;
    }
    prep();
    for(int i=1;i<=q;i++){
        if(fst[i]!=-1){
            int resp=query(fst[i],lst[i]);
            //cout<<i<<" "<<fst[i]<<" "<<lst[i]<<" "<<resp<<endl;
            if(resp<i){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)cout<<v[i]<<" ";
    cout<<endl;


    return 0;
}