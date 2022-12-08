#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-3
#define f first
#define s second
#define MAXN 512345
#define INF LLONG_MAX/4
#define double long double
#define MOD 1000000007

int n;
int v[112];
int memo[112][11234];

int tothe(int x,int a){
    if(a==0)return 1;
    if(a==1)return x;
    if(a%2==0)return tothe((x*x)%MOD,a/2);
    return (x*tothe((x*x)%MOD,a/2))%MOD;
}

int choose(int num,int j){
    int resp=1;
    for(int i=2;i<=num;i++){
        resp*=i;
        resp%=MOD;
    };
    for(int i=2;i<=j;i++){
        resp*=tothe(i,MOD-2);
        resp%=MOD;
    }
    for(int i=2;i<=num-j;i++){
        resp*=tothe(i,MOD-2);
        resp%=MOD;
    }
    //cout<<num<<" "<<j<<" deu "<<resp<<endl;
    return resp;
}


void ways(){
    memo[0][0]=1;
    for(int i=0;i<n;i++){
        //cout<<v[i]<<endl;
        for(int j=n;j>=0;j--){
            for(int k=11233;k>=0;k--){
                if(v[i]+k<11234){
                    memo[j+1][v[i]+k]+=memo[j][k];
                    //if(memo[j][k]>0)cout<<"adiciona "<<memo[j][k]<<" a "<<j+1<<" "<<v[i]+k<<" com "<<v[i]<<endl;
                    if(memo[j+1][v[i]+k]>=MOD)
                        memo[j+1][v[i]+k]-=MOD;
                }
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v,v+n);
    set<int> s;
    bool doistipo=0;
    for(int i=0;i<n;i++)s.insert(v[i]);
    if(s.size()==1){
        cout<<n<<endl;
        return 0;
    }
    if(s.size()==2){
        doistipo=1;
    }
    //cout<<"vai fuder"<<endl;
    ways();
    //cout<<"fudeu"<<endl;
    int resp=0;
    int num=1;
    for(int i=0;i<n;i++){
        if(i==n-1 || v[i]!=v[i+1]){
            for(int j=1;j<=num;j++){
                //cout<<v[i]<<" "<<j<<endl;
                //cout<<"choose eh "<<num<<" "<<j<<endl;
                //cout<<"da "<<memo[j][j*v[i]]<<" era pra dar "<<choose(num,j)<<endl;
                if(memo[j][j*v[i]]!=choose(num,j))break;
                else{
                    resp=max(resp,j);
                    if(doistipo && j==num)resp=n;
                }
            }
            num=1;
        }
        else num++;
    }
    cout<<resp<<endl;
}