
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define MAXN 1123456
#define INF INT_MAX
#define int long long
#define double long double
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define eps 1e-11
#define pi acos(-1)
#define MOD 1000000007

const int n=100;

struct matrix{
    int m[n][n];
    //assumes same size
    matrix mult(matrix b){
        matrix aux;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                aux.m[i][j]=0;
                for(int k=0;k<n;k++){
                    aux.m[i][j]+=m[k][j]*b.m[i][k]%MOD;
                    aux.m[i][j]%=MOD;
                }
            }
        }
        return aux;
    }
    int res(){
        int resp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                resp+=m[i][j];
            }
        }
        return resp%MOD;
    }
    //does not work for i==0
    matrix exp(int i){
        if(i==1)return *this;
        if(i%2==0)return (this->mult(*this)).exp(i/2);
        return this->mult(this->mult(*this).exp(i/2));
    }
};

int count(int a,int b){
    int c=a^b;
    int resp=0;
    while(c!=0){
        resp+=(c%2);
        c/=2;
    }
    return resp;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int num,k;
    cin>>num>>k;
    vector<int> v;
    for(int i=0;i<num;i++){
        int x;cin>>x;v.pb(x);
    }
    matrix ma;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(count(v[i],v[j])%3==0)ma.m[i][j]=1;
            else ma.m[i][j]=0;  
        }
    }

    if(k==1){
        cout<<num<<endl;
        return 0;
    }
    cout<<(ma.exp(k-1)).res()<<endl;

    return 0;
 
}