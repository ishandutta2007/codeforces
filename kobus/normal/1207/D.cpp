#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define f first
#define s second
#define pb push_back
#define MAXN 212345
#define pii pair<int,int>
#define pdd pair<double,double>
#define one 1
#define int long long
#define mp make_pair
#define ld long double
#define MOD 998244353 

int fat(int i){
    int ans=1;
    for(int j=2;j<=i;j++){ans*=j;ans%=MOD;}
    return ans;
}


bool check(vector<pii> v){
    for(int i=1;i<v.size();i++){
        if(v[i-1].s>v[i].s)return 0;
    }
    return 1;
}

int32_t main(){

    int n;
    cin>>n;

    vector<int> v1;
    vector<int> v2;
    vector<pii> v3;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v1.pb(a);
        v2.pb(b);
        v3.pb({a,b});
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    //cout<<"A"<<endl;
    sort(v3.begin(),v3.end());
    //cout<<"B"<<endl;

    int equals1=1;
    int number1=1;
    for(int i=1;i<=n;i++){
        if(i!=n && v1[i]==v1[i-1])equals1++;
        else{
            number1*=fat(equals1);
            number1%=MOD;
            equals1=1;
        }
    }

    int equals2=1;
    int number2=1;
    for(int i=1;i<=n;i++){
        if(i!=n && v2[i]==v2[i-1])equals2++;
        else{
            //cout<<equals2<<" ";
            number2*=fat(equals2);
            number2%=MOD;
            equals2=1;
        }
    }
    //cout<<"A"<<endl;

    int equals3=1;
    int number3=1;
    if(!check(v3))number3=0;
    else{
        for(int i=1;i<=n;i++){
            if(i!=n && v3[i]==v3[i-1])equals3++;
            else{
                number3*=fat(equals3);
                number3%=MOD;
                equals3=1;
            }
        }
    }

    //cout<<fat(n)<<" "<<number1<<" "<<number2<<" "<<number3<<endl;

    cout<<((((fat(n)-number1-number2+number3)%MOD)+MOD)%MOD)<<endl;


    return 0;
}